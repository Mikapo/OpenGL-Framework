#include "Renderer_item.h"

#include <utility>

OpenGL::Renderer_item::Renderer_item(Renderer_item&& other) noexcept
{
    *this = std::move(other);
}

OpenGL::Renderer_item& OpenGL::Renderer_item::operator=(Renderer_item&& other) noexcept
{
    m_id = other.m_id;
    m_is_valid = other.m_is_valid;

    other.m_id = 0;
    other.m_is_valid = false;

    return *this;
}

bool OpenGL::Renderer_item::is_valid() const noexcept
{
    return m_is_valid;
}

void OpenGL::Renderer_item::set_id(uint32_t new_id) noexcept
{
    m_id = new_id;
}

uint32_t OpenGL::Renderer_item::get_id() const noexcept
{
    return m_id;
}
