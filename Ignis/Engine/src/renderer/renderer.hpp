#pragma once
#include "texture.hpp"

enum class RendererAPI
{
    UNKNOWN = -1,
    OPENGL,
    VULKAN
};

class Renderer
{
public:
    static void create(RendererAPI api = RendererAPI::OPENGL);
    static void init();
    static void shutdown();
    static RendererAPI get_api();

    static Ref<Texture> white_texture;
    static Ref<Texture> black_texture;
private:
    static RendererAPI m_api;
};