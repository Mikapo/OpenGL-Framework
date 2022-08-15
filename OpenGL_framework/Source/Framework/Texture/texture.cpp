#include "GL/glew.h"

#include "Texture.h"
#include <stdexcept>
#include <string>

OpenGL::Texture::Texture(Texture_buffer buffer) : m_buffer(std::move(buffer))
{
}

OpenGL::Texture::~Texture()
{
    if (is_valid())
    {
        const uint32_t texture_id = get_id();
        glDeleteTextures(1, &texture_id);
    }
}

void OpenGL::Texture::bind(Texture_slot slot) noexcept
{
    if (!m_has_been_initialized)
    {
        initialize();
    }

    m_is_binded = true;
    m_current_slot = GL_TEXTURE0 + static_cast<int32_t>(slot);
    glActiveTexture(m_current_slot);
    glBindTexture(GL_TEXTURE_2D, get_id());
}

void OpenGL::Texture::unbind() noexcept
{
    if (!m_is_binded)
        return;

    glActiveTexture(m_current_slot);
    glBindTexture(GL_TEXTURE_2D, 0);
    m_current_slot = -1;
    m_is_binded = false;
}

bool OpenGL::Texture::has_local_buffer() const noexcept
{
    return m_buffer.has_buffer();
}

void OpenGL::Texture::initialize() noexcept
{
    if (has_local_buffer())
    {
        uint32_t texture_id = 0;
        glGenTextures(1, &texture_id);
        set_id(texture_id);
        glBindTexture(GL_TEXTURE_2D, texture_id);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

        int32_t width = 0, height = 0;
        m_buffer.get_dimensions(width, height);

        glTexImage2D(
            GL_TEXTURE_2D, 0, GL_RGBA8, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, m_buffer.get_buffer().data());

        glGenerateMipmap(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, 0);
        m_has_been_initialized = true;
    }
}
