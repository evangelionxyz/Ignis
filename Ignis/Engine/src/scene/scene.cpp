#include "scene.hpp"

Scene::Scene(const std::string &name)
    : m_name(name)
{
}

void Scene::start_transition(const Ref<Scene> &next_scene)
{
    m_next_scene = next_scene;
}

void Scene::destroy()
{
}

Ref<Scene> Scene::create(const std::string &name)
{
    return CreateRef<Scene>(name);
}
