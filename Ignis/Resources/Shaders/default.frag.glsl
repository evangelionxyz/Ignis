#version 450 core
layout (location = 0) out vec4 color;

layout(location = 0) in Vertex
{
    vec2 position;
    vec2 texture_coord;
} vin;

uniform vec4 u_color;
uniform sampler2D u_texture;
void main()
{
    vec4 texture_color = texture(u_texture, vin.texture_coord);
    color = texture_color * u_color;
}