#include "gl_vertex_array.hpp"

#include <glad/glad.h>

class GLVertexArray::Impl
{
public:
    std::vector<Ref<GLVertexBuffer>> buffers;
    Ref<GLIndexBuffer> index_buffer;
    u32 buffer_index = 0;

    Impl()
    {
    }
};

GLVertexArray::GLVertexArray() 
    : m_impl(new GLVertexArray::Impl())
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

    GL_CHECK();

    auto layout = buffer->get_layout();
    for (const auto &element : layout) {
        switch (element.type) {
            case ShaderDataType_Float:
            case ShaderDataType_Float2:
            case ShaderDataType_Float3:
            case ShaderDataType_Float4: {
                glEnableVertexAttribArray(m_impl->buffer_index);
                glVertexAttribPointer(m_impl->buffer_index,
                    element.get_component_count(),
                    get_gl_shader_data_type(element.type),
                    element.normalized ? GL_TRUE : GL_FALSE,
                    layout.get_stride(),
                    reinterpret_cast<const void *>(static_cast<const uintptr_t>(element.offset)));

                m_impl->buffer_index++;
                break;
            }
            case ShaderDataType_Int:
            case ShaderDataType_Int2:
            case ShaderDataType_Int3:
            case ShaderDataType_Int4:
            case ShaderDataType_Bool:{
                glEnableVertexAttribArray(m_impl->buffer_index);
                glVertexAttribIPointer(m_impl->buffer_index,
                    element.get_component_count(),
                    get_gl_shader_data_type(element.type),
                    layout.get_stride(),
                    reinterpret_cast<const void *>(static_cast<const uintptr_t>(element.offset)));

                m_impl->buffer_index++;
                break;
            }
            case ShaderDataType_Mat2:
            case ShaderDataType_Mat3:
            case ShaderDataType_Mat4: {
                const u8 count = element.get_component_count();
                for (u8 i = 0; i < count; i++) {
                    glEnableVertexAttribArray(m_impl->buffer_index);
                    glVertexAttribPointer(m_impl->buffer_index,
                        count,
                        get_gl_shader_data_type(element.type),
                        element.normalized ? GL_TRUE : GL_FALSE,
                        layout.get_stride(),
                        reinterpret_cast<const void *>(static_cast<const uintptr_t>(element.offset + sizeof(f32) * count * i)));
                    glVertexAttribDivisor(m_impl->buffer_index, 1);
                    m_impl->buffer_index++;
                }
                break;
            }
            case ShaderDataType_Unknown:
            default:
                LOG_ERROR("[VertexArray] Unknown shader data type");
                return;
        }
    }
    m_impl->buffers.push_back(buffer);
}

void GLVertexArray::set_index_buffer(const Ref<GLIndexBuffer> &buffer)
{
    GL_CHECK();

    glBindVertexArray(m_id);
    buffer->bind();
    m_impl->index_buffer = buffer;
}

Ref<GLIndexBuffer> GLVertexArray::get_index_buffer() const
{
    return m_impl->index_buffer;
}

Ref<GLVertexArray> GLVertexArray::create()
{
    return CreateRef<GLVertexArray>();
}

void GLVertexArray::destroy()
{
    glDeleteVertexArrays(1, &m_id);
    glBindVertexArray(0);

    m_impl->index_buffer->destroy();

    if (m_impl)
        delete m_impl;
}
