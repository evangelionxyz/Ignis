#pragma once
#include "texture.hpp"

struct FramebufferTextureSpec
{
    FramebufferTextureSpec() = default;
    explicit FramebufferTextureSpec(const TextureFormat format)
        : format(format)
    {
    }
    TextureFormat format;
};

struct FramebufferAttachmentSpec
{
    FramebufferAttachmentSpec() = default;
    FramebufferAttachmentSpec(const std::initializer_list<FramebufferTextureSpec> attachments)
        : texture_attachments(attachments)
    {
    }

    std::vector<FramebufferTextureSpec> texture_attachments;
};

struct FramebufferSpec
{
    FramebufferAttachmentSpec attachments;
    i32 width = 0, height = 0, samples = 1;
    i32 depth_array_count = 0;
    bool read_buffer = false;
};

class Framebuffer : public Object
{
public:
    virtual void resize(u32 width, u32 height) = 0;
    virtual i32 read_pixel(u32 attachment_index, i32 x, i32 y) const = 0;
    virtual void bind() const = 0;
    virtual const u32 get_id() const = 0;
    virtual i32 get_width() const { return m_spec.width; }
    virtual i32 get_height() const { return m_spec.height; }
    virtual const FramebufferSpec &get_spec() const {return m_spec;}

    static Ref<Framebuffer> create(const FramebufferSpec& spec);

protected:
    FramebufferSpec m_spec;
};