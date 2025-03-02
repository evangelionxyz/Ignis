#include "gl_framebuffer.hpp"

#include <core/logger.hpp>
#include <glad/gl.h>
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

GLFramebuffer::GLFramebuffer(const FramebufferSpec &spec)
    : m_spec(spec)
{
    LOG_ASSERT(m_spec.width > 0 && m_spec.height > 0, "[Framebuffer] invalid size");

    for (auto attachment : m_spec.attachments.texture_attachments) {
        is_depth_format(attachment.format)
        ? m_depth_attachment_spec = attachment
        : m_color_attachment_specs.emplace_back(attachment);
    }

    invalidate();
}

void GLFramebuffer::invalidate()
{
    if (m_id) {
        destroy();
    }

    glCreateFramebuffers(1, &m_id);
    glBindFramebuffer(GL_FRAMEBUFFER, m_id);

    const bool multisample = m_spec.samples > 1;

    // process color attachments
    if (!m_color_attachment_specs.empty()) {

        // create textures
        m_color_attachments.resize(m_color_attachment_specs.size());
        glCreateTextures(texture_2d_target(multisample), m_color_attachments.size(), m_color_attachments.data());
        for (size_t i = 0; i < m_color_attachments.size(); i++) {
            glBindTexture(texture_2d_target(multisample), m_color_attachments[i]);
            const GLenum format = get_gl_texture_format(m_color_attachment_specs[i].format);
            const i32 internal_format =  get_gl_texture_internal_format(m_color_attachment_specs[i].format);
            attach_color_texture_2d(m_color_attachments[i], internal_format, format, m_spec, i);
        }
    }

    // process depth attachment
    if (m_depth_attachment_spec.format != TEXTURE_FORMAT_UNKNOWN) {
        // create the texture
        glCreateTextures(texture_2d_target(multisample), 1, &m_depth_attachment);
        glBindTexture(texture_2d_target(multisample), m_depth_attachment);
        const GLenum format = get_gl_texture_format(m_depth_attachment_spec.format);
        const GLenum attachment_type = get_gl_attachment_type(m_depth_attachment_spec.format);
        attach_depth_texture_2d(m_depth_attachment, format, attachment_type, m_spec);
    }

   if (!m_color_attachments.empty()) {
       const GLenum buffers[4] = { GL_COLOR_ATTACHMENT0, GL_COLOR_ATTACHMENT1, GL_COLOR_ATTACHMENT2, GL_COLOR_ATTACHMENT3 };
       glDrawBuffers(4, buffers);
   }

    if(m_color_attachments.empty())
        glDrawBuffer(GL_NONE);
    if (m_spec.read_buffer == false)
        glReadBuffer(GL_NONE);

    glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

void GLFramebuffer::resize(u32 width, u32 height)
{
    if (width == 0 || height == 0) {
        LOG_ERROR("[Framebuffer] invalid size {0} {1}", width, height);
        return;
    }
    m_spec.width = static_cast<i32>(width);
    m_spec.height = static_cast<i32>(height);
    invalidate();
}

i32 GLFramebuffer::read_pixel(const u32 attachment_index, const i32 x, const i32 y) const
{
    if (attachment_index >= m_color_attachments.size()) {
        i32 pixel_data;
        glReadBuffer(GL_COLOR_ATTACHMENT0 + attachment_index);
        glReadPixels(x, y, 1, 1, GL_RGB, GL_UNSIGNED_BYTE, &pixel_data);
        return pixel_data;
    }
    return -1;
}

void GLFramebuffer::destroy()
{
    if (m_id != 0) {
        glDeleteFramebuffers(1, &m_id);
        LOG_TRACE("[Framebuffer] {} destroyed ", m_id);
    }
    glDeleteTextures(m_color_attachments.size(), m_color_attachments.data());
    if (m_depth_attachment != 0) {
        glDeleteTextures(1, &m_depth_attachment);
        m_depth_attachment = 0;
    }
    m_color_attachments.clear();
}

void GLFramebuffer::bind() const
{
    glBindFramebuffer(GL_FRAMEBUFFER, m_id);
    glViewport(0, 0, m_spec.width, m_spec.height);
}

void GLFramebuffer::unbind()
{
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

const u32 GLFramebuffer::get_id() const
{
    return m_id;
}