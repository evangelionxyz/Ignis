#version 450 core
layout(location = 0) in vec2 position;

uniform mat4 u_view_projection;
void main()
{
    gl_Position = u_view_projection * vec4(position, 0.0, 1.0);
}