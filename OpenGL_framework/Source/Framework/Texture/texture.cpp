#include "GL/glew.h"

#include "Texture.h"
#include <stdexcept>
#include <string>

OpenGL::Texture::Texture(Texture_buffer buffer, Texture_slot slot) noexcept : m_buffer(std::move(buffer)), m_slot(slot)
{
}

OpenGL::Texture::~Texture()
{
    const uint32_t texture_id = get_id();
    glDeleteTextures(1, &texture_id);
}

void OpenGL::Texture::bind() const noexcept
{
    glActiveTexture(GL_TEXTURE0 + static_cast<uint8_t>(m_slot));
    glBindTexture(GL_TEXTURE_2D, get_id());
}

void OpenGL::Texture::unbind() const noexcept
{
    glActiveTexture(GL_TEXTURE0 + static_cast<uint8_t>(m_slot));
    glBindTexture(GL_TEXTURE_2D, 0);
}

uint32_t OpenGL::Texture::construct_item()
{
    uint32_t texture_id = 0;
    glGenTextures(1, &texture_id);
    glBindTexture(GL_TEXTURE_2D, texture_id);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    int32_t width = 0, height = 0;
    m_buffer.get_dimensions(width, height);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, m_buffer.get_buffer().data());

    glGenerateMipmap(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, 0);

    return texture_id;
}
