#pragma once
#include "assets/asset.hpp"

#include "scene.hpp"
#include "entt.hpp"

#include <unordered_map>
#include <string>

class Scene;

class IGNIS_API SceneManager {
public:
    static Ref<Scene> create_scene(const std::string &name);
    static Ref<Scene> find_scene(const std::string &name);
    static bool remove_scene(const std::string &name);

    static void set_active(const Ref<Scene> &scene);
};
