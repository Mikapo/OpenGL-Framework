#include "GL/glew.h"

#include "Shader.h"
#include "Shadow_map.h"
#include <stdexcept>

OpenGL::Shadow_map::~Shadow_map()
{
    if (m_has_been_initialized)
        glDeleteTextures(1, &m_depth_map_id);
}

void OpenGL::Shadow_map::init(std::unique_ptr<Shader> shadow_map_shader, int32_t shadow_width, int32_t shadow_height)
{
    if (m_has_been_initialized)
        throw std::logic_error("Shadow map has been already initialized");

    m_shadow_width = shadow_width;
    m_shadow_height = shadow_height;

    m_shader = std::move(shadow_map_shader);
    m_depth_map_id = create_depth_map_texture(shadow_width, shadow_height);
    initialize_frame_buffer(m_depth_map_id);
    m_has_been_initialized = true;
}

uint32_t OpenGL::Shadow_map::create_depth_map_texture(int32_t shadow_width, int32_t shadow_height) noexcept
{
    uint32_t depth_map = 0;
    glGenTextures(1, &depth_map);
    glBindTexture(GL_TEXTURE_2D, depth_map);
    glTexImage2D(
        GL_TEXTURE_2D, 0, GL_DEPTH_COMPONENT, shadow_width, shadow_height, 0, GL_DEPTH_COMPONENT, GL_FLOAT, nullptr);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_COMPARE_MODE, GL_COMPARE_REF_TO_TEXTURE);
    glBindTexture(GL_TEXTURE_2D, 0);
    return depth_map;
}

void OpenGL::Shadow_map::initialize_frame_buffer(uint32_t depth_map)
{
    m_frame_buffer.initialize();
    m_frame_buffer.bind();

    glFramebufferTexture2D(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_TEXTURE_2D, depth_map, 0);
    glDrawBuffer(GL_NONE);
    glReadBuffer(GL_NONE);

    m_frame_buffer.unbind();
}

void OpenGL::Shadow_map::bind_frame_buffer() const noexcept
{
    m_frame_buffer.bind();
}

void OpenGL::Shadow_map::unbind_frame_buffer() noexcept
{
    m_frame_buffer.unbind();
}

void OpenGL::Shadow_map::bind_depth_map(Texture_slot slot) const noexcept
{
    glActiveTexture(GL_TEXTURE0 + static_cast<int32_t>(slot));
    glBindTexture(GL_TEXTURE_2D, m_depth_map_id);
}

void OpenGL::Shadow_map::unbind_depth_map() noexcept
{
    glBindTexture(GL_TEXTURE_2D, 0);
}

OpenGL::Shader* OpenGL::Shadow_map::get_shader() const noexcept
{
    return m_shader.get();
}

void OpenGL::Shadow_map::get_shadow_resolution(int32_t& out_width, int32_t& out_height) const noexcept
{
    out_width = m_shadow_width;
    out_height = m_shadow_height;
}
