#include "Index_buffer.h"

#include "GL/glew.h"

OpenGL::Index_buffer::Index_buffer(const void* data, size_t count) noexcept : m_count(count)
{
    uint32_t buffer_id = 0;
    glGenBuffers(1, &buffer_id);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, buffer_id);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, static_cast<GLsizeiptr>(sizeof(uint32_t) * count), data, GL_STATIC_DRAW);
    set_id(buffer_id);
}

OpenGL::Index_buffer::~Index_buffer()
{
    const uint32_t buffer_id = get_id();
    glDeleteBuffers(1, &buffer_id);
}

void OpenGL::Index_buffer::bind() const noexcept
{
    const uint32_t buffer_id = get_id();
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, buffer_id);
}

void OpenGL::Index_buffer::unbind() noexcept
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

size_t OpenGL::Index_buffer::get_count() const noexcept
{
    return m_count;
}
