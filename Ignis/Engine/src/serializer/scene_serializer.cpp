#include "scene_serializer.hpp"
#include "renderer/renderer.hpp"
#include "scene/components.hpp"

#include "scene/entt.hpp"

class SceneSerializer::Impl
{
public:
    Ref<Scene> scene;
    std::filesystem::path filepath;

    Impl(Ref<Scene> scene, const std::filesystem::path &filepath)
        : scene(scene), filepath(filepath)
    {
    }
};

SceneSerializer::SceneSerializer(Ref<Scene> scene, const std::filesystem::path &filepath)
    : m_impl(new SceneSerializer::Impl(scene, filepath))
{
}

void SceneSerializer::serialize()
{
    Serializer sr(m_impl->filepath);

    sr.begin_map();
    {
        sr.begin_map("Scene");
        sr.add_key_value("Handle", m_impl->scene->handle);
        sr.add_key_value("Name", m_impl->scene->get_name());

        sr.begin_sequence("Entities");
        for (const auto &entity : m_impl->scene->get_entities())
        {
            ID &id_comp = m_impl->scene->entity_get_component<ID>(entity.second);
            sr.begin_map();
            sr.add_key_value_u64("Entity", id_comp.uuid);

            // tag component
            sr.begin_map("ID");
            sr.add_key_value_string("Name", id_comp.name);
            sr.end_map();

            // transform component
            if (m_impl->scene->entity_has_component<Transform>(entity.second))
            {
                Transform &transform = m_impl->scene->entity_get_component<Transform>(entity.second);
                sr.begin_map("Transform");
                sr.add_key_value_vec3("World_Translation", transform.get_world_translation());
                sr.add_key_value_quat("World_Rotation", transform.get_world_rotation());
                sr.add_key_value_vec3("World_Scale", transform.get_world_scale());
                sr.end_map();
            }

            // sprite component
            if (m_impl->scene->entity_has_component<Sprite>(entity.second))
            {
                Sprite &sprite = m_impl->scene->entity_get_component<Sprite>(entity.second);
                sr.begin_map("Sprite");
                sr.add_key_value_vec4("Color", sprite.get_color());
                sr.add_key_value_u64("TextureHandle", sprite.get_texture_handle());
                sr.end_map();
            }

            sr.end_map();
        }
        sr.end_sequence(); // !Entities
        sr.end_map(); // !Scene
    }
    sr.end_map();

    sr.serialize();
}

Ref<Scene> SceneSerializer::deserialize(const std::filesystem::path &filepath)
{
    YAML::Node data = YAML::LoadFile(filepath.string());

    if (!data["Scene"])
        return nullptr;

    YAML::Node scene_node = data["Scene"];

    std::string scene_name = scene_node["Name"].as<std::string>();
    AssetHandle scene_uuid = scene_node["Handle"].as<AssetHandle>();

    Ref<Scene> scene = Scene::create(scene_name, scene_uuid);

    if (!scene_node["Entities"])
        return nullptr;

    YAML::Node entities_node = scene_node["Entities"];

    for (YAML::iterator::value_type entity_node : entities_node)
    {
        UUID entity_uuid = entity_node["Entity"].as<UUID>();
        std::string entity_name = entity_node["ID"]["Name"].as<std::string>();

        entt::entity deserialized_entity = scene->create_entity(entity_name, entity_uuid);

        // transform component
        if (YAML::Node transform_node = entity_node["Transform"])
        {
            Transform &transform = scene->entity_add_component<Transform>(deserialized_entity);
            transform.set_world_translation(transform_node["World_Translation"].as<glm::vec3>());
            transform.set_world_rotation(transform_node["World_Rotation"].as<glm::quat>());
            transform.set_world_scale(transform_node["World_Scale"].as<glm::vec3>());
        }

        // sprite component
        if (YAML::Node sprite_node = entity_node["Sprite"])
        {
            Sprite &sprite = scene->entity_add_component<Sprite>(deserialized_entity);
            sprite.set_color(sprite_node["Color"].as<glm::vec4>());
            //sprite.texture_handle;
        }
    }

    return scene;
}
