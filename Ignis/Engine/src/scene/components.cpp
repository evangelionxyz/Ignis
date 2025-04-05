#include "components.hpp"

// ID Component
class ID::Impl
{
public:
    std::vector<UUID> children;
};

ID::ID()
    : name("No Name"), m_impl(new Impl()), uuid(0)
{
}

ID::ID(const char *name_, UUID uuid)
    : name(name_), m_impl(new Impl()), uuid(uuid)
{
}


void ID::destroy()
{
    if (m_impl)
        delete m_impl;
}

std::vector<UUID> &ID::get_children()
{
    return m_impl->children;
}


// Transform component

class Transform::Impl
{
public:
    glm::mat4 world_transform, local_transform;
    glm::vec3 world_translation, local_translation;
    glm::vec3 world_scale, local_scale;
    glm::quat world_rotation, local_rotation;

    Impl(const glm::vec3 &translation, const glm::quat &rotation, const glm::vec3 &scale)
        : world_translation(translation), world_rotation(rotation), world_scale(scale)
    {
    } 
};

Transform::Transform()
    : m_impl(new Transform::Impl(glm::vec3(0.0f), glm::quat(0.0f, 0.0f, 0.0f, 1.0f), glm::vec3(1.0f)))
{   
}
Transform::Transform(const Transform &other)
    : m_impl(new Transform::Impl(
        glm::vec3(other.m_impl->world_translation),
        other.m_impl->world_rotation, 
        other.m_impl->world_scale))
{
}

Transform::Transform(const glm::vec3 &translation, const glm::quat &rotation, const glm::vec3 &scale)
    : m_impl(new Transform::Impl(translation, rotation, scale))
{
}

Transform::~Transform()
{
    if (m_impl)
        delete m_impl;
}

void Transform::set_world_translation(const glm::vec3 &translation)
{
    m_impl->world_translation = translation;
}

void Transform::set_world_rotation(const glm::quat &rotation)
{
    m_impl->world_rotation = rotation;
}

void Transform::set_world_scale(const glm::vec3 &scale)
{
    m_impl->world_scale = scale;
}

void Transform::set_local_translation(const glm::vec3 &translation)
{
    m_impl->local_translation = translation;
}

void Transform::set_local_rotation(const glm::quat &rotation)
{
    m_impl->local_rotation = rotation;
}

void Transform::set_local_scale(const glm::vec3 &scale)
{
    m_impl->local_scale = scale;
}

glm::mat4 Transform::get_world_transform() const
{
    m_impl->world_transform = glm::translate(glm::mat4(1.0f), m_impl->world_translation)
        * glm::toMat4(m_impl->world_rotation) * glm::scale(glm::mat4(1.0f), m_impl->world_scale);
    return m_impl->world_transform;
}

glm::mat4 Transform::get_local_transform() const
{
    m_impl->local_transform = glm::translate(glm::mat4(1.0f), m_impl->local_translation)
        * glm::toMat4(m_impl->local_rotation) * glm::scale(glm::mat4(1.0f), m_impl->local_scale);
    return m_impl->local_transform;
}

glm::vec3 Transform::get_world_euler_rotation() const
{
    return glm::eulerAngles(m_impl->world_rotation);
}

glm::vec3 Transform::get_local_euler_rotation() const
{
    return glm::eulerAngles(m_impl->local_rotation);
}

const glm::vec3 &Transform::get_world_translation() const
{
    return m_impl->world_translation;
}

const glm::quat &Transform::get_world_rotation() const
{
    return m_impl->world_rotation;
}

const glm::vec3 &Transform::get_world_scale() const
{
    return m_impl->world_scale;
}

const glm::vec3 &Transform::get_local_translation() const
{
    return m_impl->local_translation;
}

const glm::quat &Transform::get_local_rotation() const
{
    return m_impl->world_rotation;
}

const glm::vec3 &Transform::get_local_scale() const
{
    return m_impl->local_scale;
}

// Sprite Component
class Sprite::Impl
{
public:
    glm::vec4 color;
    AssetHandle texture_handle;

    Impl(const glm::vec4 &clr)
        : color(clr)
    {
    }
};

Sprite::Sprite()
    : m_impl(new Sprite::Impl(glm::vec4(1.0f)))
{
}
Sprite::Sprite(const Sprite & other)
    : m_impl(new Sprite::Impl(other.m_impl->color))
{
}
Sprite::Sprite(const glm::vec4 &color)
    : m_impl(new Sprite::Impl(color))
{
}

Sprite::~Sprite()
{
    if (m_impl)
        delete m_impl;
}

const glm::vec4 &Sprite::get_color() const
{
    return m_impl->color;
}

void Sprite::set_color(const glm::vec4 &color)
{
    m_impl->color = color;
}

AssetHandle &Sprite::get_texture_handle() const
{
    return m_impl->texture_handle;
}

void set_texture_handle(AssetHandle handle)
{

}
