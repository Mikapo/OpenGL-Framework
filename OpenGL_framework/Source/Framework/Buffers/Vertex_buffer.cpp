#include "Vertex_buffer.h"

#include "GL/Glew.h"

OpenGL::Vertex_buffer::Vertex_buffer(const void* data, ptrdiff_t size) noexcept
{
    uint32_t id = 0;
    glGenBuffers(1, &id);
    glBindBuffer(GL_ARRAY_BUFFER, id);
    glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
    set_id(id);
}

OpenGL::Vertex_buffer::~Vertex_buffer()
{
    if (is_valid())
    {
        const uint32_t id = get_id();
        glDeleteBuffers(1, &id);
    }
}

void OpenGL::Vertex_buffer::bind() const noexcept
{
    if (is_valid())
        glBindBuffer(GL_ARRAY_BUFFER, get_id());
}

void OpenGL::Vertex_buffer::unbind() noexcept
{
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}
