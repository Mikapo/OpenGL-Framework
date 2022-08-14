#pragma once

namespace OpenGL
{
    namespace Default_shader_2d
    {
        constexpr const char* FRAG_SHADER = R"(
        #version 330 core

        layout(location = 0) out vec4 out_frag_color;

        uniform vec4 u_color = vec4(0.9f, 0.9f, 0.9f, 1.0f);

        void main() 
        {     
            out_frag_color = u_color;
        })";

        constexpr const char* VERT_SHADER = R"(
        #version 330 core

        layout (location = 0) in vec3 l_position;

        uniform mat4 u_projection = mat4(1);
        uniform mat4 u_model = mat4(1);

        void main()
        {
            gl_Position = u_projection * u_model * vec4(l_position, 1);
        })";

        constexpr const char* PROJECTION_UNIFORM = "u_projection";
        constexpr const char* MODEL_UNIFORM = "u_model";
        constexpr const char* COLOR_UNIFORM = "u_color";
    } // namespace Default_shader_2d
} // namespace OpenGL
