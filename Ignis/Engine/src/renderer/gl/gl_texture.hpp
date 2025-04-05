#pragma once
#include "gl_buffer.hpp"
#include "renderer/texture.hpp"
#include "core/buffer.hpp"

#include <string>
#include <filesystem>

extern "C"
{
IGNIS_API GLenum get_gl_texture_format(const TextureFormat format);
IGNIS_API GLenum get_gl_attachment_type(const TextureFormat format);
IGNIS_API i32 get_gl_texture_internal_format(const TextureFormat format);
IGNIS_API GLenum get_gl_texture_filter(const TextureFilter filter);
}


class IGNIS_API GLTexture : public Texture {
public:
    GLTexture() = default;
    GLTexture(const TextureSpec &spec, const Buffer buffer);
    GLTexture(const char *filepath);

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
