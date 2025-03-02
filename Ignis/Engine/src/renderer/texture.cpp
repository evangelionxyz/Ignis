#include "texture.hpp"
#include "renderer.hpp"
#include "gl/gl_texture.hpp"

Ref<Texture> Texture::create(const TextureSpec &spec, const Buffer &buffer)
{
    switch (Renderer::get_api()) {
        case RendererAPI::OPENGL: return CreateRef<GLTexture>(spec, buffer);
        case RendererAPI::VULKAN: return nullptr;
        default: return nullptr;
    }
}

Ref<Texture> Texture::create(const std::string &filepath)
{
    switch (Renderer::get_api()) {
        case RendererAPI::OPENGL: return CreateRef<GLTexture>(filepath);
        case RendererAPI::VULKAN: return nullptr;
        default: return nullptr;
    }
}