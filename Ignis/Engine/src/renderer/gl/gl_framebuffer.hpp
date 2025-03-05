#pragma once
#include <core/object.hpp>
#include <vector>

#include "renderer/framebuffer.hpp"

class GLFramebuffer : public Framebuffer {
public:
    GLFramebuffer() = default;
    GLFramebuffer(const FramebufferSpec &spec);

    void resize(u32 width, u32 height) override;
    i32 read_pixel(u32 attachment_index, i32 x, i32 y) const override;
    void destroy() override;
    void bind() const override;
    static void unbind();
    const u32 get_id() const override;

private:
    void invalidate();

    u32 m_id = 0;
    u32 m_depth_attachment = 0;
    u32 m_color_attachment_index = 0;

    std::vector<FramebufferTextureSpec> m_color_attachment_specs;
    FramebufferTextureSpec m_depth_attachment_spec{};

    std::vector<u32> m_color_attachments;
    FramebufferSpec m_spec;
};

