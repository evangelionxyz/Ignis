#include "scene.hpp"
#include "components.hpp"

Scene::Scene(const std::string &name, UUID uuid)
    : m_name(name), m_uuid(uuid)
{
    m_registry = new entt::registry();
}

entt::entity Scene::create_entity(const std::string &name)
{
    const entt::entity entity = m_registry->create();
    ID &id_comp = m_registry->emplace<ID>(entity, ID(name));
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
    if (entity != entt::null)
    {
        m_entities.erase(uuid);
        m_registry->destroy(entity);
    }
}

void Scene::destroy_entity(entt::entity entity)
{
    if (entity != entt::null)
    {
        const ID &id_comp = m_registry->get<ID>(entity);
        if (m_entities.contains(id_comp.uuid))
            m_entities.erase(id_comp.uuid);
        m_registry->destroy(entity);
    }
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
    //m_registry->
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

Ref<Scene> Scene::create(const std::string &name)
{
    return CreateRef<Scene>(name);
}
