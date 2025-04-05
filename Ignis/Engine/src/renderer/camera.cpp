#include "camera.hpp"

#include "core/input/input.hpp"
#include "core/input/key_event.hpp"
#include "glm/gtx/quaternion.hpp"

#include <imgui.h>

class Camera::Impl
{
public:
    CameraType type;
    f32 zoom = 3.0f, aspect_ratio = 1.0f;
    f32 yaw = 0.0f, pitch = 0.0f;

    glm::vec2 size;
    glm::vec3 position;
    glm::mat4 view_matrix;
    glm::mat4 projection_matrix;

    Camera::Impl(CameraType type, const glm::vec3 &position)
        : type(type), position(position)
    {
    }
};

Camera::Camera(CameraType type, const f32 width, const f32 height,const glm::vec3 &position)
    : m_impl(new Camera::Impl(type, position))
{
    resize({width, height});
    update_view_projection();
}

Camera::~Camera()
{
    if (m_impl)
        delete m_impl;
}

void Camera::on_update(f32 delta_time)
{
    //if (!ImGui::GetIO().WantTextInput)
    {
        if (Input::is_key_pressed(Key::A))
            m_impl->position -= get_right() * m_impl->zoom * delta_time;
        else if (Input::is_key_pressed(Key::D))
            m_impl->position += get_right() * m_impl->zoom * delta_time;

        if (Input::is_key_pressed(Key::W))
        {
            if (m_impl->type == CAMERA_TYPE_2D)
                m_impl->zoom -= m_impl->zoom * delta_time;
            else
                m_impl->position += get_forward() * delta_time;
        }
        else if (Input::is_key_pressed(Key::S))
        {
            if (m_impl->type == CAMERA_TYPE_2D)
                m_impl->zoom += m_impl->zoom * delta_time;
            else
                m_impl->position -= get_forward() * delta_time;
        }
    }
    

    update_view_projection();
}

void Camera::update_view_projection() {
    switch (m_impl->type)
    {
        case CAMERA_TYPE_2D:
        {
            const glm::vec2 ortho_size = {m_impl->zoom * m_impl->aspect_ratio, m_impl->zoom};
            m_impl->projection_matrix = glm::ortho(-ortho_size.x, ortho_size.x, -ortho_size.y, ortho_size.y, 0.1f, 100.0f);
            break;
        }
        case CAMERA_TYPE_3D:
        {
            m_impl->projection_matrix = glm::ortho(0.0f, 0.0f, m_impl->size.x, m_impl->size.y, 0.1f, 100.0f);
            break;
        }
    }
    m_impl->view_matrix = glm::translate(glm::mat4(1.0f), m_impl->position) * glm::toMat4(glm::quat({-m_impl->pitch, -m_impl->yaw, 0.0f}));
    m_impl->view_matrix = glm::inverse(m_impl->view_matrix);
}

void Camera::on_event(Event &e) 
{
    EventDispatcher dispatcher(e);
    dispatcher.dispatch<KeyPressedEvent>(BIND_CLASS_EVENT_FN(Camera::on_key_pressed_event));
    dispatcher.dispatch<MouseScrolledEvent>(BIND_CLASS_EVENT_FN(Camera::on_mouse_scroll_event));
}

bool Camera::on_mouse_scroll_event(MouseScrolledEvent &e)
{
    switch (m_impl->type) {
        case CAMERA_TYPE_2D: {
            const f32 scale_factor = std::max(m_impl->size.x, m_impl->size.y); // Scale movement speed

            if (Input::is_modifier_pressed(KeyMod::Alt)) {
                m_impl->zoom -= e.get_offset_y() * (m_impl->zoom * 0.1f);
                m_impl->zoom = std::max(m_impl->zoom, 0.1f);
            }
            else {
                const f32 move_speed = 50.0f / scale_factor;
                if (Input::is_modifier_pressed(KeyMod::LeftShift)) {
                    m_impl->position -= get_right() * e.get_offset_y() * move_speed * m_impl->aspect_ratio * m_impl->zoom;
                    m_impl->position += get_up() * e.get_offset_x() * move_speed * m_impl->aspect_ratio * m_impl->zoom;
                }
                else {
                    m_impl->position += get_right() * e.get_offset_x() * move_speed * m_impl->aspect_ratio * m_impl->zoom;
                    m_impl->position += get_up() * e.get_offset_y() * move_speed * m_impl->aspect_ratio * m_impl->zoom;
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
    m_impl->position = position;
}

void Camera::resize(const glm::vec2 &size)
{
    m_impl->size = size;
    m_impl->aspect_ratio = size.x / size.y;
}

void Camera::set_zoom(f32 zoom)
{
    m_impl->zoom = zoom;
}

const glm::mat4 &Camera::get_view_matrix() const 
{
    return m_impl->view_matrix;
}

const glm::mat4 &Camera::get_projection_matrix() const 
{
    return m_impl->projection_matrix;
}

glm::mat4 Camera::get_view_projection() const 
{
    return m_impl->projection_matrix * m_impl->view_matrix;
}

glm::vec3 Camera::get_position() const 
{
    return m_impl->position;
}

glm::vec3 Camera::get_forward() const 
{
    return glm::rotate(glm::quat({-m_impl->pitch, -m_impl->yaw, 0.0}), {0.0f, 0.0f, -1.0f});
}

glm::vec3 Camera::get_up() const 
{
    return glm::rotate(glm::quat({-m_impl->pitch, -m_impl->yaw, 0.0}), {0.0f, 1.0f, 0.0f});
}

glm::vec3 Camera::get_right() const 
{
    return glm::rotate(glm::quat({-m_impl->pitch, -m_impl->yaw, 0.0}), {1.0f, 0.0f, 0.0f});
}
