#pragma once
#include <core/object.hpp>
#include <vector>

#include "renderer/framebuffer.hpp"

class IGNIS_API GLFramebuffer : public Framebuffer {
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
    class Impl;
    Impl *m_impl;
};

