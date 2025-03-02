#pragma once
#include "gl_buffer.hpp"
#include "renderer/texture.hpp"
#include "core/buffer.hpp"

#include <string>
#include <filesystem>

static GLenum get_gl_texture_format(const TextureFormat format)
{
    switch (format) {
        case TEXTURE_FORMAT_RGB:
            return GL_RGB;
        case TEXTURE_FORMAT_RGBA:
        case TEXTURE_FORMAT_RGBA8:
        case TEXTURE_FORMAT_RGBA16F:
            return GL_RGBA;
        case TEXTURE_FORMAT_DEPTH:
            return GL_DEPTH_COMPONENT;
        case TEXTURE_FORMAT_DEPTH24STENCIL8:
            return GL_DEPTH24_STENCIL8;
        case TEXTURE_FORMAT_RED_INTEGER:
            return GL_RED_INTEGER;
    }
    return GL_NONE;
}

static GLenum get_gl_attachment_type(const TextureFormat format)
{
    switch (format) {
        case TEXTURE_FORMAT_DEPTH24STENCIL8: return GL_DEPTH_STENCIL_ATTACHMENT;
        case TEXTURE_FORMAT_DEPTH: return GL_DEPTH_ATTACHMENT;
    }
    return GL_NONE;
}

static i32 get_gl_texture_internal_format(const TextureFormat format)
{
    switch (format) {
        case TEXTURE_FORMAT_RGB: return GL_RGB8;
        case TEXTURE_FORMAT_RGBA: return GL_RGBA8;
        case TEXTURE_FORMAT_RGBA8: return GL_RGBA8;
        case TEXTURE_FORMAT_RGBA16F: return GL_RGBA16F;
        case TEXTURE_FORMAT_DEPTH: return GL_DEPTH_COMPONENT;
        case TEXTURE_FORMAT_DEPTH24STENCIL8:return GL_DEPTH24_STENCIL8;
        case TEXTURE_FORMAT_RED_INTEGER:return GL_R32I;
    }
    return GL_NONE;
}

static GLenum get_gl_texture_filter(const TextureFilter filter)
{
    switch (filter) {
        case TEXTURE_FILTER_NEAREST: return GL_NEAREST;
        case TEXTURE_FILTER_LINEAR: return GL_LINEAR;
    }
    return GL_NONE;
}

class GLTexture : public Texture {
public:
    GLTexture() = default;
    GLTexture(const TextureSpec &spec, const Buffer buffer);
    GLTexture(const std::string &filepath);

    void set_data(const Buffer buffer) override;
    void bind(i32 index) override;
    void destroy() override;

    u32 get_id() const override;
    i32 get_index() const override;

    static void unbind(i32 index = 0);

private:
    u32 m_id = 0, m_index = 0;
    TextureSpec m_spec;
};
