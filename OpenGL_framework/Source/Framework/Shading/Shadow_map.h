#pragma once

#include "../Buffers/Buffers.h"
#include "../Texture/Texture_slots.h"
#include "Shader.h"
#include <glm/mat4x4.hpp>
#include <memory>

namespace OpenGL
{
    class Shadow_map
    {
    public:
        Shadow_map() = default;
        ~Shadow_map();

        Shadow_map(const Shadow_map&) = delete;
        Shadow_map(const Shadow_map&&) = delete;
        Shadow_map& operator=(const Shadow_map&) = delete;
        Shadow_map& operator=(const Shadow_map&&) = delete;

        void init(std::unique_ptr<Shader> shadow_map_shader, int32_t shadow_width, int32_t shadow_height) noexcept;
        void cleanup() noexcept;
        void bind_frame_buffer() const noexcept;
        static void unbind_frame_buffer() noexcept;
        void bind_texture(Texture_slot slot) const noexcept;
        static void unbind_texture() noexcept;
        [[nodiscard]] Shader* get_shader() const noexcept;
        void get_shadow_resolution(int32_t& out_width, int32_t& out_height) const noexcept;

    private:
        [[nodiscard]] static uint32_t create_depth_map_texture(int32_t shadow_width, int32_t shadow_height) noexcept;
        [[nodiscard]] static uint32_t create_frame_buffer(uint32_t depth_map) noexcept;

        bool m_has_been_initialized = false;
        int32_t m_shadow_width = 0, m_shadow_height = 0;
        std::unique_ptr<Shader> m_shader = nullptr;
        uint32_t m_frame_buffer = 0;
        uint32_t m_depth_map = 0;
    };
} // namespace OpenGL
