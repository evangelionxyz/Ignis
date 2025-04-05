#pragma once
#include "gl/gl_wrapper.hpp"
#include "texture.hpp"

enum class RendererAPI
{
    UNKNOWN = -1,
    OPENGL,
    VULKAN
};

class IGNIS_API Renderer
{
public:
    static void create(RendererAPI api = RendererAPI::OPENGL);
    static void init();
    static void shutdown();
    static RendererAPI get_api();

    static Ref<Texture> get_white_texture();
    static Ref<Texture> get_black_texture();
private:
    static RendererAPI m_api;
};