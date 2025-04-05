#include "gl_framebuffer.hpp"

#include <core/logger.hpp>
#include <glad/glad.h>
#include "gl_texture.hpp"

static constexpr u32 s_max_framebuffer_size = 8192;

static GLenum texture_2d_target(const bool multisample)
{
    return multisample ? GL_TEXTURE_2D_MULTISAMPLE : GL_TEXTURE_2D;
}

static void attach_color_texture_2d(u32 texture_id, const GLenum internal_format, const GLenum format, const FramebufferSpec spec, i32 index)
{
    bool multisample = spec.samples > 1;
    if (multisample) glTexImage2DMultisample(GL_TEXTURE_2D_MULTISAMPLE, spec.samples, internal_format, spec.width, spec.height, GL_FALSE);
    else glTexImage2D(GL_TEXTURE_2D, 0, internal_format, spec.width, spec.height, 0, format, GL_UNSIGNED_BYTE, nullptr);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0 + index, texture_2d_target(multisample), texture_id, 0);
}

static void attach_depth_texture_2d(u32 texture_id, const GLenum format, GLenum attachment_type, const FramebufferSpec spec)
{
    bool multisample = spec.samples > 1;
    if (multisample) glTexImage2DMultisample(GL_TEXTURE_2D_MULTISAMPLE, spec.samples, format, spec.width, spec.height, GL_FALSE);
    else
    {
        if (attachment_type == GL_DEPTH_STENCIL_ATTACHMENT) glTexStorage2D(GL_TEXTURE_2D, 1, format, spec.width, spec.height);
        else if (attachment_type == GL_DEPTH_ATTACHMENT) glTexImage2D(GL_TEXTURE_2D, 0, format, spec.width, spec.height, 0, format, GL_FLOAT, nullptr);
    }

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    constexpr f32 borderColor[] = { 1.0f, 1.0f, 1.0f, 1.0f };
    glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, borderColor);

    glFramebufferTexture2D(GL_FRAMEBUFFER, attachment_type, texture_2d_target(multisample), texture_id, 0);
}

class GLFramebuffer::Impl
{
public:
    u32 id = 0;
    u32 depth_attachment = 0;
    u32 color_attachment_index = 0;

    std::vector<FramebufferTextureSpec> color_attachment_specs;
    FramebufferTextureSpec depth_attachment_spec{};

    std::vector<u32> color_attachments;
    FramebufferSpec spec;

    GLFramebuffer::Impl(const FramebufferSpec &specification)
        : spec(specification)
    {
    }
};

GLFramebuffer::GLFramebuffer(const FramebufferSpec &spec)
    : m_impl(new GLFramebuffer::Impl(spec))
{
    LOG_ASSERT(m_impl->spec.width > 0 && m_impl->spec.height > 0, "[Framebuffer] invalid size");

    for (auto attachment : m_impl->spec.attachments.get_attachments()) {
        is_depth_format(attachment.format)
        ? m_impl->depth_attachment_spec = attachment
        : m_impl->color_attachment_specs.emplace_back(attachment);
    }
    GL_CHECK();


    invalidate();
}

void GLFramebuffer::invalidate()
{
    if (m_impl->id) {
        destroy();
    }

    glCreateFramebuffers(1, &m_impl->id);
    glBindFramebuffer(GL_FRAMEBUFFER, m_impl->id);

    const bool multisample = m_impl->spec.samples > 1;

    // process color attachments
    if (!m_impl->color_attachment_specs.empty()) {

        // create textures
        m_impl->color_attachments.resize(m_impl->color_attachment_specs.size());
        glCreateTextures(texture_2d_target(multisample), m_impl->color_attachments.size(), m_impl->color_attachments.data());
        for (size_t i = 0; i < m_impl->color_attachments.size(); i++) {
            glBindTexture(texture_2d_target(multisample), m_impl->color_attachments[i]);
            const GLenum format = get_gl_texture_format(m_impl->color_attachment_specs[i].format);
            const i32 internal_format =  get_gl_texture_internal_format(m_impl->color_attachment_specs[i].format);
            attach_color_texture_2d(m_impl->color_attachments[i], internal_format, format, m_impl->spec, i);
        }
    }

    // process depth attachment
    if (m_impl->depth_attachment_spec.format != TEXTURE_FORMAT_UNKNOWN) {
        // create the texture
        glCreateTextures(texture_2d_target(multisample), 1, &m_impl->depth_attachment);
        glBindTexture(texture_2d_target(multisample), m_impl->depth_attachment);
        const GLenum format = get_gl_texture_format(m_impl->depth_attachment_spec.format);
        const GLenum attachment_type = get_gl_attachment_type(m_impl->depth_attachment_spec.format);
        attach_depth_texture_2d(m_impl->depth_attachment, format, attachment_type, m_impl->spec);
    }

   if (!m_impl->color_attachments.empty()) {
       constexpr GLenum buffers[4] = { GL_COLOR_ATTACHMENT0, GL_COLOR_ATTACHMENT1, GL_COLOR_ATTACHMENT2, GL_COLOR_ATTACHMENT3 };
       glDrawBuffers(4, buffers);
   }

    if(m_impl->color_attachments.empty())
        glDrawBuffer(GL_NONE);
    if (m_impl->spec.read_buffer == false)
        glReadBuffer(GL_NONE);

    glBindTexture(GL_TEXTURE_2D, 0);
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

void GLFramebuffer::resize(u32 width, u32 height)
{
    if (width == 0 || height == 0) {
        LOG_ERROR("[Framebuffer] invalid size {0} {1}", width, height);
        return;
    }
    m_impl->spec.width = static_cast<i32>(width);
    m_impl->spec.height = static_cast<i32>(height);
    invalidate();
}

i32 GLFramebuffer::read_pixel(const u32 attachment_index, const i32 x, const i32 y) const
{
    if (attachment_index >= m_impl->color_attachments.size()) {
        i32 pixel_data;
        glReadBuffer(GL_COLOR_ATTACHMENT0 + attachment_index);
        glReadPixels(x, y, 1, 1, GL_RGB, GL_UNSIGNED_BYTE, &pixel_data);
        return pixel_data;
    }
    return -1;
}

void GLFramebuffer::destroy()
{
    if (m_impl->id != 0) {
        glDeleteFramebuffers(1, &m_impl->id);
        LOG_TRACE("[Framebuffer] {} destroyed ", m_impl->id);
    }

    glDeleteTextures(m_impl->color_attachments.size(), m_impl->color_attachments.data());
    if (m_impl->depth_attachment != 0) {
        glDeleteTextures(1, &m_impl->depth_attachment);
        m_impl->depth_attachment = 0;
    }

    m_impl->color_attachments.clear();

    GL_CHECK();

    //m_impl->spec.attachments.destroy();
}

void GLFramebuffer::bind() const
{
    GL_CHECK();

    glBindFramebuffer(GL_FRAMEBUFFER, m_impl->id);
    glViewport(0, 0, m_impl->spec.width, m_impl->spec.height);

    GL_CHECK();
}

void GLFramebuffer::unbind()
{
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

const u32 GLFramebuffer::get_id() const
{
    return m_impl->id;
}