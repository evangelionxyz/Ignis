#pragma once

#include "core/object.hpp"

#define GLM_ENABLE_EXPERIMENTAL
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

enum CameraType
{
    CAMERA_TYPE_2D,
    CAMERA_TYPE_3D
};

class Camera : public Object
{
public:
    Camera() = default;
    Camera(CameraType type, const glm::vec3 &position = glm::vec3(0.0f));

    void set_size(const glm::vec2 &size);
    void set_zoom(f32 zoom);
    void set_position(const glm::vec3 &position);
    void on_update(f32 delta_time);

    const glm::mat4 &get_view_matrix();
    const glm::mat4 &get_projection_matrix();
    const glm::mat4 get_view_projection();

private:
    CameraType m_type;
    f32 m_zoom = 1.0f;
    glm::vec2 m_size;
    glm::vec3 m_position;
    glm::mat4 m_view_matrix;
    glm::mat4 m_projection_matrix;

};