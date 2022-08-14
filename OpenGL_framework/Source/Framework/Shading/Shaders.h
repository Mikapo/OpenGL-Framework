#pragma once

#include "Shader.h"
#include <memory>
#include <string>
#include <string_view>

namespace OpenGL
{
    class Shaders
    {
    public:
        Shaders() = delete;

        static std::unique_ptr<Shader> compile_default_shader();
        static std::unique_ptr<Shader> compile_shader_from_file(std::string_view vert_path, std::string_view frag_path);

    private:
        static std::unique_ptr<Shader> compile_shader(std::string_view vert_shader, std::string_view frag_shader);
        static std::string parse_shader(std::string_view file_path);
    };
} // namespace OpenGL
