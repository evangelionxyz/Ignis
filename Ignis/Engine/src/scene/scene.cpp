#include "scene.hpp"
#include "components.hpp"

class Scene::Impl
{
public:
    std::string name;
    Ref<Scene> next_scene;
    EntityMap entities;
    entt::registry* registry;
    
    Impl(const std::string &name_)
        : name(name_)
    {
        registry = new entt::registry();
    }

    ~Impl()
    {
        if (registry)
            delete registry;
    }
};

Scene::Scene(const std::string &name, AssetHandle handle)
    : m_impl(new Scene::Impl(name)), Asset(handle)
{
}

Scene::~Scene()
{
    if (m_impl)
        delete m_impl;
}

entt::entity Scene::create_entity(const std::string &name, UUID uuid)
{
    const entt::entity entity = m_impl->registry->create();
    ID &id_comp = m_impl->registry->emplace<ID>(entity, ID(name.c_str(), uuid));
    m_impl->registry->emplace<Transform>(entity, Transform());
    m_impl->entities[id_comp.uuid] = entity;

    return entity;
}

entt::entity Scene::get_entity(const UUID uuid)
{
    if (m_impl->entities.contains(uuid))
        return m_impl->entities[uuid];
        
    return entt::null;
}

void Scene::destroy_entity(UUID uuid)
{
    entt::entity entity = get_entity(uuid);
    destroy_entity(entity);
}

void Scene::destroy_entity(entt::entity entity)
{
    m_impl->registry->destroy(entity);
    m_impl->entities.erase(std::ranges::find_if(m_impl->entities, [entity](const auto &pair)
    {
        return pair.second == entity;
    }));
}

const std::string &Scene::get_name()
{
    return m_impl->name;
}

EntityMap &Scene::get_entities()
{
    return m_impl->entities;;
}

entt::registry &Scene::get_registry() const
{
    return *m_impl->registry;
}

void Scene::start_transition(const Ref<Scene> &next_scene)
{
    m_impl->next_scene = next_scene;
}

void Scene::destroy()
{
    m_impl->entities.clear();
    delete m_impl->registry;

    m_impl->registry = nullptr;
}

void Scene::on_update(f32 delta_time)
{
    m_impl->registry->view<Transform>().each([&](auto entity, Transform &transform)
    {

    });
}

void Scene::render()
{
    m_impl->registry->view<Sprite>().each([&](auto entity, Sprite &sprite)
    {

    });
}

Ref<Scene> Scene::create(const std::string &name, UUID uuid)
{
    return CreateRef<Scene>(name, uuid);
}
