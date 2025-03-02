#pragma once

#include "core/types.hpp"
#include "scene/entt.hpp"

class Scene;
class SceneHierarchyPanel
{
public:
    SceneHierarchyPanel() = default;
    void set_scene(Scene *scene);

    void render();
    void draw_entity_node(const entt::entity entity, i32 index);
    entt::entity draw_entity_create_context_menu() const;

    entt::entity get_selected_entity() const;
    Scene* get_scene() const;

private:
    bool is_deleting = false;
    Scene *m_scene;
    entt::entity m_selected_entity;
};
