#pragma once

#include <core/object.hpp>
#include <glad/glad.h>

#include "gl_wrapper.hpp"

enum ShaderDataType
{
    ShaderDataType_Unknown = 0,
    ShaderDataType_Float,
    ShaderDataType_Float2,
    ShaderDataType_Float3,
    ShaderDataType_Float4,
    ShaderDataType_Mat2,
    ShaderDataType_Mat3,
    ShaderDataType_Mat4,
    ShaderDataType_Int,
    ShaderDataType_Int2,
    ShaderDataType_Int3,
    ShaderDataType_Int4,
    ShaderDataType_Bool
};

static u32 get_shader_data_type_size(ShaderDataType type)
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

static GLenum get_gl_shader_data_type(ShaderDataType type)
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

struct BufferElement
{
    std::string name;
    ShaderDataType type = ShaderDataType_Unknown;
    u32 size, offset;
    bool normalized = false;

    BufferElement() = default;

    BufferElement(ShaderDataType type, const std::string &name, const bool normalized = false)
        : name(name), type(type), size(get_shader_data_type_size(type)), offset(0), normalized(normalized)
    {
    }

    u8 get_component_count() const
    {
        switch (type) {
            case ShaderDataType_Float:  return 1;
            case ShaderDataType_Float2: return 2;
            case ShaderDataType_Float3: return 3;
            case ShaderDataType_Float4: return 4;
            case ShaderDataType_Mat2:   return 2;
            case ShaderDataType_Mat3:   return 3;
            case ShaderDataType_Mat4:   return 4;
            case ShaderDataType_Int:    return 1;
            case ShaderDataType_Int2:   return 2;
            case ShaderDataType_Int3:   return 3;
            case ShaderDataType_Int4:   return 4;
            case ShaderDataType_Bool:   return 1;
        }

        LOG_ASSERT(false, "[BufferElement] Unknown shader data type");
        return 0;
    }
};

class BufferLayout
{
public:
    BufferLayout() = default;

    BufferLayout(std::initializer_list<BufferElement> elements)
        : m_elements(elements)
    {
        calculate_offset_and_stride();
    }

    u32 get_stride() const { return m_stride; }
    const std::vector<BufferElement>& get_elements() const { return m_elements; }

    std::vector<BufferElement>::iterator begin() { return m_elements.begin(); }
    std::vector<BufferElement>::iterator end() { return m_elements.end(); }
private:
    void calculate_offset_and_stride()
    {
        u32 offset = 0;
        m_stride = 0;
        for (auto& element : m_elements) {
            element.offset = offset;
            offset += element.size;
            m_stride += element.size;
        }
    }
    std::vector<BufferElement> m_elements;
    u32 m_stride = 0;
};

class GLBuffer : public Object {
public:
    u32 get_id() {return m_id;}

protected:
    u32 m_id = 0;
};
