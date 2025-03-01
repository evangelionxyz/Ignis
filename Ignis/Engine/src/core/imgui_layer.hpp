#pragma once
#include "object.hpp"

class Window;
class ImGuiLayer : public Object
{
public:
    ImGuiLayer() = default;
    ImGuiLayer(Window *window);

    void begin_render();
    void end_render();

    void destroy() override;
private:
    Window *m_window;
};