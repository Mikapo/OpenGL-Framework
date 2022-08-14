#pragma once

namespace OpenGL
{
    class Buffers;
    class Shader;

    class Renderer
    {
    public:
        static void draw(Buffers& buffers, const Shader& shader);
    };
} // namespace OpenGL
