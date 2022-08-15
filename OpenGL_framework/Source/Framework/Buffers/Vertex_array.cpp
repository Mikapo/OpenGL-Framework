#include "GL/glew.h"

#include "../layout/Vertex_buffer_layout.h"
#include "Vertex_array.h"
#include "Vertex_buffer.h"

OpenGL::Vertex_array::~Vertex_array()
{
    if (!has_been_initialized())
        return;

    const uint32_t array_id = get_id();
    glDeleteVertexArrays(1, &array_id);
}

void OpenGL::Vertex_array::add_buffer(const Vertex_buffer& vertex_buffer, const Vertex_buffer_layout& layout) const
{
    bind();
    vertex_buffer.bind();
    const auto& elements = layout.get_elements();
    uint32_t offset = 0;

    for (GLuint i = 0; i < elements.size(); i++)
    {
        const auto& element = elements.at(i);
        glEnableVertexAttribArray(i);

        glVertexAttribPointer(
            i, static_cast<GLint>(element.get_count()), element.get_type(), element.get_normalized(),
            static_cast<GLsizei>(layout.get_stride()), reinterpret_cast<const void*>(offset));

        offset += element.get_count() * Vertex_buffer_elements::get_size_of_type(element.get_type());
    }
}

void OpenGL::Vertex_array::bind() const noexcept
{
    glBindVertexArray(get_id());
}

void OpenGL::Vertex_array::unbind() const noexcept
{
    glBindVertexArray(0);
}

uint32_t OpenGL::Vertex_array::construct_item()
{
    uint32_t array_id = 0;
    glGenVertexArrays(1, &array_id);

    return array_id;
}
