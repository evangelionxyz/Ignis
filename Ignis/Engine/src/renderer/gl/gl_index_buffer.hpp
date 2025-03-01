#pragma once

#include <core/types.hpp>
#include "gl_buffer.hpp"

class GLIndexBuffer : public GLBuffer {
public:

    GLIndexBuffer(u32 size);
    GLIndexBuffer(const u32 *indices, u32 count);

    void bind() const;
    static void unbind();

    void destroy() override;
    u32 get_count() const;

    static Ref<GLIndexBuffer> create(u32 size);
    static Ref<GLIndexBuffer> create(u32 *indices, u32 size);
private:
    u32 m_count = 0;


};
