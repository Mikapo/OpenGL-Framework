#pragma once

#include <cstdint>
#include <string_view>
#include <vector>

namespace OpenGL
{
    class Texture_buffer
    {
    public:
        void load_buffer_from_file(std::string_view path);
        void add_buffer(
            std::vector<unsigned char> buffer, int32_t tex_width, int32_t tex_height, int32_t tex_channels) noexcept;

        void free_buffer();

        [[nodiscard]] const std::vector<unsigned char>& get_buffer() const noexcept;
        [[nodiscard]] bool has_buffer() const noexcept;
        void get_dimensions(int32_t& width, int32_t& height) const noexcept;

    private:
        int32_t m_width = 0, m_height = 0, m_bpp = 0;
        std::vector<unsigned char> m_buffer;
    };
} // namespace OpenGL
