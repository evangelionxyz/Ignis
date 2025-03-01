#pragma once
#include "gl_buffer.hpp"
#include "gl_index_buffer.hpp"
#include "gl_vertex_buffer.hpp"

class GLVertexArray final : public GLBuffer {
public:
    GLVertexArray();

    void bind() const;
    static void unbind();

    void add_vertex_buffer(const Ref<GLVertexBuffer> &buffer);
    void set_index_buffer(const Ref<GLIndexBuffer> &buffer);

    Ref<GLIndexBuffer> get_index_buffer() const;
    static Ref<GLVertexArray> create();
    void destroy() override;
private:
    std::vector<Ref<GLVertexBuffer>> m_buffers;
    Ref<GLIndexBuffer> m_index_buffer;
    u32 m_buffer_index = 0;
};

