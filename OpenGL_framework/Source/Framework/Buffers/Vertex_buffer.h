#pragma once

#include "../Renderer_item.h"
#include <utility>

namespace OpenGL
{
    class Vertex_buffer : public Renderer_item
    {
    public:
        Vertex_buffer(const void* data, ptrdiff_t size) noexcept;
        ~Vertex_buffer();
        Vertex_buffer(const Vertex_buffer&) = delete;
        Vertex_buffer(Vertex_buffer&&) = default;

        Vertex_buffer& operator=(const Vertex_buffer&) = delete;
        Vertex_buffer& operator=(Vertex_buffer&&) = delete;

        void bind() const noexcept;
        static void unbind() noexcept;
    };
} // namespace OpenGL
