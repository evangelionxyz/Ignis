#pragma once
#include "ignis_engine.hpp"
#include "inspector_panel.hpp"
#include "scene_hierarchy_panel.hpp"
#include "content_browser_panel.hpp"

#include <unordered_map>

class IgnisEditor : public Application
{
public:
    IgnisEditor();

    void run() override;
    void on_event(Event &event) override;

    void destroy() override;
    const Ref<Texture> &get_icons(const std::string &name);

    static IgnisEditor *get();

    Window *get_window();
private:
    void init();
    void on_update(f32 delta_time);
    void on_gui_render(f32 delta_time);

    void load_scene(const std::filesystem::path &filepath);

    void draw_viewport();
    void resize();

    GLFramebuffer m_viewport_framebuffer;
    ImGuiLayer m_imgui_layer;
    Window m_window;
    GLShader m_shader;
    Camera m_camera;

    static IgnisEditor *s_instance;

    Ref<GLVertexArray> m_vertex_array;
    Ref<GLVertexBuffer> m_vertex_buffer;

    glm::ivec2 m_viewport_size;
    Ref<Scene> m_scene;

    Ref<SceneHierarchyPanel> m_scene_hierarchy_panel;
    Ref<InspectorPanel> m_inspector_panel;
    Ref<ContentBrowserPanel> m_content_browser_panel;

    bool is_viewport_hovered = false, is_viewport_active = false;

    glm::vec4 m_clear_color = glm::vec4(0.1f, 0.1f, 0.1f, 1.0f);

    Ref<Texture> m_texture;

    std::unordered_map<std::string, Ref<Texture>> m_icons;
};
