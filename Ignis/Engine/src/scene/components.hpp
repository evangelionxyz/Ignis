#pragma once

#include "core/uuid.hpp"

#include <string>

#include <glm/glm.hpp>
#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/quaternion.hpp>

class Texture;

struct Component
{
    virtual void destroy() {};
};

struct ID : Component
{
    ID();
    ID(const std::string &name, UUID uuid = UUID());


    std::string name;
    UUID uuid;

    std::vector<UUID> children;
};

struct Transform : Component
{
    Transform();
    Transform(const Transform &other);
    Transform(const glm::vec3 &translation, const glm::quat &rotation, const glm::vec3 &scale);

    glm::mat4 world_transform, local_transform;
    glm::vec3 world_translation, local_translation;
    glm::vec3 world_scale, local_scale;
    glm::quat world_rotation, local_rotation;

    glm::mat4 get_world_transform()
    {
        world_transform = glm::translate(glm::mat4(1.0f), world_translation)
            * glm::toMat4(world_rotation) * glm::scale(glm::mat4(1.0f), world_scale);
        return world_transform;
    }

    glm::mat4 get_local_transform()
    {
        local_transform = glm::translate(glm::mat4(1.0f), local_translation)
            * glm::toMat4(local_rotation) * glm::scale(glm::mat4(1.0f), local_scale);
        return local_transform;
    }

    glm::vec3 get_world_euler_rotation()
    {
        return glm::eulerAngles(world_rotation);
    }

    glm::vec3 get_local_euler_rotation()
    {
        return glm::eulerAngles(local_rotation);
    }
};

struct Sprite : Component
{
    Sprite();
    Sprite(const Sprite &);
    Sprite(const glm::vec4 &color);

    Ref<Texture> texture;
    glm::vec4 color;
};