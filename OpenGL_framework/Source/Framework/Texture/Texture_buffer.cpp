#include "Texture_buffer.h"

#include "stb_image/stb_Image.h"
#include <span>
#include <stdexcept>

void OpenGL::Texture_buffer::load_buffer_from_file(std::string_view path)
{
    stbi_set_flip_vertically_on_load(1);

    constexpr int32_t desired_channels = 4;
    unsigned char* texture_buffer = stbi_load(path.data(), &m_width, &m_height, &m_bpp, desired_channels);

    if (!texture_buffer)
        throw std::invalid_argument("Failed to load the texture");

    const size_t tex_buffer_size = m_width * m_height * desired_channels;
    const std::span tex_span = {texture_buffer, tex_buffer_size};

    m_buffer.resize(tex_buffer_size);
    std::copy(tex_span.begin(), tex_span.end(), m_buffer.begin());

    stbi_image_free(texture_buffer);
}

void OpenGL::Texture_buffer::add_buffer(
    std::vector<unsigned char> buffer, int32_t tex_width, int32_t tex_height, int32_t tex_channels) noexcept
{
    m_buffer = std::move(buffer);
    m_width = tex_width;
    m_height = tex_height;
    m_bpp = tex_channels;
}

void OpenGL::Texture_buffer::free_buffer()
{
    // frees buffer memory
    std::vector<unsigned char>().swap(m_buffer);
}

const std::vector<unsigned char>& OpenGL::Texture_buffer::get_buffer() const noexcept
{
    return m_buffer;
}

bool OpenGL::Texture_buffer::has_buffer() const noexcept
{
    return !m_buffer.empty();
}

void OpenGL::Texture_buffer::get_dimensions(int32_t& width, int32_t& height) const noexcept
{
    width = m_width;
    height = m_height;
}
