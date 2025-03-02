#pragma once
#include "ignis_engine.hpp"
#include "inspector_panel.hpp"
#include "scene_hierarchy_panel.hpp"

class IgnisEditor : public Application
{
public:
    IgnisEditor();

    void run() override;
    void on_event(Event &event) override;

    void destroy() override;
private:
    void init_panels();
    void on_update(f32 delta_time);
    void on_gui_render(f32 delta_time);

    void draw_viewport();
    void resize();

    GLFramebuffer m_viewport_framebuffer;
    ImGuiLayer m_imgui_layer;
    Window m_window;
    GLShader m_shader;
    Camera m_camera;

    Ref<GLVertexArray> m_vertex_array;
    Ref<GLVertexBuffer> m_vertex_buffer;

    glm::ivec2 m_viewport_size;
    Ref<Scene> m_scene;

    Ref<SceneHierarchyPanel> m_scene_hierarchy_panel;
    Ref<InspectorPanel> m_inspector_panel;

    bool is_viewport_hovered = false, is_viewport_active = false;

    glm::vec4 m_clear_color = glm::vec4(0.1f, 0.1f, 0.1f, 1.0f);

    Ref<Texture> m_texture;
};
