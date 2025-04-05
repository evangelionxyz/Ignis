#pragma once

#include "core/object.hpp"

#define GLM_ENABLE_EXPERIMENTAL
#include <core/input/key_event.hpp>
#include <core/input/mouse_event.hpp>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

enum CameraType
{
    CAMERA_TYPE_2D,
    CAMERA_TYPE_3D
};

class IGNIS_API Camera : public Object
{
public:
    Camera() = default;
    Camera(CameraType type, const f32 width, const f32 height, const glm::vec3 &position = glm::vec3(0.0f, 0.0f, 1.0f));
    ~Camera();

    void resize(const glm::vec2 &size);
    void set_zoom(f32 zoom);
    void set_position(const glm::vec3 &position);
    void on_update(f32 delta_time);

    void update_view_projection();

    void on_event(Event &e) override;
    bool on_mouse_scroll_event(MouseScrolledEvent &e);
    bool on_key_pressed_event(KeyPressedEvent &e);

    const glm::mat4 &get_view_matrix() const;
    const glm::mat4 &get_projection_matrix() const;

    glm::mat4 get_view_projection() const;

    glm::vec3 get_position() const;
    glm::vec3 get_forward() const;
    glm::vec3 get_up() const;
    glm::vec3 get_right() const;

private:
    class Impl;
    Impl *m_impl;
};