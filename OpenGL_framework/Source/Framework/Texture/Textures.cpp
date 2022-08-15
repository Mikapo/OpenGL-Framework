#include "Textures.h"

std::unique_ptr<OpenGL::Texture> OpenGL::Textures::load_texture_from_file(std::string_view file_path)
{
    Texture_buffer tex_buffer;
    tex_buffer.load_buffer_from_file(file_path);

    return create_texture(std::move(tex_buffer));
}

std::unique_ptr<OpenGL::Texture> OpenGL::Textures::create_texture_with_buffer(
    std::vector<unsigned char> buffer, int32_t tex_width, int32_t tex_height, int32_t tex_channels)
{
    Texture_buffer tex_buffer;
    tex_buffer.add_buffer(std::move(buffer), tex_width, tex_height, tex_channels);

    return create_texture(std::move(tex_buffer));
}

std::unique_ptr<OpenGL::Texture> OpenGL::Textures::create_texture(Texture_buffer buffer)
{
    return std::make_unique<Texture>(std::move(buffer));
}