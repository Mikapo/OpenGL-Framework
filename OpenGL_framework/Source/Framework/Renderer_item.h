#pragma once

#include <cstdint>

namespace OpenGL
{
    class Renderer_item
    {
    public:
        virtual ~Renderer_item() = default;

        Renderer_item(const Renderer_item&) = delete;
        Renderer_item(Renderer_item&& other) noexcept;

        Renderer_item& operator=(const Renderer_item&) = delete;
        Renderer_item& operator=(Renderer_item&& other) noexcept;

        [[nodiscard]] bool is_valid() const noexcept;

    protected:
        Renderer_item() = default;

        void set_id(uint32_t new_id) noexcept;
        [[nodiscard]] uint32_t get_id() const noexcept;

    private:
        bool m_is_valid = true;
        uint32_t m_id = 0;
    };

} // namespace OpenGL
