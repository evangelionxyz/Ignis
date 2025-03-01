#include "gl_vertex_array.hpp"

#include <glad/gl.h>



GLVertexArray::GLVertexArray()
{
    glCreateVertexArrays(1, &m_id);
    glBindVertexArray(m_id);
}

void GLVertexArray::bind() const
{
    glBindVertexArray(m_id);
}

void GLVertexArray::unbind()
{
    glBindVertexArray(0);
}

void GLVertexArray::add_vertex_buffer(const Ref<GLVertexBuffer> &buffer)
{
    glBindVertexArray(m_id);
    buffer->bind();

    auto layout = buffer->get_layout();
    for (const auto &element : layout) {
        switch (element.type) {
            case ShaderDataType_Float:
            case ShaderDataType_Float2:
            case ShaderDataType_Float3:
            case ShaderDataType_Float4: {
                glEnableVertexAttribArray(m_buffer_index);
                glVertexAttribPointer(m_buffer_index,
                    element.get_component_count(),
                    get_gl_shader_data_type(element.type),
                    element.normalized ? GL_TRUE : GL_FALSE,
                    layout.get_stride(),
                    reinterpret_cast<const void *>(static_cast<const uintptr_t>(element.offset)));

                m_buffer_index++;
                break;
            }
            case ShaderDataType_Int:
            case ShaderDataType_Int2:
            case ShaderDataType_Int3:
            case ShaderDataType_Int4:
            case ShaderDataType_Bool:{
                glEnableVertexAttribArray(m_buffer_index);
                glVertexAttribIPointer(m_buffer_index,
                    element.get_component_count(),
                    get_gl_shader_data_type(element.type),
                    layout.get_stride(),
                    reinterpret_cast<const void *>(static_cast<const uintptr_t>(element.offset)));

                m_buffer_index++;
                break;
            }
            case ShaderDataType_Mat2:
            case ShaderDataType_Mat3:
            case ShaderDataType_Mat4: {
                const u8 count = element.get_component_count();
                for (u8 i = 0; i < count; i++) {
                    glEnableVertexAttribArray(m_buffer_index);
                    glVertexAttribPointer(m_buffer_index,
                        count,
                        get_gl_shader_data_type(element.type),
                        element.normalized ? GL_TRUE : GL_FALSE,
                        layout.get_stride(),
                        reinterpret_cast<const void *>(static_cast<const uintptr_t>(element.offset + sizeof(f32) * count * i)));
                    glVertexAttribDivisor(m_buffer_index, 1);
                    m_buffer_index++;
                }
                break;
            }
            case ShaderDataType_Unknown:
            default:
                LOG_ERROR("[VertexArray] Unknown shader data type");
                return;
        }
    }
    m_buffers.push_back(buffer);
}

void GLVertexArray::set_index_buffer(const Ref<GLIndexBuffer> &buffer)
{
    glBindVertexArray(m_id);
    buffer->bind();
    m_index_buffer = buffer;
}

Ref<GLIndexBuffer> GLVertexArray::get_index_buffer() const
{
    return m_index_buffer;
}

Ref<GLVertexArray> GLVertexArray::create()
{
    return CreateRef<GLVertexArray>();
}

void GLVertexArray::destroy()
{
    glDeleteVertexArrays(1, &m_id);
    glBindVertexArray(0);

    m_index_buffer->destroy();
}
