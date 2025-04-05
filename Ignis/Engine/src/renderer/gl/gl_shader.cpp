#include "gl_shader.hpp"

#include <core/utils.hpp>
#include <core/logger.hpp>
#include <iostream>

#include <string>


class GLShader::Impl
{
public:
    std::vector<u32> shaders;
    std::unordered_map<const char *, i32> uniform_locations;
};

GLShader::GLShader()
    : m_impl(new GLShader::Impl())
{
}


void GLShader::create_program()
{
    m_program = glCreateProgram();
    LOG_TRACE("[Shader] program created");
}

u32 GLShader::create_shader(const char *filepath, ShaderType shader_type)
{
    const char *shader_source = read_file(filepath);
    u32 shader = glCreateShader(get_gl_shader_type(shader_type));

    glShaderSource(shader, 1, &shader_source, 0);
    return shader;
}

void GLShader::compile(u32 shader)
{
    glCompileShader(shader);

    int is_compiled = 0;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &is_compiled);
    if (is_compiled == GL_FALSE)
    {
        GLint max_length = 0;
        glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &max_length);

        char buffer[256];
        glGetShaderInfoLog(shader, max_length, &max_length, buffer);
        LOG_ERROR("Failed to compile shader: {}", buffer);
        glDeleteShader(shader);
        return;
    }

    glAttachShader(m_program, shader);

    m_impl->shaders.push_back(shader);
}

void GLShader::link()
{
    glLinkProgram(m_program);

    int is_linked = 0;
    glGetProgramiv(m_program, GL_LINK_STATUS, &is_linked);
    if (is_linked == GL_FALSE)
    {
        int max_length = 0;
        glGetProgramiv(m_program, GL_INFO_LOG_LENGTH, &max_length);

        char buffer[256];
        glGetProgramInfoLog(m_program, max_length, &max_length, buffer);
        LOG_ERROR("Failed to link shader: {}", buffer);

        glDeleteProgram(m_program);

        destroy_shaders();
    }

    for (auto &shader : m_impl->shaders)
    {
        glDetachShader(m_program, shader);
    }
}

void GLShader::destroy_shaders()
{
    for (auto &shader : m_impl->shaders)
    {
       glDeleteShader(shader); 
    }

    m_impl->shaders.clear();
}

void GLShader::destroy()
{
    destroy_shaders();

    if (m_program != 0) {
        glDeleteProgram(m_program);
        LOG_TRACE("[Shader] Program {} destroyed", m_program);
    }

    if (m_impl)
        delete m_impl;
}

void GLShader::use()
{
    glUseProgram(m_program);
}

void GLShader::set_uniform_int(const char *name, const i32 value, i32 count)
{
    glUniform1iv(get_uniform_location(name), count, &value);
}

void GLShader::set_uniform_float(const char *name, const f32 value, i32 count)
{
    glUniform1fv(get_uniform_location(name), count, &value);
}

void GLShader::set_uniform_vec2(const char *name, const glm::vec2 &value, i32 count)
{
    glUniform2fv(get_uniform_location(name), count, glm::value_ptr(value));
}

void GLShader::set_uniform_vec3(const char *name, const glm::vec3 &value, i32 count)
{
    glUniform3fv(get_uniform_location(name), count, glm::value_ptr(value));
}

void GLShader::set_uniform_vec4(const char *name, const glm::vec4 &value, i32 count)
{
    glUniform4fv(get_uniform_location(name), count, glm::value_ptr(value));
}

void GLShader::set_uniform_mat4(const char *name, const glm::mat4 &value, i32 count)
{
    glUniformMatrix4fv(get_uniform_location(name), count, false, glm::value_ptr(value));
}

i32 GLShader::get_uniform_location(const char *name)
{
    if (m_impl->uniform_locations.contains(name))
        return m_impl->uniform_locations[name];

    i32 location = glGetUniformLocation(m_program, name);
    if (location > -1)
    {
        m_impl->uniform_locations[name] = location;
        return location;
    }

    LOG_ERROR("[Shader] Failed to get uniform '{}'", name);
    return -1;
}