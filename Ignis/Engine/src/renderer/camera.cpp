#include "camera.hpp"

Camera::Camera(CameraType type, const glm::vec3 &position)
    : m_type(type), m_position(position)
{
    switch (type)
    {
        case CAMERA_TYPE_2D:
        {
            m_projection_matrix = glm::ortho(0.0f, 0.0f, m_size.x, m_size.y, 0.1f, 100.0f);
            m_view_matrix = glm::inverse(glm::translate(glm::mat4(1.0f), m_position));
            break;
        }
        case CAMERA_TYPE_3D:
        {
            m_projection_matrix = glm::ortho(0.0f, 0.0f, m_size.x, m_size.y, 0.1f, 100.0f);
            m_view_matrix = glm::inverse(glm::translate(glm::mat4(1.0f), m_position));
            break;
        }
    }
}

void Camera::on_update(f32 delta_time)
{
    m_view_matrix = glm::inverse(glm::translate(glm::mat4(1.0f), m_position));
}

void Camera::set_position(const glm::vec3 &position)
{
    m_position = position;
}

void Camera::set_size(const glm::vec2 &size)
{
    m_size = size;
}

void Camera::set_zoom(f32 zoom)
{
    m_zoom = zoom;
}

const glm::mat4 &Camera::get_view_matrix()
{
    return m_view_matrix;
}

const glm::mat4 &Camera::get_projection_matrix()
{
    return m_projection_matrix;
}

const glm::mat4 Camera::get_view_projection()
{
    return m_projection_matrix* m_view_matrix;
}
