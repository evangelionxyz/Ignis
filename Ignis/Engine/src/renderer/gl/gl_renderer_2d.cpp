#include "gl_renderer_2d.hpp"

GLR2DData GLR2D::rdata;

void GLR2D::init()
{
    rdata.quad_vertex_buffer_base = new QuadVertex[rdata.quad_max_vertices];
    rdata.quad_vertex_array = GLVertexArray::create();
    rdata.quad_vertex_buffer = GLVertexBuffer::create(rdata.quad_max_vertices * sizeof(QuadVertex);
    rdata.quad_vertex_buffer->set_layout({
        {ShaderDataType_Float2, "position"},
        {ShaderDataType_Float2, "texture_coord"},
        {ShaderDataType_Float4, "color"}
    });

    rdata.quad_vertex_array->add_vertex_buffer(rdata.quad_vertex_buffer);

    u32 quad_indices = new u32[]
}

void GLR2D::shutdown()
{
    
}

void GLR2D::start_batch()
{
    
}
void GLR2D::flush_batch()
{
    
}

// drawing function
void GLR2D::draw_rect(const Rect& rect, const glm::vec4& color)
{
    
}