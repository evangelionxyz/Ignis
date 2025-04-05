#pragma once
#include "gl_buffer.hpp"

class IGNIS_API GLVertexBuffer : public GLBuffer{
public:
    GLVertexBuffer(u32 size);
    GLVertexBuffer(const f32 *vertices, u32 size);

    void set_data(const void *data, u32 size, u32 offset);

    void set_layout(const BufferLayout &layout);
    const BufferLayout &get_layout() const;
    static Ref<GLVertexBuffer> create(u32 size);
    static Ref<GLVertexBuffer> create(f32 *vertices, u32 size);

    void bind() const;
    static void unbind();

    void destroy() override;

private:
    BufferLayout m_layout;
};
