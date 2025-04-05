#include "scene_hierarchy_panel.hpp"
#include "scene/scene.hpp"
#include "scene/components.hpp"

#include <imgui.h>

#include "renderer/renderer.hpp"

void SceneHierarchyPanel::set_scene(Scene *scene)
{
    m_scene = scene;
}

void SceneHierarchyPanel::render()
{
    ImGui::Begin("Hierarchy");

    if (m_scene != nullptr) 
    {
        // render entity node
        for (const auto e : m_scene->get_entities()) 
        {
            const entt::entity entity = m_scene->get_entity(e.first);
            draw_entity_node(entity, 0);

            if (is_deleting) 
            {
                break;
            }
        }

        is_deleting = false;

        // popup context
        if (ImGui::BeginPopupContextWindow("create_entity_context", ImGuiPopupFlags_MouseButtonRight | ImGuiPopupFlags_NoOpenOverItems)) 
        {
            m_selected_entity = draw_entity_create_context_menu();
            ImGui::EndPopup();
        }
    }

    ImGui::End();
}

void SceneHierarchyPanel::draw_entity_node(const entt::entity entity, i32 index)
{
    if (!m_scene->get_registry().valid(entity)) {
        return;
    }

    ID &id_comp = m_scene->entity_get_component<ID>(entity);

    const ImGuiTreeNodeFlags flags = (m_selected_entity == entity ? ImGuiTreeNodeFlags_Selected : 0)
        | ImGuiTreeNodeFlags_OpenOnDoubleClick | ImGuiTreeNodeFlags_OpenOnArrow | ImGuiTreeNodeFlags_Framed | ImGuiTreeNodeFlags_SpanAvailWidth | ImGuiTreeNodeFlags_SpanFullWidth;

    auto _id = reinterpret_cast<void*>(static_cast<u64>(static_cast<u32>(entity)));
    const bool opened = ImGui::TreeNodeEx(_id, flags, id_comp.name);

    if (ImGui::IsItemClicked()) {
        m_selected_entity = entity;
    }

    ImGui::PushID(_id);
    if (ImGui::BeginPopupContextItem(id_comp.name))
    {
        if (ImGui::MenuItem("Delete")) {
            m_scene->destroy_entity(entity);
            is_deleting = true;
        }

        ImGui::EndPopup();
    }
    ImGui::PopID();

    if (opened) {
        ImGui::TreePop();
    }
}

entt::entity SceneHierarchyPanel::draw_entity_create_context_menu() const
{
    entt::entity entity = entt::null;
    if (ImGui::BeginMenu("Create Entity")) {
        if (ImGui::MenuItem("Empty")) {
            entity = m_scene->create_entity("empty");
        }
        else if (ImGui::MenuItem("Sprite")) {
            entity = m_scene->create_entity("sprite");
            Sprite &sp = m_scene->entity_add_component<Sprite>(entity);
            //sp.texture = Renderer::white_texture;
        }
        ImGui::EndMenu();
    }

    return entity;
}

entt::entity SceneHierarchyPanel::get_selected_entity() const
{
    return m_selected_entity;
}

Scene* SceneHierarchyPanel::get_scene() const
{
    return m_scene;
}
