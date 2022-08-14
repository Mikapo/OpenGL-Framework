
#include "Shaders.h"
#include "Default_shaders/2d_shader.h"
#include "glm/ext/matrix_clip_space.hpp"
#include <fstream>
#include <sstream>

std::unique_ptr<OpenGL::Shader> OpenGL::Shaders::compile_default_shader()
{
    std::unique_ptr shader = compile_shader(Default_shader_2d::VERT_SHADER, Default_shader_2d::FRAG_SHADER);

    const glm::mat4 projection = glm::ortho(-1.0F, 1.0F, -1.0F, 1.0F);
    shader->set_uniform(Default_shader_2d::PROJECTION_UNIFORM, projection);

    return shader;
}

std::unique_ptr<OpenGL::Shader> OpenGL::Shaders::compile_shader_from_file(
    std::string_view vert_path, std::string_view frag_path)
{
    const std::string vert_source = parse_shader(vert_path);
    const std::string frag_source = parse_shader(frag_path);

    return compile_shader(vert_source, frag_source);
}

std::unique_ptr<OpenGL::Shader> OpenGL::Shaders::compile_shader(
    std::string_view vert_shader, std::string_view frag_shader)
{
    return std::make_unique<Shader>(vert_shader, frag_shader);
}

std::string OpenGL::Shaders::parse_shader(std::string_view file_path)
{
    std::ifstream file_stream(file_path.data());
    std::stringstream output_stream;
    std::string line;

    while (getline(file_stream, line))
        output_stream << line << '\n';

    return output_stream.str();
}
