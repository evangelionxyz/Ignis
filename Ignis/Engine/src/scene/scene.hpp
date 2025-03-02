#pragma once

#include "entt.hpp"

#include "core/object.hpp"
#include "core/uuid.hpp"

#include <string>
#include <core/input/key_codes.hpp>

using EntityMap = std::unordered_map<UUID, entt::entity>;

class Scene : public Object {
public:
    Scene() = default;
    Scene(const std::string &name, UUID uuid = UUID());

    void start_transition(const Ref<Scene> &next_scene);
    void destroy() override;

    void on_update(f32 delta_time);
    void render();

    entt::entity create_entity(const std::string &name);
    entt::entity get_entity(UUID uuid);
    void destroy_entity(UUID uuid);
    void destroy_entity(entt::entity entity);

    template<typename T, typename... Args>
    T &entity_add_component(const entt::entity entity, Args &&... args)
    {
        if (entity_has_component<T>(entity))
            return entity_get_component<T>(entity);

        T &comp = m_registry->emplace_or_replace<T>(entity, std::forward<Args>(args)...);
        return comp;
    }

    template<typename T, typename... Args>
    T &entity_add_or_replace_component(const entt::entity entity, Args &&... args)
    {
        T &comp = m_registry->emplace_or_replace<T>(entity, std::forward<Args>(args)...);
        return comp;
    }

    template<typename T>
    T &entity_get_component(const entt::entity entity)
    {
        return m_registry->get<T>(entity);
    }

    template<typename T>
    bool entity_has_component(const entt::entity entity) const
    {
        return m_registry->all_of<T>(entity);
    }

    EntityMap &get_entities();
    entt::registry &get_registry() const;
    UUID get_uuid() const;
    static Ref<Scene> create(const std::string &name);

private:
    UUID m_uuid;
    std::string m_name;
    Ref<Scene> m_next_scene;

    EntityMap m_entities;
    entt::registry* m_registry;
};
