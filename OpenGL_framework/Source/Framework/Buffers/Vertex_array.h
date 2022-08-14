#pragma once

#include "../Renderer_item.h"
#include <utility>

namespace OpenGL
{
    class Vertex_array : public Renderer_item
    {
    public:
        Vertex_array() noexcept;
        ~Vertex_array() override;
        Vertex_array(const Vertex_array&) = delete;
        Vertex_array(Vertex_array&&) = default;

        Vertex_array& operator=(const Vertex_array&) = delete;
        Vertex_array& operator=(Vertex_array&&) = delete;

        void add_buffer(const class Vertex_buffer& vertex_buffer, const class Vertex_buffer_layout& layout) const;
        void bind() const noexcept;
        static void unbind() noexcept;
    };
} // namespace OpenGL
