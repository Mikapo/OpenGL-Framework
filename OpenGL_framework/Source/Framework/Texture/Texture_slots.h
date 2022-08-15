#pragma once

#include <cstdint>

namespace OpenGL
{
    enum class Texture_slot : uint8_t
    {
        texture = 0,
        shadow_map = 1
    };
} // namespace OpenGL
