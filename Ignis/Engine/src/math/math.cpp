#include "math.hpp"

struct Rect::Impl
{
    glm::vec2 min;
    glm::vec2 max;

    Rect::Impl(const glm::vec2 &min, const glm::vec2 &max)
        : min(min), max(max)
    {
    }
};

Rect::Rect() 
    : m_impl(new Rect::Impl({0.0f, 0.0f}, {0.0f, 0.0f}))
{
}

Rect::Rect(glm::vec2 min, glm::vec2 max) 
    : m_impl(new Rect::Impl(min, max))
{
}

Rect::Rect(f32 min_x, f32 min_y, f32 max_x, f32 max_y) 
    : m_impl(new Rect::Impl({min_x, min_y}, {max_x, max_y})) 
{
}

Rect::~Rect()
{
    if (m_impl)
        delete m_impl;
}

glm::vec2 &Rect::get_min() const
{
    return m_impl->min;
}

glm::vec2 &Rect::get_max() const
{
    return m_impl->max;
}

glm::vec2 Rect::get_origin(Anchor anchor, const glm::vec2& offset) const
{
    switch (anchor)
    {
    case Anchor_BottomLeft: return { m_impl->min.x + offset.x, m_impl->min.y + offset.y };
    case Anchor_TopLeft: return { m_impl->min.x + offset.x, m_impl->max.y + offset.y };
    case Anchor_TopRight: return { m_impl->max.x + offset.x, m_impl->max.y + offset.y };
    case Anchor_Right: return { m_impl->max.x + offset.x, (m_impl->min.y + offset.y) / 2.0f };
    case Anchor_Left: return { m_impl->min.x + offset.x, (m_impl->max.y + offset.y) / 2.0f };

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
    return p.x >= m_impl->min.x && p.y >= m_impl->min.y && p.x <= m_impl->max.x && p.y <= m_impl->max.y;
}
const bool Rect::contains(const ImVec2& p) const
{
    return p.x >= m_impl->min.x && p.y >= m_impl->min.y && p.x <= m_impl->max.x && p.y <= m_impl->max.y;
}

void Rect::set_min(const glm::vec2& min) { m_impl->min = min; }
void Rect::set_min(f32 x, f32 y) { m_impl->min.x = x; m_impl->min.y = y; }
void Rect::set_max(const glm::vec2& max) { m_impl->max = max; }
void Rect::set_max(f32 x, f32 y) { m_impl->max.x = x; m_impl->max.y = y; }

glm::vec2 Rect::get_center() const
{
    return { (m_impl->min.x + m_impl->max.x) / 2.0f, (m_impl->min.y + m_impl->max.y) / 2.0f };
}

glm::vec2 Rect::get_size() const
{
    return { m_impl->max.x - m_impl->min.x, m_impl->max.y - m_impl->min.y };
}

// glm::vec2 operator
Rect Rect::operator+=(const glm::vec2& vec2) const
{
    return { m_impl->min + vec2, m_impl->max + vec2 };
}

Rect Rect::operator-=(const glm::vec2& vec2) const
{
    return { m_impl->min - vec2, m_impl->max - vec2 };
}

Rect Rect::operator*=(const glm::vec2& vec2) const
{
    return { m_impl->min * vec2, m_impl->max * vec2 };
}

Rect Rect::operator/=(const glm::vec2& vec2) const
{
    return { m_impl->min / vec2, m_impl->max / vec2 };
}

// operator
Rect Rect::operator+(const Rect& rhs) const
{
    return { m_impl->min + rhs.m_impl->min, m_impl->max + rhs.m_impl->max };
}

Rect Rect::operator-(const Rect& rhs) const
{
    return { m_impl->min - rhs.m_impl->min, m_impl->max - rhs.m_impl->max };
}

Rect Rect::operator*(const Rect& rhs) const
{
    return { m_impl->min * rhs.m_impl->min, m_impl->max * rhs.m_impl->max };
}

Rect Rect::operator/(const Rect& rhs) const
{
    return { m_impl->min / rhs.m_impl->min, m_impl->max / rhs.m_impl->max };
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


struct OBB::Impl
{
    glm::vec3 center;
    glm::vec3 half_extents;
    glm::mat3 orientation;

    OBB::Impl(const glm::vec3 &center, const glm::vec3 &half_extents, const glm::mat3 &orientation)
        : center(center), half_extents(half_extents), orientation(orientation)
    {
    } 
};


OBB::OBB(const glm::vec3& center, const glm::vec3& worldScale, const glm::quat& rotation)
    : m_impl(new OBB::Impl(center, worldScale * 0.5f, glm::mat3_cast(rotation)))
{
}

std::array<glm::vec3, 8> OBB::get_vertices()
{
    std::array<glm::vec3, 8> vertices;
    glm::vec3 axes[3] =
    {
     m_impl->orientation[0] * m_impl->half_extents.x,
     m_impl->orientation[1] * m_impl->half_extents.y,
     m_impl->orientation[2] * m_impl->half_extents.z
    };

    vertices[0] = m_impl->center - axes[0] - axes[1] - axes[2];
    vertices[1] = m_impl->center + axes[0] - axes[1] - axes[2];
    vertices[2] = m_impl->center - axes[0] + axes[1] - axes[2];
    vertices[3] = m_impl->center + axes[0] + axes[1] - axes[2];
    vertices[4] = m_impl->center - axes[0] - axes[1] + axes[2];
    vertices[5] = m_impl->center + axes[0] - axes[1] + axes[2];
    vertices[6] = m_impl->center - axes[0] + axes[1] + axes[2];
    vertices[7] = m_impl->center + axes[0] + axes[1] + axes[2];

    return vertices;
}

bool OBB::ray_intersection(const glm::vec3& ray_origin, const glm::vec3& ray_direction, f32& t_intersect)
{
    glm::vec3 delta = m_impl->center - ray_origin;
    f32 t_near = std::numeric_limits<f32>::lowest();  // start with lowest possible value
    f32 t_far = std::numeric_limits<f32>::max();  // start with max possible value

    std::array<glm::vec3, 3> axes = { m_impl->orientation[0], m_impl->orientation[1], m_impl->orientation[2] };

    for (int i = 0; i < axes.size(); ++i)
    {
        f32 e = glm::dot(axes[i], delta);
        f32 f = glm::dot(axes[i], ray_direction);

        // ray is not parallel to the slab
        if (fabs(f) > glm::epsilon<f32>())
        {
            f32 t1 = (e + m_impl->half_extents[i]) / f;
            f32 t2 = (e - m_impl->half_extents[i]) / f;

            if (t1 > t2) std::swap(t1, t2);  // ensure t1 is the near intersection

            t_near = t1 > t_near ? t1 : t_near;
            t_far = t2 < t_far ? t2 : t_far;

            // check if ray misses the box
            if (t_near > t_far || t_far < 0.0f) return false;
        }
        else // ray is parallel to the slab
        {
            if (-e - m_impl->half_extents[i] > 0.0f || -e + m_impl->half_extents[i] < 0.0f)
                return false;  // no intersection
        }
    }

    // if tNear > 0, return it, otherwise return tFar
    t_intersect = t_near > 0.0f ? t_near : t_far;
    return true;
}

