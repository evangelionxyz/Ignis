#include "shader.hpp"

#include <core/utils.hpp>
#include <iostream>

void Shader::create_program()
{
    m_program = glCreateProgram();
}

uint32_t Shader::create_shader(const std::string &filepath, ShaderType shader_type)
{
    std::string shader_source = read_file(filepath);
    uint32_t shader = glCreateShader(get_gl_shader_type(shader_type));

    const char *source_ptr = shader_source.c_str();
    glShaderSource(shader, 1, &source_ptr, 0);
    return shader;
}

void Shader::compile(uint32_t shader)
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
        std::cout << buffer << '\n';
        glDeleteShader(shader);

        return;
    }

    glAttachShader(m_program, shader);

    m_shaders.push_back(shader);
}

void Shader::link()
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

        glDeleteProgram(m_program);

        destroy_shaders();
    }

    for (auto &shader : m_shaders)
    {
        glDetachShader(m_program, shader);
    }
}

void Shader::destroy_shaders()
{
    for (auto &shader : m_shaders)
    {
       glDeleteShader(shader); 
    }

    m_shaders.clear();
}

void Shader::destroy()
{
    destroy_shaders();

    if (m_program != 0)
        glDeleteProgram(m_program);
}

void Shader::use()
{
    glUseProgram(m_program);
}

void Shader::set_uniform_int(const std::string &name, const i32 value, i32 count)
{
    glUniform1iv(get_uniform_location(name), count, &value);
}

void Shader::set_uniform_float(const std::string &name, const f32 value, i32 count)
{
    glUniform1fv(get_uniform_location(name), count, &value);
}

void Shader::set_uniform_vec2(const std::string &name, const glm::vec2 &value, i32 count)
{
    glUniform2fv(get_uniform_location(name), count, glm::value_ptr(value));
}

void Shader::set_uniform_vec3(const std::string &name, const glm::vec3 &value, i32 count)
{
    glUniform3fv(get_uniform_location(name), count, glm::value_ptr(value));
}

void Shader::set_uniform_vec4(const std::string &name, const glm::vec4 &value, i32 count)
{
    glUniform4fv(get_uniform_location(name), count, glm::value_ptr(value));
}

void Shader::set_uniform_mat4(const std::string &name, const glm::mat4 &value, i32 count)
{
    glUniformMatrix4fv(get_uniform_location(name), count, false, &value[0][0]);
}

i32 Shader::get_uniform_location(const std::string &name)
{
    if (m_uniform_locations.contains(name))
        return m_uniform_locations[name];

    i32 location = glGetUniformLocation(m_program, name.c_str());
    if (location > -1)
    {
        m_uniform_locations[name] = location;
        return location;
    }
    
    return -1;
}