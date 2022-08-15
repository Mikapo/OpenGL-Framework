#include "GL/Glew.h"

#include "Vertex_buffer.h"

OpenGL::Vertex_buffer::Vertex_buffer(std::vector<float> buffer) noexcept : m_local_buffer(std::move(buffer))
{
}

OpenGL::Vertex_buffer::~Vertex_buffer()
{
    if (!has_been_initialized())
        return;

    const uint32_t id = get_id();
    glDeleteBuffers(1, &id);
}

void OpenGL::Vertex_buffer::bind() const noexcept
{
    glBindBuffer(GL_ARRAY_BUFFER, get_id());
}

void OpenGL::Vertex_buffer::unbind() const noexcept
{
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

uint32_t OpenGL::Vertex_buffer::construct_item()
{
    uint32_t id = 0;
    glGenBuffers(1, &id);
    glBindBuffer(GL_ARRAY_BUFFER, id);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * m_local_buffer.size(), m_local_buffer.data(), GL_STATIC_DRAW);

    m_local_buffer.clear();
    m_local_buffer.shrink_to_fit();

    return id;
}
