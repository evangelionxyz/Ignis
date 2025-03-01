#include "scene_manager.hpp"

#include "scene.hpp"

std::unordered_map<std::string, Ref<Scene>> SceneManager::m_scenes;
Ref<Scene> SceneManager::m_current_scene;

Ref<Scene> SceneManager::create_scene(const std::string &name)
{
    m_scenes[name] = Scene::create(name);
    if (!m_current_scene) {
        m_current_scene = m_scenes[name];
        return m_current_scene;
    }
    return nullptr;
}

Ref<Scene> SceneManager::find_scene(const std::string &name)
{
    if (m_scenes.contains(name)) {
        return m_scenes[name];
    }
    return nullptr;
}

bool SceneManager::remove_scene(const std::string &name)
{
    if (m_scenes.contains(name)) {
        m_scenes.erase(name);
        return true;
    }
    return false;
}

void SceneManager::set_active(const Ref<Scene> &scene)
{
    m_current_scene = scene;
}
