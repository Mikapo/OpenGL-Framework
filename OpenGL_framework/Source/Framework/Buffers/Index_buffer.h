#pragma once

#include "../Renderer_item.h"
#include <cstdint>

namespace OpenGL
{
    class Index_buffer : public Renderer_item
    {
    public:
        Index_buffer(const void* data, size_t count) noexcept;
        ~Index_buffer();
        Index_buffer(const Index_buffer&) = delete;
        Index_buffer(Index_buffer&&) = default;

        Index_buffer& operator=(const Index_buffer&) = delete;
        Index_buffer& operator=(Index_buffer&&) = delete;

        void bind() const noexcept;
        static void unbind() noexcept;
        [[nodiscard]] size_t get_count() const noexcept;

    private:
        size_t m_count;
    };
} // namespace OpenGL
