#pragma once
#include "core/buffer.hpp"
#include "core/types.hpp"
#include "core/object.hpp"

enum TextureFormat
{
    TEXTURE_FORMAT_UNKNOWN,
    TEXTURE_FORMAT_RED_INTEGER,
    TEXTURE_FORMAT_RGB,
    TEXTURE_FORMAT_RGBA,
    TEXTURE_FORMAT_RGBA8,
    TEXTURE_FORMAT_RGBA16F,
    TEXTURE_FORMAT_DEPTH,
    TEXTURE_FORMAT_DEPTH24STENCIL8,
};

enum TextureWrap
{
    TEXTURE_WRAP_CLAMP_TO_EDGE,
    TEXTURE_WRAP_REPEAT
};

enum TextureFilter
{
    TEXTURE_FILTER_LINEAR,
    TEXTURE_FILTER_NEAREST
};

struct TextureSpec
{
    TextureFormat format;
    TextureWrap wrap_mode;
    TextureFilter filter;
    i32 width, height, channels;

    TextureSpec()
        : format(TEXTURE_FORMAT_RGBA8), wrap_mode(TEXTURE_WRAP_CLAMP_TO_EDGE), filter(TEXTURE_FILTER_LINEAR),
            width(1), height(1), channels(static_cast<i32>(format))
    {
    }
};

static bool is_depth_format(const TextureFormat format)
{
    switch (format) {
        case TEXTURE_FORMAT_DEPTH:
        case TEXTURE_FORMAT_DEPTH24STENCIL8: return true;
        default: return false;
    }
}

class Texture : public Object
{
public:
    virtual void set_data(const Buffer &buffer) = 0;
    virtual u32 get_id() const = 0;
    virtual i32 get_index() const = 0;
    virtual void bind(i32 index) = 0;

    static Ref<Texture> create(const TextureSpec &spec, const Buffer &buffer = Buffer());
    static Ref<Texture> create(const std::string &filepath);
};