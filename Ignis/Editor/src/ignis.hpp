#pragma once

#include <iostream>

#include <core/application.hpp>
#include <core/base.hpp>
#include <core/window.hpp>

#include <core/input/event.hpp>
#include <core/input/key_event.hpp>
#include <core/input/app_event.hpp>
#include <core/input/mouse_event.hpp>

#include <renderer/shader.hpp>
#include <core/imgui_layer.hpp>

#include <SDL3/SDL_gpu.h>
#include <glad/gl.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class IgnisEditor : public Application
{
public:
    IgnisEditor();

    void run() override;
    void on_event(Event &event) override;

    void destroy() override;
private:
    void on_update(f32 delta_time);
    void on_gui_render(f32 delta_time);

    Window m_window;
    ImGuiLayer m_imgui_layer;
    Shader m_shader;
};