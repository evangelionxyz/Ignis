#include "math.hpp"

glm::vec2 Rect::get_origin(Anchor anchor, const glm::vec2& offset) const
{
    switch (anchor)
    {
    case Anchor_BottomLeft: return { min.x + offset.x, min.y + offset.y };
    case Anchor_TopLeft: return { min.x + offset.x, max.y + offset.y };
    case Anchor_TopRight: return { max.x + offset.x, max.y + offset.y };
    case Anchor_Right: return { max.x + offset.x, (min.y + offset.y) / 2.0f };
    case Anchor_Left: return { min.x + offset.x, (max.y + offset.y) / 2.0f };

    default:
    case Anchor_Center:
    {
        const glm::vec2& center = get_center();
        return { center.x + offset.x, center.y + offset.y };
    }
    }
}

const bool Rect::contains(const glm::vec2& p) const
{
    return p.x >= min.x && p.y >= min.y && p.x <= max.x && p.y <= max.y;
}
const bool Rect::contains(const ImVec2& p) const
{
    return p.x >= min.x && p.y >= min.y && p.x <= max.x && p.y <= max.y;
}


glm::vec2 Rect::get_center() const
{
    return { (min.x + max.x) / 2.0f, (min.y + max.y) / 2.0f };
}

glm::vec2 Rect::get_size() const
{
    return { max.x - min.x, max.y - min.y };
}


AABB::AABB(const glm::vec3& center, const glm::vec3& size)
    : min(center - size * 0.5f), max(center + size * 0.5f)
{
}

bool AABB::ray_intersection(const glm::vec3& ray_origin, const glm::vec3& ray_direction)
{
    glm::vec3 inverted_direction = 1.0f / ray_direction;
    glm::vec3 t_min = (min - ray_origin) * inverted_direction;
    glm::vec3 t_max = (max - ray_origin) * inverted_direction;
    glm::vec3 t1 = glm::min(t_min, t_max);
    glm::vec3 t2 = glm::max(t_min, t_max);
    float tNear = glm::max(glm::max(t1.x, t1.y), t1.z);
    float tFar = glm::min(glm::min(t2.x, t2.y), t2.z);
    return tNear <= tFar && tFar > 0;
}

OBB::OBB(const glm::vec3& center, const glm::vec3& worldScale, const glm::quat& rotation)
    : center(center), half_extents(worldScale * 0.5f), orientation(glm::mat3_cast(rotation))
{
}

std::array<glm::vec3, 8> OBB::get_vertices()
{
    std::array<glm::vec3, 8> vertices;
    glm::vec3 axes[3] =
    {
        orientation[0] * half_extents.x,
        orientation[1] * half_extents.y,
        orientation[2] * half_extents.z
    };

    vertices[0] = center - axes[0] - axes[1] - axes[2];
    vertices[1] = center + axes[0] - axes[1] - axes[2];
    vertices[2] = center - axes[0] + axes[1] - axes[2];
    vertices[3] = center + axes[0] + axes[1] - axes[2];
    vertices[4] = center - axes[0] - axes[1] + axes[2];
    vertices[5] = center + axes[0] - axes[1] + axes[2];
    vertices[6] = center - axes[0] + axes[1] + axes[2];
    vertices[7] = center + axes[0] + axes[1] + axes[2];

    return vertices;
}

bool OBB::ray_intersection(const glm::vec3& ray_origin, const glm::vec3& ray_direction, f32& t_intersect)
{
    glm::vec3 delta = center - ray_origin;
    f32 t_near = std::numeric_limits<f32>::lowest();  // start with lowest possible value
    f32 t_far = std::numeric_limits<f32>::max();  // start with max possible value

    std::array<glm::vec3, 3> axes = { orientation[0], orientation[1], orientation[2] };

    for (int i = 0; i < axes.size(); ++i)
    {
        f32 e = glm::dot(axes[i], delta);
        f32 f = glm::dot(axes[i], ray_direction);

        // ray is not parallel to the slab
        if (fabs(f) > glm::epsilon<f32>())
        {
            f32 t1 = (e + half_extents[i]) / f;
            f32 t2 = (e - half_extents[i]) / f;

            if (t1 > t2) std::swap(t1, t2);  // ensure t1 is the near intersection

            t_near = t1 > t_near ? t1 : t_near;
            t_far = t2 < t_far ? t2 : t_far;

            // check if ray misses the box
            if (t_near > t_far || t_far < 0.0f) return false;
        }
        else // ray is parallel to the slab
        {
            if (-e - half_extents[i] > 0.0f || -e + half_extents[i] < 0.0f)
                return false;  // no intersection
        }
    }

    // if tNear > 0, return it, otherwise return tFar
    t_intersect = t_near > 0.0f ? t_near : t_far;
    return true;
}

