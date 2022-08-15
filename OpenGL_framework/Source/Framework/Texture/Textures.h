#pragma once

#include "Texture.h"
#include <memory>

namespace OpenGL
{
    class Textures
    {
    public:
        static std::unique_ptr<Texture> load_texture_from_file(std::string_view file_path);
        static std::unique_ptr<Texture> create_texture_with_buffer(
            std::vector<unsigned char> buffer, int32_t tex_width, int32_t tex_height, int32_t tex_channels);

    private:
        static std::unique_ptr<Texture> create_texture(Texture_buffer buffer);
    };
} // namespace OpenGL