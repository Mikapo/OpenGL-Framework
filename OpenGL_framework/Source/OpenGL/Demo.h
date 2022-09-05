#pragma once

#include "Application/Application.h"
#include "Buffers/Buffers.h"
#include "Shading/Shader.h"
#include "Texture/Textures.h"
#include <memory>

namespace OpenGL
{
    class Demo
    {
    public:
        void run();

    private:
        void on_window_open();
        void render();

        Application application;

        // Different objects used for rendering
        std::unique_ptr<Buffers> m_square_buffers = nullptr;
        std::unique_ptr<Buffers> m_triangle_buffers = nullptr;
        std::unique_ptr<Shader> m_shader = nullptr;
        std::unique_ptr<Texture> m_texture = nullptr;
    };
} // namespace OpenGL
