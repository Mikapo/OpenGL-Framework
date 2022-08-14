#include "Buffers.h"

OpenGL::Buffers::Buffers(std::vector<float> vertices, std::vector<uint32_t> indices, Vertex_buffer_layout layout)
    : m_vertices(std::move(vertices)),
      m_indices(std::move(indices)),
      m_layout(std::move(layout)),
      m_indices_amount(m_indices.size())
{
}

void OpenGL::Buffers::bind()
{
    if (!m_has_been_initialized)
        initialize();

    m_va->bind();
    m_ib->bind();
}

void OpenGL::Buffers::unbind() const noexcept
{
    if (!m_has_been_initialized)
        return;

    Vertex_array::unbind();
    Index_buffer::unbind();
}

size_t OpenGL::Buffers::get_indices_count() const noexcept
{
    return m_indices_amount;
}

void OpenGL::Buffers::initialize()
{
    if (m_has_been_initialized)
        return;

    m_vb = std::make_unique<Vertex_buffer>(m_vertices.data(), sizeof(float) * m_vertices.size());
    m_va = std::make_unique<Vertex_array>();
    m_va->add_buffer(*m_vb, m_layout);
    m_ib = std::make_unique<Index_buffer>(m_indices.data(), m_indices.size());

    m_vertices.clear();
    m_indices.clear();

    m_has_been_initialized = true;
}
