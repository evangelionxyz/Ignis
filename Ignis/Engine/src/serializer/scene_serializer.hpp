#pragma once
#include "scene/scene.hpp"
#include "serializer.hpp"

class SceneSerializer
{
public:
    SceneSerializer(Ref<Scene> scene, const std::filesystem::path &filepath);

    void serialize();

    static Ref<Scene> deserialize(const std::filesystem::path &filepath);

private:
    Ref<Scene> m_scene;
    std::filesystem::path m_filepath;
};