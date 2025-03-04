#pragma once
#include "math/math.hpp"
#include "gl_shader.hpp"
#include "gl_vertex_array.hpp"
#include "gl_vertex_buffer.hpp"
#include "gl_index_buffer.hpp"

struct QuadVertex
{
    glm::vec2 position;
    glm::vec2 texture_coord;
    glm::vec4 color;
};

struct GLR2DData
{
    // quad data
    Ref<GLVertexArray> quad_vertex_array;
    Ref<GLVertexBuffer> quad_vertex_buffer;
    QuadVertex* quad_vertex_buffer_base = nullptr;
    QuadVertex* quad_vertex_buffer_pointer = nullptr;
    glm::vec4 quad_vertex_positions[4];
    u32 quad_index_count = 0;
    Ref<GLShader> quad_shader;
    u32 quad_max_vertices = 1024;
};

struct GLR2D
{
    static void init();
    static void shutdown();

    static void start_batch();
    static void flush_batch();

    // drawing function
    static void draw_rect(const Rect& rect, const glm::vec4& color);

    static GLR2DData rdata;

};