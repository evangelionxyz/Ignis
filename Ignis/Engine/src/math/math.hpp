#pragma once
#include "core/types.hpp"

#include <array>

#define GLM_ENABLE_EXPERIMENTAL
#include <glm/glm.hpp>
#include <glm/gtx/quaternion.hpp>

#include <imgui.h>
struct Math
{

};

enum Anchor
{
    Anchor_Center,
    Anchor_Left, Anchor_Right,
    Anchor_TopLeft, Anchor_TopRight,
    Anchor_BottomLeft, Anchor_BottomRight
};

struct Rect
{
    glm::vec2 min;
    glm::vec2 max;

    Rect() : min(0.0f, 0.0f), max(0.0f, 0.0f) {}
    Rect(glm::vec2 min, glm::vec2 max) : min(min), max(max) {}
    Rect(f32 min_x, f32 min_y, f32 max_x, f32 max_y) : min(min_x, min_y), max(max_x, max_y) {}

    glm::vec2 get_origin(Anchor anchor, const glm::vec2& offset = glm::vec2(0.0f, 0.0f)) const;

    const bool contains(const glm::vec2& p) const;
    const bool contains(const ImVec2& p) const;

    void set_min(const glm::vec2& min_) { this->min = min_; }
    void set_min(f32 x, f32 y) { min.x = x; min.y = y; }
    void set_max(const glm::vec2& max_) { this->max = max_; }
    void set_max(f32 x, f32 y) { max.x = x; max.y = y; }

    glm::vec2 get_center() const;

    glm::vec2 get_size() const;

    // glm::vec2 operator
    Rect operator+=(const glm::vec2& vec2) const
    {
        return { min + vec2, max + vec2 };
    }

    Rect operator-=(const glm::vec2& vec2) const
    {
        return { min - vec2, max - vec2 };
    }

    Rect operator*=(const glm::vec2& vec2) const
    {
        return { min * vec2, max * vec2 };
    }

    Rect operator/=(const glm::vec2& vec2) const
    {
        return { min / vec2, max / vec2 };
    }

    // operator
    Rect operator+(const Rect& rhs) const
    {
        return { min + rhs.min, max + rhs.max };
    }

    Rect operator-(const Rect& rhs) const
    {
        return { min - rhs.min, max - rhs.max };
    }

    Rect operator*(const Rect& rhs) const
    {
        return { min * rhs.min, max * rhs.max };
    }

    Rect operator/(const Rect& rhs) const
    {
        return { min / rhs.min, max / rhs.max };
    }
};

struct Margin
{
    f32 top, bottom, left, right;
    Margin() : top(0.0f), bottom(0.0f), left(0.0f), right(0.0f) {}
    Margin(f32 value) : top(value), bottom(value), left(value), right(value) {}
    Margin(f32 horizontal, f32 vertical) : top(vertical), bottom(vertical), left(horizontal), right(horizontal) {}
    Margin(f32 l, f32 r, f32 t, f32 b) : top(t), bottom(b), left(l), right(r) {}
};

struct AABB
{
    glm::vec3 min = glm::vec3(0.0f);
    glm::vec3 max = glm::vec3(0.0f);

    AABB() = default;
    AABB(const AABB&) = default;
    AABB(const glm::vec3& center, const glm::vec3& size);

    bool ray_intersection(const glm::vec3& ray_origin, const glm::vec3& ray_direction);
};

struct OBB
{
    glm::vec3 center;
    glm::vec3 half_extents;
    glm::mat3 orientation;

    OBB() = default;
    OBB(const OBB&) = default;
    OBB(const glm::vec3& center, const glm::vec3& worldScale, const glm::quat& rotation);

    std::array<glm::vec3, 8> get_vertices();

    bool ray_intersection(const glm::vec3& ray_origin, const glm::vec3& ray_direction, f32& t_intersect);
};