#include "gl_vertex_buffer.hpp"

#include <glad/gl.h>

GLVertexBuffer::GLVertexBuffer(const u32 size)
{
    glCreateBuffers(1, &m_id);
    glBindBuffer(GL_ARRAY_BUFFER, m_id);

    glBufferData(GL_ARRAY_BUFFER, size, nullptr, GL_DYNAMIC_DRAW);
}

GLVertexBuffer::GLVertexBuffer(const f32 *vertices, const u32 size)
{
    glCreateBuffers(1, &m_id);
    glBindBuffer(GL_ARRAY_BUFFER, m_id);

    glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);
}

Ref<GLVertexBuffer> GLVertexBuffer::create(u32 size)
{
    return CreateRef<GLVertexBuffer>(size);
}

Ref<GLVertexBuffer> GLVertexBuffer::create(f32 *vertices, u32 size)
{
    return CreateRef<GLVertexBuffer>(vertices, size);
}

void GLVertexBuffer::set_data(const void *data, u32 size, u32 offset)
{
    glBufferSubData(GL_ARRAY_BUFFER, offset, size, data);
}

void GLVertexBuffer::set_layout(const BufferLayout &layout)
{
    m_layout = layout;
}

const BufferLayout & GLVertexBuffer::get_layout() const
{
    return m_layout;;
}

void GLVertexBuffer::bind() const
{
    glBindBuffer(GL_ARRAY_BUFFER, m_id);
}

void GLVertexBuffer::unbind()
{
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void GLVertexBuffer::destroy()
{
    if (m_id)
        glDeleteBuffers(1, &m_id);
}
