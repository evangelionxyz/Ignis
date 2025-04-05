#include "gl_buffer.hpp"

#include <vector>

IGNIS_API u32 get_shader_data_type_size(ShaderDataType type)
{
    switch (type) {
        case ShaderDataType_Float: return 4;
        case ShaderDataType_Float2: return 4 * 2;
        case ShaderDataType_Float3: return 4 * 3;
        case ShaderDataType_Float4: return 4 * 4;
        case ShaderDataType_Mat2: return 4 * 2 * 2;
        case ShaderDataType_Mat3: return 4 * 3 * 3;
        case ShaderDataType_Mat4: return 4 * 4 * 4;
        case ShaderDataType_Int: return 4;
        case ShaderDataType_Int2: return 4 * 2;
        case ShaderDataType_Int3: return 4 * 3;
        case ShaderDataType_Int4: return 4 * 4;
        case ShaderDataType_Bool: return 1;
        case ShaderDataType_Unknown:
        default: return 0;
    }
}

IGNIS_API GLenum get_gl_shader_data_type(ShaderDataType type)
{
    switch (type)
    {
        case ShaderDataType_Float:  return GL_FLOAT;
        case ShaderDataType_Float2: return GL_FLOAT;
        case ShaderDataType_Float3: return GL_FLOAT;
        case ShaderDataType_Float4: return GL_FLOAT;
        case ShaderDataType_Mat2:   return GL_FLOAT;
        case ShaderDataType_Mat3:   return GL_FLOAT;
        case ShaderDataType_Mat4:   return GL_FLOAT;
        case ShaderDataType_Int:    return GL_INT;
        case ShaderDataType_Int2:   return GL_INT;
        case ShaderDataType_Int3:   return GL_INT;
        case ShaderDataType_Int4:   return GL_INT;
        case ShaderDataType_Bool:   return GL_BOOL;
    }

    LOG_ASSERT(false, "Unknown Shader Data Type");
    return 0;
}

class BufferLayout::Impl
{
public:
    u32 stride = 0;
    std::vector<BufferElement> elements;

    BufferLayout::Impl(std::vector<BufferElement> elm)
        : elements(elm)
    {
    }
};

BufferLayout::BufferLayout(std::initializer_list<BufferElement> elements)
    : m_impl(new BufferLayout::Impl(elements))
{
    calculate_offset_and_stride();
}

BufferLayout::BufferLayout(const BufferLayout &other)
    : m_impl(new BufferLayout::Impl(other.m_impl->elements))
{
    calculate_offset_and_stride();
}

void BufferLayout::destroy()
{
    if (m_impl)
    {
        delete m_impl;
        m_impl = nullptr;
    }
}

void BufferLayout::calculate_offset_and_stride()
{
    u32 offset = 0;
    m_impl->stride  = 0;
    for (auto& element : m_impl->elements) {
        element.offset = offset;
        offset += element.size;
        m_impl->stride += element.size;
    }
}

u32 BufferLayout::get_stride() const 
{ 
    return m_impl->stride;
}

const std::vector<BufferElement>& BufferLayout::get_elements() const 
{ 
    return m_impl->elements;
}

std::vector<BufferElement>::iterator BufferLayout::begin() 
{ 
    return m_impl->elements.begin(); 
}

std::vector<BufferElement>::iterator BufferLayout::end() 
{
    return m_impl->elements.end(); 
}
