#pragma once

#include "core/base.hpp"

#include "entt.hpp"
#include "assets/asset.hpp"
#include "core/object.hpp"
#include "core/uuid.hpp"

#include <string>
#include <core/input/key_codes.hpp>

using EntityMap = std::unordered_map<UUID, entt::entity>;

class IGNIS_API Scene : public Asset {
public:
    Scene() = default;
    Scene(const std::string &name, AssetHandle handle = AssetHandle());
    ~Scene();

    void start_transition(const Ref<Scene> &next_scene);
    void destroy() override;

    void on_update(f32 delta_time);
    void render();

    entt::entity create_entity(const std::string &name, UUID uuid = UUID());
    entt::entity get_entity(UUID uuid);
    void destroy_entity(UUID uuid);
    void destroy_entity(entt::entity entity);

    template<typename T, typename... Args>
    T &entity_add_component(const entt::entity entity, Args &&... args)
    {
        if (entity_has_component<T>(entity))
            return entity_get_component<T>(entity);

        T &comp = get_registry().emplace_or_replace<T>(entity, std::forward<Args>(args)...);
        return comp;
    }

    template<typename T, typename... Args>
    T &entity_add_or_replace_component(const entt::entity entity, Args &&... args)
    {
        T &comp = get_registry().emplace_or_replace<T>(entity, std::forward<Args>(args)...);
        return comp;
    }

    template<typename T>
    T &entity_get_component(const entt::entity entity)
    {
        return get_registry().get<T>(entity);
    }

    template<typename T>
    bool entity_has_component(const entt::entity entity) const
    {
        return get_registry().all_of<T>(entity);
    }

    const std::string &get_name();

    EntityMap &get_entities();
    entt::registry &get_registry() const;

    static Ref<Scene> create(const std::string &name, AssetHandle handle = AssetHandle());

    static AssetType get_static_type() { return ASSET_TYPE_SCENE; }
    AssetType get_type() const override { return get_static_type(); }

private:
    class Impl;
    Impl *m_impl;
};
