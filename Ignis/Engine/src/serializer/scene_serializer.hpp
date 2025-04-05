#pragma once
#include "scene/scene.hpp"
#include "serializer.hpp"

class IGNIS_API SceneSerializer
{
public:
    SceneSerializer(Ref<Scene> scene, const std::filesystem::path &filepath);

    void serialize();

    static Ref<Scene> deserialize(const std::filesystem::path &filepath);

private:
    class Impl;
    Impl *m_impl;
};