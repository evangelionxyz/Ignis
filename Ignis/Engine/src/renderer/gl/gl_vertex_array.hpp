#pragma once

#include "core/base.hpp"
#include "gl_buffer.hpp"
#include "gl_index_buffer.hpp"
#include "gl_vertex_buffer.hpp"

class IGNIS_API GLVertexArray : public GLBuffer {
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
    class Impl;
    Impl *m_impl;
};

