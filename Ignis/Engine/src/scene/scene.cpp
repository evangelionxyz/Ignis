#include "scene.hpp"
#include "components.hpp"

Scene::Scene(const std::string &name, UUID uuid)
    : m_name(name), m_uuid(uuid)
{
    m_registry = new entt::registry();
}

entt::entity Scene::create_entity(const std::string &name, UUID uuid)
{
    const entt::entity entity = m_registry->create();
    ID &id_comp = m_registry->emplace<ID>(entity, ID(name, uuid));
    m_registry->emplace<Transform>(entity, Transform());
    m_entities[id_comp.uuid] = entity;

    return entity;
}

entt::entity Scene::get_entity(const UUID uuid)
{
    if (m_entities.contains(uuid))
        return m_entities[uuid];
        
    return entt::null;
}

void Scene::destroy_entity(UUID uuid)
{
    entt::entity entity = get_entity(uuid);
    destroy_entity(entity);
}

void Scene::destroy_entity(entt::entity entity)
{
    m_registry->destroy(entity);
    m_entities.erase(std::ranges::find_if(m_entities, [entity](const auto &pair)
    {
        return pair.second == entity;
    }));
}

const std::string &Scene::get_name()
{
    return m_name;
}

EntityMap &Scene::get_entities()
{
    return m_entities;;
}

entt::registry &Scene::get_registry() const
{
    return *m_registry;
}

void Scene::start_transition(const Ref<Scene> &next_scene)
{
    m_next_scene = next_scene;
}

void Scene::destroy()
{
    m_entities.clear();
    delete m_registry;
}

void Scene::on_update(f32 delta_time)
{
    m_registry->view<Transform>().each([&](auto entity, Transform &transform)
    {

    });
}

void Scene::render()
{
    m_registry->view<Sprite>().each([&](auto entity, Sprite &sprite)
    {

    });
}

UUID Scene::get_uuid() const
{
    return m_uuid;
}

Ref<Scene> Scene::create(const std::string &name, UUID uuid)
{
    return CreateRef<Scene>(name, uuid);
}
