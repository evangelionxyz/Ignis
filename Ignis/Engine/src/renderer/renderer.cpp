#include "renderer.hpp"

RendererAPI Renderer::m_api;

void Renderer::init(RendererAPI api)
{
    m_api = api;
}

void Renderer::shutdown()
{
}

RendererAPI Renderer::get_api()
{
    return m_api;;
}
