#pragma once

#include "Index_buffer.h"
#include "Vertex_array.h"
#include "Vertex_buffer.h"
#include "Vertex_buffer_layout.h"
#include <memory>
#include <vector>

namespace OpenGL
{
    class Buffers
    {
    public:
        Buffers(std::vector<float> vertices, std::vector<uint32_t> indices, Vertex_buffer_layout layout);

        void bind();
        void unbind() const noexcept;
        [[nodiscard]] size_t get_indices_count() const noexcept;

    private:
        void initialize();

        bool m_has_been_initialized = false;
        std::vector<float> m_vertices;
        std::vector<uint32_t> m_indices;
        Vertex_buffer_layout m_layout;
        size_t m_indices_amount = 0;

        std::unique_ptr<Vertex_buffer> m_vb;
        std::unique_ptr<Vertex_array> m_va;
        std::unique_ptr<Index_buffer> m_ib;
    };
} // namespace OpenGL
