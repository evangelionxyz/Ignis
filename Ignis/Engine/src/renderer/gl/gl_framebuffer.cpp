#include "gl_framebuffer.hpp"

#include <core/logger.hpp>
#include <glad/gl.h>

GLFramebuffer::GLFramebuffer(const FramebufferSpec &spec)
    : m_spec(spec)
{
    invalidate();
}

void GLFramebuffer::invalidate() {
    if (m_id) {
        glDeleteFramebuffers(1, &m_id);
        glDeleteTextures(m_color_attachments.size(), m_color_attachments.data());
        m_color_attachments.clear();
    }

    glCreateFramebuffers(1, &m_id);
    glBindFramebuffer(GL_FRAMEBUFFER, m_id);

    // TODO: only one color attachment
    u32 texture_id;
    glCreateTextures(GL_TEXTURE_2D, 1, &texture_id);
    glBindTexture(GL_TEXTURE_2D, texture_id);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB8, m_spec.width, m_spec.height, 0, GL_RGB, GL_UNSIGNED_BYTE, nullptr);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glFramebufferTexture(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, texture_id, 0);

    m_color_attachments.push_back(texture_id);

    glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

void GLFramebuffer::resize(u32 width, u32 height) {
    if (width == 0 || height == 0) {
        LOG_ERROR("[Framebuffer] invalid size {0} {1}", width, height);
        return;
    }

    m_spec.width = static_cast<i32>(width);
    m_spec.height = static_cast<i32>(height);

    invalidate();
}

i32 GLFramebuffer::read_pixel(u32 attachment_index, i32 x, i32 y) const {
    if (attachment_index >= m_color_attachments.size()) {
        i32 pixel_data;
        glReadBuffer(GL_COLOR_ATTACHMENT0 + attachment_index);
        glReadPixels(x, y, 1, 1, GL_RGB, GL_UNSIGNED_BYTE, &pixel_data);
        return pixel_data;
    }
    return -1;
}

void GLFramebuffer::destroy() {
    if (m_id != 0) {
        glDeleteFramebuffers(1, &m_id);
        LOG_TRACE("[Framebuffer] {} destroyed ", m_id);
    }
}

void GLFramebuffer::bind() const {
    glBindFramebuffer(GL_FRAMEBUFFER, m_id);
    glViewport(0, 0, m_spec.width, m_spec.height);
}

void GLFramebuffer::unbind() {
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

const u32 GLFramebuffer::get_id() const {
    return m_id;
}

const FramebufferSpec & GLFramebuffer::get_spec() const {
    return m_spec;
}

i32 GLFramebuffer::get_width() const {
    return m_spec.width;
}

i32 GLFramebuffer::get_height() const {
    return m_spec.height;
}
