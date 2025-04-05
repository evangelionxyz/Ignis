#include "renderer.hpp"

#include <glad/glad.h>

#include "core/logger.hpp"

RendererAPI Renderer::m_api;
static Ref<Texture> s_white_texture;
static Ref<Texture> s_black_texture;

void Renderer::create(const RendererAPI api)
{
    m_api = api;
}

void Renderer::init()
{
    glEnable(GL_DEPTH_TEST);

    u32 white_texture_data = 0xffffffff;
    u32 black_texture_data = 0xff000000;

    TextureSpec texture_spec;
    texture_spec.width = 1;
    texture_spec.height = 1;
    texture_spec.format = TEXTURE_FORMAT_RGBA;

    s_white_texture = Texture::create(texture_spec, Buffer(&white_texture_data, sizeof(white_texture_data)));
    s_black_texture = Texture::create(texture_spec, Buffer(&black_texture_data, sizeof(black_texture_data)));

    GL_CHECK();
}

void Renderer::shutdown()
{
    if (s_white_texture) s_white_texture->destroy();
    if (s_black_texture) s_black_texture->destroy();
}

RendererAPI Renderer::get_api()
{
    LOG_ASSERT(m_api != RendererAPI::UNKNOWN, "[Renderer] RendererAPI must be set");
    return m_api;
}

Ref<Texture> Renderer::get_white_texture()
{
    return s_white_texture;
}

Ref<Texture> Renderer::get_black_texture()
{
    return s_black_texture;
}

