#pragma once

#include <iostream>

#include <core/application.hpp>
#include <core/base.hpp>
#include <core/window.hpp>

#include <core/input/event.hpp>
#include <core/input/key_event.hpp>
#include <core/input/app_event.hpp>
#include <core/input/mouse_event.hpp>
#include <core/logger.hpp>
#include <renderer/renderer.hpp>
#include <renderer/gl/gl_shader.hpp>
#include <renderer/gl/gl_framebuffer.hpp>
#include <renderer/camera.hpp>
#include <core/imgui_layer.hpp>
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

    void draw_viewport();
    void resize();

    GLFramebuffer m_viewport_framebuffer;
    ImGuiLayer m_imgui_layer;
    Window m_window;
    GLShader m_shader;
    Camera m_camera;
    u32 m_vao;

    glm::ivec2 m_viewport_size;
};