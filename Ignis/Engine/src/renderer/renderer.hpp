#pragma once

enum class RendererAPI
{
    OPENGL,
    VULKAN
};

class Renderer
{
public:
    static void init(RendererAPI api = RendererAPI::OPENGL);
    static void shutdown();

    static RendererAPI get_api();
private:
    static RendererAPI m_api;
};