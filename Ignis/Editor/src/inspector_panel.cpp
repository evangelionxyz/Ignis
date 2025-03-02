#include "inspector_panel.hpp"
#include "scene/components.hpp"
#include "scene/scene.hpp"
#include "scene_hierarchy_panel.hpp"

#include <glm/gtc/type_ptr.hpp>
#include <imgui_internal.h>

InspectorPanel::InspectorPanel()
{
}

void InspectorPanel::render(f32 delta_time)
{
    ImGui::Begin("Inspector", nullptr);
    switch (m_state) {
        case INSPECTOR_STATE_SCENE: {
            draw_scene_inspector(delta_time);
            break;
        }
    }
    ImGui::End();
}

void InspectorPanel::set_data(void *data, InspectorState state)
{
    m_state = state;
    m_data = data;
}

void InspectorPanel::draw_scene_inspector(f32 delta_time)
{
    if (!m_data)
        return;

    SceneHierarchyPanel* sh = static_cast<SceneHierarchyPanel*>(m_data);
    Scene *scene = sh->get_scene();

    entt::entity selected_entity = sh->get_selected_entity();
    if (scene->get_registry().valid(selected_entity))
    {
        ID& id_comp = scene->entity_get_component<ID>(selected_entity);
        Transform& transform_comp = scene->entity_get_component<Transform>(selected_entity);
        auto _id = reinterpret_cast<void*>(static_cast<u64>(static_cast<u32>(selected_entity)));
        ImGui::PushID(_id);

        ImGui::Text("Name: %s", id_comp.name.c_str());

        ImGui::DragFloat3("Position", glm::value_ptr(transform_comp.world_translation), 0.025f);
        ImGui::DragFloat3("Scale", glm::value_ptr(transform_comp.world_scale), 0.025f);

        ImGui::PopID();
    }

}

