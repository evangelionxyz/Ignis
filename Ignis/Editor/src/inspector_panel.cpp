#include "inspector_panel.hpp"
#include "scene/components.hpp"
#include "scene/scene.hpp"
#include "scene_hierarchy_panel.hpp"

#include "ignis.hpp"

#include <glm/gtc/type_ptr.hpp>
#include <imgui_internal.h>

InspectorPanel::InspectorPanel()
{
}

void InspectorPanel::render()
{
    ImGui::Begin("Inspector", nullptr);
    switch (m_state) {
        case INSPECTOR_STATE_SCENE: {
            draw_scene_inspector();
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

void InspectorPanel::draw_scene_inspector()
{
    if (!m_data)
        return;

    SceneHierarchyPanel* sh = static_cast<SceneHierarchyPanel*>(m_data);
    Scene *scene = sh->get_scene();

    if (!scene)
        return;

    entt::entity selected_entity = sh->get_selected_entity();
    if (scene->get_registry().valid(selected_entity))
    {
        ID& id_comp = scene->entity_get_component<ID>(selected_entity);

        // ID component
        if (scene->entity_has_component<ID>(selected_entity))
        {
            char buffer[256];
            strncpy_s(buffer, id_comp.name.c_str(), sizeof(buffer));

            if (ImGui::InputText("##Tag", buffer, sizeof(buffer), ImGuiInputTextFlags_EnterReturnsTrue))
            {
                if (strlen(buffer) > 0) 
                {
                    id_comp.name = buffer;
                }
            }
        }

        ImGui::SameLine();
        ImGui::PushItemWidth(-1);

        if (ImGui::ImageButton("+", IgnisEditor::get()->get_icons("add")->get_id(), {16.0f, 16.0f}))
        {
            ImGui::OpenPopup("add_component");
        }

        ImGui::PopItemWidth();

        constexpr ImGuiTreeNodeFlags tree_node_flags = ImGuiTreeNodeFlags_DefaultOpen | ImGuiTreeNodeFlags_Framed | ImGuiTreeNodeFlags_SpanAvailWidth | ImGuiTreeNodeFlags_AllowItemOverlap;

        // Transform component
        if (scene->entity_has_component<Transform>(selected_entity))
        {
            Transform& transform_comp = scene->entity_get_component<Transform>(selected_entity);
            if (ImGui::TreeNodeEx("tr", tree_node_flags, "Transform"))
            {
                ImGui::DragFloat3("Position", glm::value_ptr(transform_comp.world_translation), 0.025f);
                ImGui::DragFloat3("Scale", glm::value_ptr(transform_comp.world_scale), 0.025f);

                ImGui::TreePop();
            }
        }

        // Sprite component
        if (scene->entity_has_component<Transform>(selected_entity))
        {
            Sprite& sp = scene->entity_get_component<Sprite>(selected_entity);
            if (ImGui::TreeNodeEx("sp", tree_node_flags, "Sprite")) 
            {
                ImGui::ColorEdit4("Color", glm::value_ptr(sp.color), ImGuiColorEditFlags_InputRGB);
                ImGui::TreePop();
            }
        }
    }

}

