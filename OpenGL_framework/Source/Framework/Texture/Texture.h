#pragma once

#include "../Renderer_item.h"

#include "GL/glew.h"
#include "Texture_slots.h"
#include <string>
#include <utility>

namespace OpenGL
{
    class Texture : public Renderer_item
    {
    public:
        Texture(std::string_view path);
        ~Texture() override;
        Texture(const Texture&) = delete;
        Texture(Texture&&) = default;

        Texture& operator=(const Texture&) = delete;
        Texture& operator=(Texture&&) = delete;

        void bind(Texture_slot slot) noexcept;
        void unbind() noexcept;
        [[nodiscard]] int32_t get_width() const noexcept;
        [[nodiscard]] bool has_local_buffer() const noexcept;

    private:
        void initialize() noexcept;
        void release_local_buffer() noexcept;

        bool m_has_been_initialized = false;
        std::string m_filepath;
        bool m_is_binded = false;
        int32_t m_current_slot = -1;
        unsigned char* m_local_buffer = nullptr;
        int32_t m_width = 0, m_height = 0, m_bpp = 0;
    };
} // namespace OpenGL
