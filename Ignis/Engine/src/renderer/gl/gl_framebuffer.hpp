#ifndef FRAMEBUFFER_HPP
#define FRAMEBUFFER_HPP

#include <core/object.hpp>
#include <vector>

struct FramebufferSpec {
    i32 width, height;
};

class GLFramebuffer : public Object {
public:
    GLFramebuffer() = default;
    GLFramebuffer(const FramebufferSpec &spec);

    void resize(u32 width, u32 height);

    i32 read_pixel(u32 attachment_index, i32 x, i32 y) const;

    void destroy() override;

    void bind() const;

    static void unbind();

    const u32 get_id() const;

    const FramebufferSpec &get_spec() const;
    i32 get_width() const;
    i32 get_height() const;

private:
    void invalidate();

    u32 m_id = 0;
    u32 m_depth_attachment = 0;
    u32 m_color_attachment_index = 0;
    std::vector<u32> m_color_attachments;
    FramebufferSpec m_spec;
};



#endif //FRAMEBUFFER_HPP
