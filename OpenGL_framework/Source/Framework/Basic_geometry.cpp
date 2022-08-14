#include "Basic_geometry.h"

std::unique_ptr<OpenGL::Buffers> OpenGL::Basic_geometry::create_square_buffers()
{
    Vertex_buffer_layout layout;
    layout.push<float>(2);

    constexpr float radius = 0.5F;
    std::vector<float> square_vertices = {-radius, -radius, radius, -radius, radius, radius, -radius, radius};
    std::vector<uint32_t> square_indices = {0, 1, 2, 0, 2, 3};

    return create_buffers(std::move(square_vertices), std::move(square_indices), std::move(layout));
}

std::unique_ptr<OpenGL::Buffers> OpenGL::Basic_geometry::create_triangle_buffers()
{
    Vertex_buffer_layout layout;
    layout.push<float>(2);

    constexpr float height = 0.5F;
    std::vector<float> triangle_vertices = {-height, -height, height, -height, 0.0F};
    std::vector<uint32_t> triangle_indices = {0, 1, 2};

    return create_buffers(std::move(triangle_vertices), std::move(triangle_indices), std::move(layout));
}

std::unique_ptr<OpenGL::Buffers> OpenGL::Basic_geometry::create_buffers(
    std::vector<float> vertices, std::vector<uint32_t> indices, Vertex_buffer_layout layout)
{
    return std::make_unique<Buffers>(std::move(vertices), std::move(indices), std::move(layout));
}
