#include "scene_serializer.hpp"
#include "renderer/renderer.hpp"
#include "scene/components.hpp"

#include "scene/entt.hpp"

SceneSerializer::SceneSerializer(Ref<Scene> scene, const std::filesystem::path &filepath)
    : m_scene(scene), m_filepath(filepath)
{
}

void SceneSerializer::serialize()
{
    Serializer sr(m_filepath);

    sr.begin_map();
    {
        sr.begin_map("Scene");
        sr.add_key_value("UUID", m_scene->get_uuid());
        sr.add_key_value("Name", m_scene->get_name());

        sr.begin_sequence("Entities");
        for (const auto &entity : m_scene->get_entities())
        {
            const ID &id_comp = m_scene->entity_get_component<ID>(entity.second);
            sr.begin_map();
            sr.add_key_value("Entity", id_comp.uuid);

            // tag component
            sr.begin_map("ID");
            sr.add_key_value("Name", id_comp.name);
            sr.end_map();

            // transform component
            if (m_scene->entity_has_component<Transform>(entity.second))
            {
                const Transform &transform = m_scene->entity_get_component<Transform>(entity.second);
                sr.begin_map("Transform");
                sr.add_key_value("World_Translation", transform.world_translation);
                sr.add_key_value("World_Rotation", transform.world_rotation);
                sr.add_key_value("World_Scale", transform.world_scale);
                sr.end_map();
            }

            // sprite component
            if (m_scene->entity_has_component<Sprite>(entity.second))
            {
                const Sprite &sprite = m_scene->entity_get_component<Sprite>(entity.second);
                sr.begin_map("Sprite");
                sr.add_key_value("Color", sprite.color);
                // TODO: Texture Asset Handle
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
    UUID scene_uuid = scene_node["UUID"].as<UUID>();

    Ref<Scene> scene = Scene::create(scene_name, scene_uuid);

    if (!scene_node["Entities"])
        return nullptr;

    YAML::Node entities_node = scene_node["Entities"];

    for (YAML::iterator::value_type entity_node : entities_node)
    {
        u64 entity_uuid = entity_node["Entity"].as<u64>();
        std::string entity_name = entity_node["ID"]["Name"].as<std::string>();

        entt::entity deserialized_entity = scene->create_entity(entity_name, entity_uuid);

        // transform component
        if (YAML::Node transform_node = entity_node["Transform"])
        {
            Transform &transform = scene->entity_add_component<Transform>(deserialized_entity);
            transform.world_translation = transform_node["World_Translation"].as<glm::vec3>();
            transform.world_rotation = transform_node["World_Rotation"].as<glm::quat>();
            transform.world_scale = transform_node["World_Scale"].as<glm::vec3>();
        }

        // sprite component
        if (YAML::Node sprite_node = entity_node["Sprite"])
        {
            Sprite &sprite = scene->entity_add_component<Sprite>(deserialized_entity);
            sprite.color = sprite_node["Color"].as<glm::vec4>();
            sprite.texture = Renderer::white_texture;
        }
    }

    return scene;
}
