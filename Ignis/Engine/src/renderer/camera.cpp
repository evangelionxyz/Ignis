#include "camera.hpp"

#include "core/input/input.hpp"
#include "core/input/key_event.hpp"
#include "glm/gtx/quaternion.hpp"

#include <imgui.h>

Camera::Camera(CameraType type, const f32 width, const f32 height,const glm::vec3 &position)
    : m_type(type), m_position(position)
{
    resize({width, height});
    update_view_projection();
}

void Camera::on_update(f32 delta_time)
{
    if (!ImGui::GetIO().WantTextInput)
    {
        if (Input::keycodes[Key::A])
            m_position -= get_right() * m_zoom * delta_time;
        else if (Input::keycodes[Key::D])
            m_position += get_right() * m_zoom * delta_time;

        if (Input::keycodes[Key::W])
        {
            if (m_type == CAMERA_TYPE_2D)
                m_zoom -= m_zoom * delta_time;
            else
                m_position += get_forward() * delta_time;
        }
        else if (Input::keycodes[Key::S])
        {
            if (m_type == CAMERA_TYPE_2D)
                m_zoom += m_zoom * delta_time;
            else
                m_position -= get_forward() * delta_time;
        }
    }
    

    update_view_projection();
}

void Camera::update_view_projection() {
    switch (m_type)
    {
        case CAMERA_TYPE_2D:
        {
            const glm::vec2 ortho_size = {m_zoom * m_aspect_ratio, m_zoom};
            m_projection_matrix = glm::ortho(-ortho_size.x, ortho_size.x, -ortho_size.y, ortho_size.y, 0.1f, 100.0f);
            break;
        }
        case CAMERA_TYPE_3D:
        {
            m_projection_matrix = glm::ortho(0.0f, 0.0f, m_size.x, m_size.y, 0.1f, 100.0f);
            break;
        }
    }
    m_view_matrix = glm::translate(glm::mat4(1.0f), m_position) * glm::toMat4(glm::quat({-m_pitch, -m_yaw, 0.0f}));
    m_view_matrix = glm::inverse(m_view_matrix);
}

void Camera::on_event(Event &e) 
{
    EventDispatcher dispatcher(e);
    dispatcher.dispatch<KeyPressedEvent>(BIND_CLASS_EVENT_FN(Camera::on_key_pressed_event));
    dispatcher.dispatch<MouseScrolledEvent>(BIND_CLASS_EVENT_FN(Camera::on_mouse_scroll_event));
}

bool Camera::on_mouse_scroll_event(MouseScrolledEvent &e)
{
    switch (m_type) {
        case CAMERA_TYPE_2D: {
            const f32 scale_factor = std::max(m_size.x, m_size.y); // Scale movement speed

            if (Input::modifiers[KeyMod::Alt]) {
                m_zoom -= e.get_offset_y() * (m_zoom * 0.1f);
                m_zoom = std::max(m_zoom, 0.1f);
            }
            else {
                const f32 move_speed = 50.0f / scale_factor;
                if (Input::modifiers[KeyMod::LeftShift]) {
                    m_position -= get_right() * e.get_offset_y() * move_speed * m_aspect_ratio * m_zoom;
                    m_position += get_up() * e.get_offset_x() * move_speed * m_aspect_ratio * m_zoom;
                }
                else {
                    m_position += get_right() * e.get_offset_x() * move_speed * m_aspect_ratio * m_zoom;
                    m_position += get_up() * e.get_offset_y() * move_speed * m_aspect_ratio * m_zoom;
                }
            }
            break;
        }
    }

    return false;
}

bool Camera::on_key_pressed_event(KeyPressedEvent &e) 
{
    return false;
}

void Camera::set_position(const glm::vec3 &position)
{
    m_position = position;
}

void Camera::resize(const glm::vec2 &size)
{
    m_size = size;
    m_aspect_ratio = size.x / size.y;
}

void Camera::set_zoom(f32 zoom)
{
    m_zoom = zoom;
}

const glm::mat4 &Camera::get_view_matrix() const 
{
    return m_view_matrix;
}

const glm::mat4 &Camera::get_projection_matrix() const 
{
    return m_projection_matrix;
}

glm::mat4 Camera::get_view_projection() const 
{
    return m_projection_matrix * m_view_matrix;
}

glm::vec3 Camera::get_position() const 
{
    return m_position;
}

glm::vec3 Camera::get_forward() const 
{
    return glm::rotate(glm::quat({-m_pitch, -m_yaw, 0.0}), {0.0f, 0.0f, -1.0f});
}

glm::vec3 Camera::get_up() const 
{
    return glm::rotate(glm::quat({-m_pitch, -m_yaw, 0.0}), {0.0f, 1.0f, 0.0f});
}

glm::vec3 Camera::get_right() const 
{
    return glm::rotate(glm::quat({-m_pitch, -m_yaw, 0.0}), {1.0f, 0.0f, 0.0f});
}
