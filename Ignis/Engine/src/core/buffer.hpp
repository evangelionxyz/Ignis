#pragma once

#include "types.hpp"

#include <cstring>

struct Buffer
{
    u8* data = nullptr;
    u64 size = 0;

    Buffer() = default;
    explicit Buffer(const u64 size)
    {
        allocate(size);
    }

    Buffer(const void* data, u64 size)
        : data((u8*)data), size(size)
    {
    }

    static Buffer copy(const Buffer other)
    {
        const Buffer result(other.size);
        memcpy(result.data, other.data, other.size);
        return result;
    }

    void allocate(const u64 size)
    {
        release();

        data = static_cast<u8 *>(malloc(size));
        this->size = size;
    }

    void release()
    {
        free(data);
        data = nullptr;
        size = 0;
    }

    template<typename T>
    T* as()
    {
        return static_cast<T *>(data);
    }

    explicit operator bool() const
    {
        return static_cast<bool>(data);
    }
};

struct ScopedBuffer
{
    explicit ScopedBuffer(const Buffer buffer)
        : m_buffer(buffer)
    {
    }

    ScopedBuffer(u64 size)
        : m_buffer(size)
    {
    }

    ~ScopedBuffer()
    {
        m_buffer.release();
    }

    u8* get_data() const
    {
        return m_buffer.data;
    }

    u8 get_size() const
    {
        return static_cast<u8>(m_buffer.size);
    }

    template<typename T>
    T* as()
    {
        return m_buffer.as<T>();
    }

    operator bool() const { return static_cast<bool>(m_buffer); }

private:
    Buffer m_buffer;

};