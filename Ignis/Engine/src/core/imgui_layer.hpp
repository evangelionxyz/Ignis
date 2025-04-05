#pragma once
#include "object.hpp"

#include <imgui.h>

class Window;
class IGNIS_API ImGuiLayer : public Object
{
public:
    ImGuiLayer() = default;

    void init(Window *window);
    void set_context(ImGuiContext *context);
    void begin_render();
    void end_render();

    void destroy() override;
private:
    Window *m_window;
};