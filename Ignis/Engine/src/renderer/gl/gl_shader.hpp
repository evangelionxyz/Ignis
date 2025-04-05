#include "core/object.hpp"

#include <glad/glad.h>
#include <stdint.h>
#include <string>

#include <vector>
#include <unordered_map>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

enum ShaderType
{
    SHADER_TYPE_UNKNOWN,
    SHADER_TYPE_VERTEX,
    SHADER_TYPE_FRAGMENT,
    SHADER_TYPE_COMPUTE,
    SHADER_TYPE_GEOMETRY
};

static GLenum get_gl_shader_type(ShaderType shader_type)
{
    switch (shader_type)
    {
        case SHADER_TYPE_VERTEX: return GL_VERTEX_SHADER;
        case SHADER_TYPE_FRAGMENT: return GL_FRAGMENT_SHADER;
        case SHADER_TYPE_COMPUTE: return GL_COMPUTE_SHADER;
        case SHADER_TYPE_GEOMETRY: return GL_GEOMETRY_SHADER;
    }

    return SHADER_TYPE_UNKNOWN;
}

class IGNIS_API GLShader : public Object
{
public:
    GLShader();

   u32 create_shader(const char *filepath, ShaderType shader_type);

    void create_program();
    void compile(u32 shader);
    void link();
    void use();

    void destroy_shaders();

    void set_uniform_int(const char *name, const i32 value, i32 count = 1);
    void set_uniform_float(const char *name, const f32 value, i32 count = 1);
    void set_uniform_vec2(const char *name, const glm::vec2 &value, i32 count = 1);
    void set_uniform_vec3(const char *name, const glm::vec3 &value, i32 count = 1);
    void set_uniform_vec4(const char *name, const glm::vec4 &value, i32 count = 1);
    void set_uniform_mat4(const char *name, const glm::mat4 &value, i32 count = 1);

    virtual void destroy() override;
    i32 get_uniform_location(const char *name);

private:
    class Impl;
    Impl *m_impl;
    u32 m_program;
};