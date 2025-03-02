#include "framebuffer.hpp"

#include "renderer.hpp"
#include "gl/gl_framebuffer.hpp"

Ref<Framebuffer> Framebuffer::create(const FramebufferSpec& spec)
{
    switch (Renderer::get_api()) {
        case RendererAPI::OPENGL: return CreateRef<GLFramebuffer>(spec);
        case RendererAPI::VULKAN: return nullptr;
        default: return nullptr;
    }
}

