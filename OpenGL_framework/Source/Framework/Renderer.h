#pragma once

namespace OpenGL
{
    class Buffers;
    class Shader;

    class Renderer
    {
    public:
        Renderer() = delete;

        static void draw(const Buffers& buffers, const Shader& shader) noexcept;
    };
} // namespace OpenGL
