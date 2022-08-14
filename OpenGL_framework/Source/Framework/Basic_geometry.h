#pragma once

#include "Buffers/Buffers.h"
#include <memory>
#include <vector>

namespace OpenGL
{
    class Vertex_buffer_layout;
    class Basic_geometry
    {
    public:
        Basic_geometry() = delete;

        [[nodiscard]] static std::unique_ptr<Buffers> create_square_buffers();
        [[nodiscard]] static std::unique_ptr<Buffers> create_triangle_buffers();

    private:
        [[nodiscard]] static std::unique_ptr<Buffers> create_buffers(
            std::vector<float> vertices, std::vector<uint32_t> indices, Vertex_buffer_layout layout);
    };
} // namespace OpenGL
