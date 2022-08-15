#pragma once

#include "../Renderer_item.h"

#include "Texture_buffer.h"
#include "Texture_slots.h"
#include <string>
#include <utility>

namespace OpenGL
{
    class Texture : public Renderer_item
    {
    public:
        Texture(Texture_buffer buffer);
        ~Texture() override;
        Texture(const Texture&) = delete;
        Texture(Texture&&) = default;

        Texture& operator=(const Texture&) = delete;
        Texture& operator=(Texture&&) = delete;

        void bind(Texture_slot slot) noexcept;
        void unbind() noexcept;
        [[nodiscard]] bool has_local_buffer() const noexcept;

    private:
        void initialize() noexcept;

        Texture_buffer m_buffer;
        bool m_has_been_initialized = false;
        bool m_is_binded = false;
        int32_t m_current_slot = -1;
    };
} // namespace OpenGL
