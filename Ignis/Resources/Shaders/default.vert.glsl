#version 450 core
vec2 positions[3] = vec2[](
    vec2(-0.5, -0.5),
    vec2(0.0, 0.5),
    vec2(0.5, -0.5)
);

uniform mat4 u_view_projection;
void main()
{
    gl_Position = u_view_projection * vec4(positions[gl_VertexID], 0.0, 1.0);
}