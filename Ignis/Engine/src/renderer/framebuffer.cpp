#include "framebuffer.hpp"

#include "renderer.hpp"
#include "gl/gl_framebuffer.hpp"

struct FramebufferAttachmentSpec::Impl
{
    std::vector<FramebufferTextureSpec> texture_attachments;
    FramebufferAttachmentSpec::Impl(const std::vector<FramebufferTextureSpec> &attachments)
        : texture_attachments(attachments)
    {
    }
};

FramebufferAttachmentSpec::FramebufferAttachmentSpec(const std::initializer_list<FramebufferTextureSpec> attachments)
    : m_impl(new FramebufferAttachmentSpec::Impl(attachments))
{
}

void FramebufferAttachmentSpec::destroy()
{
    if (m_impl)
    {
        delete m_impl;
        m_impl = nullptr;
    }
}
std::vector<FramebufferTextureSpec> &FramebufferAttachmentSpec::get_attachments()
{
    return m_impl->texture_attachments;
}

Ref<Framebuffer> Framebuffer::create(const FramebufferSpec& spec)
{
    switch (Renderer::get_api()) {
        case RendererAPI::OPENGL: return CreateRef<GLFramebuffer>(spec);
        case RendererAPI::VULKAN: return nullptr;
        default: return nullptr;
    }
}

