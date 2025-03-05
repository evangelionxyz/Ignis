#include "gl_index_buffer.hpp"

#include <glad/glad.h>

GLIndexBuffer::GLIndexBuffer(u32 size)
{
    glCreateBuffers(1, &m_id);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_id);

    glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, nullptr, GL_DYNAMIC_DRAW);
}

GLIndexBuffer::GLIndexBuffer(const u32 *indices, u32 count)
    : m_count(count)
{
    glCreateBuffers(1, &m_id);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_id);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(u32), indices, GL_STATIC_DRAW);
}

void GLIndexBuffer::bind() const
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_id);
}

void GLIndexBuffer::unbind()
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void GLIndexBuffer::destroy()
{
    if (m_id)
        glDeleteBuffers(1, &m_id);
}

u32 GLIndexBuffer::get_count() const
{
    return m_count;
}

Ref<GLIndexBuffer> GLIndexBuffer::create(u32 size)
{
    return CreateRef<GLIndexBuffer>(size);
}

Ref<GLIndexBuffer> GLIndexBuffer::create(u32 *indices, u32 size)
{
    return CreateRef<GLIndexBuffer>(indices, size);
}


