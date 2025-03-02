#pragma once
#include "scene.hpp"
#include "entt.hpp"

#include <unordered_map>
#include <string>

class Scene;

class SceneManager {
public:
    static Ref<Scene> create_scene(const std::string &name);
    static Ref<Scene> find_scene(const std::string &name);
    static bool remove_scene(const std::string &name);

    static void set_active(const Ref<Scene> &scene);

    static std::unordered_map<UUID, entt::registry> scene_registry_map;

private:
    static std::unordered_map<std::string, Ref<Scene>> m_scenes;
    static Ref<Scene> m_current_scene;
};
