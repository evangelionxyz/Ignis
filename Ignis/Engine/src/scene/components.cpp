#include "components.hpp"

// ID Component
ID::ID()
    : name("untitled"), uuid(0)
{
}

ID::ID(const std::string &name, UUID uuid)
    : name(name), uuid(uuid)
{
}

// Transform component
Transform::Transform()
    : world_translation(0.0f), world_rotation(glm::quat(0.0f, 0.0f, 0.0f, 1.0f)), world_scale(1.0f)
{   
}
Transform::Transform(const Transform &other)
    : world_translation(other.world_translation), world_rotation(other.world_rotation), world_scale(other.world_scale)
{
}

Transform::Transform(const glm::vec3 &translation, const glm::quat &rotation, const glm::vec3 &scale)
    : world_translation(translation), world_rotation(rotation), world_scale(scale)
{
}

// Sprite Component
Sprite::Sprite()
    : color(1.0f)
{
}
Sprite::Sprite(const Sprite &)
    : color(1.0f)
{
}
Sprite::Sprite(const glm::vec4 &color)
    : color(color)
{
}