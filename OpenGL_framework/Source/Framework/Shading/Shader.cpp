#include "Shader.h"

#include <fstream>
#include <iostream>
#include <sstream>

#include "GL/glew.h"
#include <GLFW/glfw3.h>

OpenGL::Shader::Shader(std::string_view vert_shader, std::string_view frag_shader)
    : m_shader_id(create_shader(vert_shader, frag_shader))
{
    glUseProgram(m_shader_id);
}

OpenGL::Shader::~Shader()
{
    glDeleteProgram(m_shader_id);
}

void OpenGL::Shader::bind() const noexcept
{
    glUseProgram(m_shader_id);
}

void OpenGL::Shader::unbind() noexcept
{
    glUseProgram(0);
}

void OpenGL::Shader::set_sampler_uniform(std::string_view name, Texture_slot slot)
{
    set_uniform(name, static_cast<int32_t>(slot));
}

void OpenGL::Shader::call_gl_uniform(int32_t pos, float value1, float value2, float value3, float value4) noexcept
{
    glUniform4f(pos, value1, value2, value3, value4);
}

void OpenGL::Shader::call_gl_uniform(
    int32_t pos, int32_t count, const std::vector<std::array<float, 4>>& array) noexcept
{
    glUniform4fv(pos, static_cast<GLsizei>(count), array.data()->data());
}

void OpenGL::Shader::call_gl_uniform(int32_t pos, float value1, float value2, float value3) noexcept
{
    glUniform3f(pos, value1, value2, value3);
}

void OpenGL::Shader::call_gl_uniform(
    int32_t pos, int32_t count, const std::vector<std::array<float, 3>>& array) noexcept
{
    glUniform3fv(pos, static_cast<GLsizei>(count), array.data()->data());
}

void OpenGL::Shader::call_gl_uniform(int32_t pos, float value1, float value2) noexcept
{
    glUniform2f(pos, value1, value2);
}

void OpenGL::Shader::call_gl_uniform(int32_t pos, float value) noexcept
{
    glUniform1f(pos, value);
}

void OpenGL::Shader::call_gl_uniform(int32_t pos, int32_t value) noexcept
{
    glUniform1i(pos, value);
}

void OpenGL::Shader::call_gl_uniform(int32_t pos, bool value) noexcept
{
    glUniform1i(pos, static_cast<GLint>(value));
}

void OpenGL::Shader::call_gl_uniform(int32_t pos, const glm::mat4& matrix) noexcept
{
    glUniformMatrix4fv(pos, 1, GL_FALSE, &matrix[0][0]);
}

int32_t OpenGL::Shader::get_uniform_location(std::string_view name)
{
    if (m_uniform_location_cache.contains(name))
        return m_uniform_location_cache[name];

    int32_t location = glGetUniformLocation(m_shader_id, name.data());
    m_uniform_location_cache[name] = location;
    return location;
}

uint32_t OpenGL::Shader::compile_shader(uint32_t type, std::string_view source)
{
    const uint32_t Shader_id = glCreateShader(type);
    const char* src = source.data();
    glShaderSource(Shader_id, 1, &src, nullptr);
    glCompileShader(Shader_id);

    int32_t result = 0;
    glGetShaderiv(Shader_id, GL_COMPILE_STATUS, &result);
    if (result == GL_FALSE)
    {
        int32_t lenght = 0;
        glGetShaderiv(Shader_id, GL_INFO_LOG_LENGTH, &lenght);

        std::vector<char> message_buffer;
        message_buffer.resize(lenght);

        glGetShaderInfoLog(Shader_id, lenght, &lenght, message_buffer.data());
        glDeleteShader(Shader_id);

        throw std::invalid_argument(message_buffer.data());
    }

    return Shader_id;
}

uint32_t OpenGL::Shader::create_shader(std::string_view vertex_shader, std::string_view fragment_shader)
{
    const uint32_t vertex_shader_id = compile_shader(GL_VERTEX_SHADER, vertex_shader);
    const uint32_t fragment_shader_id = compile_shader(GL_FRAGMENT_SHADER, fragment_shader);
    const uint32_t program = glCreateProgram();

    glAttachShader(program, vertex_shader_id);
    glAttachShader(program, fragment_shader_id);
    glLinkProgram(program);
    glValidateProgram(program);

    glDeleteShader(vertex_shader_id);
    glDeleteShader(fragment_shader_id);

    return program;
}
