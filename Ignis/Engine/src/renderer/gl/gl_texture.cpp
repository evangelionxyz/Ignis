#include "stbi_image.h"
#include "gl_texture.hpp"

#include "core/buffer.hpp"

GLTexture::GLTexture(const TextureSpec &spec, const Buffer &buffer)
    : m_spec(spec)
{
    if (m_spec.width == 0 || m_spec.height == 0) {
        LOG_ERROR("[GLTexture] Invalid texture dimensions!");
        return;
    }

    glCreateTextures(GL_TEXTURE_2D, 1, &m_id);
    glBindTexture(GL_TEXTURE_2D, m_id);

    const GLint internal_format = get_gl_texture_internal_format(m_spec.format);
    const GLenum filter = get_gl_texture_filter(m_spec.filter);

    glTextureStorage2D(m_id, 1, internal_format, m_spec.width, m_spec.height);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, filter);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, filter);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

    if (buffer) {
        GLTexture::set_data(buffer);
    }

    glBindTexture(GL_TEXTURE_2D, 0);
}

GLTexture::GLTexture(const std::string &filepath)
{
    LOG_ASSERT(std::filesystem::exists(filepath), "[Texture] File does not exists");

    const stbi_uc *pixel = stbi_load(filepath.c_str(), &m_spec.width, &m_spec.height, &m_spec.channels, 0);
    LOG_ASSERT(pixel, "[Texture] Failed to load texture");

    switch (m_spec.channels) {
        case 3: m_spec.format = TEXTURE_FORMAT_RGB; break;
        case 4: m_spec.format = TEXTURE_FORMAT_RGBA; break;
    }

    const GLenum format = get_gl_texture_format(m_spec.format);
    const GLint internal_format = get_gl_texture_internal_format(m_spec.format);
    const GLenum filter = get_gl_texture_filter(m_spec.filter);

    glCreateTextures(GL_TEXTURE_2D, 1, &m_id);
    glBindTexture(GL_TEXTURE_2D, m_id);

    glTexImage2D(GL_TEXTURE_2D, 0, internal_format, m_spec.width, m_spec.height, 0, format, GL_UNSIGNED_BYTE, pixel);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, filter);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, filter);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

    glBindTexture(GL_TEXTURE_2D, 0);
}

void GLTexture::bind(const i32 index)
{
    m_index = index;
    glActiveTexture(GL_TEXTURE0 + index);
    glBindTextureUnit(index, m_id);
}

void GLTexture::set_data(const Buffer &buffer)
{
    glBindTexture(GL_TEXTURE_2D, m_id);

    // Correct buffer size check
    m_spec.channels = m_spec.format == TEXTURE_FORMAT_RGBA8 ? 4 : 3;
    size_t expected_size = m_spec.width * m_spec.height * m_spec.channels;
    LOG_ASSERT(buffer.size == expected_size, "[Texture] Data must be entire texture! Expected %zu, got %zu", expected_size, buffer.size);
    const GLenum format = get_gl_texture_format(m_spec.format);
    glTextureSubImage2D(m_id, 0, 0, 0, m_spec.width, m_spec.height, format, GL_UNSIGNED_BYTE, buffer.data);
}

void GLTexture::unbind(i32 index)
{
    glBindTexture(GL_TEXTURE_2D, 0);
}

void GLTexture::destroy()
{
    if (m_id)
        glDeleteTextures(1, &m_id);
}

u32 GLTexture::get_id() const
{
    return m_id;
}

i32 GLTexture::get_index() const
{
    return m_index;
}
