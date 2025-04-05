#pragma once

#include "core/base.hpp"

#include "core/uuid.hpp"
#include "assets/asset.hpp"

#include <string>

#include <glm/glm.hpp>
#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/quaternion.hpp>

class IGNIS_API Texture;

class IGNIS_API Component
{
public:
    virtual void destroy() {};
};

class IGNIS_API ID : Component
{
public:
    ID();
    ID(const char *name, UUID uuid = UUID());

    void destroy() override;

    std::vector<UUID> &get_children();

    const char *name;
    UUID uuid;
public:
    class Impl;
    Impl *m_impl;
};

class IGNIS_API Transform : Component
{
public:
    Transform();
    Transform(const Transform &other);
    Transform(const glm::vec3 &translation, const glm::quat &rotation, const glm::vec3 &scale);

    ~Transform();

    void set_world_translation(const glm::vec3 &translation);
    void set_world_rotation(const glm::quat &rotation);
    void set_world_scale(const glm::vec3 &scale);

    void set_local_translation(const glm::vec3 &translation);
    void set_local_rotation(const glm::quat &rotation);
    void set_local_scale(const glm::vec3 &scale);

    glm::mat4 get_world_transform() const;
    glm::mat4 get_local_transform() const;
    glm::vec3 get_world_euler_rotation() const;
    glm::vec3 get_local_euler_rotation() const;

    const glm::vec3 &get_world_translation() const;
    const glm::quat &get_world_rotation() const;
    const glm::vec3 &get_world_scale() const;

    const glm::vec3 &get_local_translation() const;
    const glm::quat &get_local_rotation() const;
    const glm::vec3 &get_local_scale() const;

private:
    class Impl;
    Impl *m_impl;
};

class IGNIS_API Sprite : Component
{
public:
    Sprite();
    Sprite(const Sprite &);
    Sprite(const glm::vec4 &color);

    ~Sprite();

    const glm::vec4 &get_color() const;
    void set_color(const glm::vec4 &color);

    AssetHandle &get_texture_handle() const;
    void set_texture_handle(AssetHandle handle);
private:
    class Impl;
    Impl *m_impl;
};