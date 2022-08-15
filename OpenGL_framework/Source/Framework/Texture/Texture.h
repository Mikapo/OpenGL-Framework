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
        Texture(Texture_buffer buffer, Texture_slot slot) noexcept;
        ~Texture() override;
        Texture(const Texture&) = delete;
        Texture(Texture&&) = delete;

        Texture& operator=(const Texture&) = delete;
        Texture& operator=(Texture&&) = delete;

        void bind() const noexcept override;
        void unbind() const noexcept override;

    private:
        [[nodiscard]] uint32_t construct_item() override;

        Texture_buffer m_buffer;
        Texture_slot m_slot = Texture_slot::color;
    };
} // namespace OpenGL
