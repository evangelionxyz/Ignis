#version 450 core
layout(location = 0) in vec2 position;
layout(location = 1) in vec2 texture_coord;

layout(location = 0) out Vertex
{
    vec2 position;
    vec2 texture_coord;
} vout;

uniform mat4 u_view_projection;
uniform mat4 u_model_matrix;
void main()
{
    gl_Position = u_view_projection * u_model_matrix * vec4(position, 0.0, 1.0);

    vout.position = position;
    vout.texture_coord = texture_coord;
}