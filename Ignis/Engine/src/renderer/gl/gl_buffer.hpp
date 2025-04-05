#pragma once

#include "core/base.hpp"
#include "core/object.hpp"

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

extern "C"
{
IGNIS_API u32 get_shader_data_type_size(ShaderDataType type);
IGNIS_API GLenum get_gl_shader_data_type(ShaderDataType type);
}


struct IGNIS_API BufferElement
{
    ShaderDataType type = ShaderDataType_Unknown;
    const char *name;
    u32 size, offset;
    bool normalized = false;

    BufferElement() = default;

    BufferElement(ShaderDataType type, const char *name, const bool normalized = false)
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

class IGNIS_API BufferLayout
{
public:
    BufferLayout() = default;
    BufferLayout(std::initializer_list<BufferElement> elements);
    BufferLayout(const BufferLayout &other);
    
    void destroy();

    u32 get_stride() const;
    const std::vector<BufferElement>& get_elements() const;
    std::vector<BufferElement>::iterator begin();
    std::vector<BufferElement>::iterator end();
private:
    void calculate_offset_and_stride();

    class Impl;
    Impl *m_impl = nullptr;
};

class IGNIS_API GLBuffer : public Object {
public:
    u32 get_id() {return m_id;}

protected:
    u32 m_id = 0;
};
