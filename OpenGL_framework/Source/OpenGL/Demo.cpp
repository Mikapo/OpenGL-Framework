#include "Demo.h"

#include "Basic_geometry.h"
#include "Math.h"
#include "Renderer.h"
#include "Shading/Default_shaders/2d_shader.h"
#include "Shading/Shaders.h"
#include "glm/ext/matrix_clip_space.hpp"

void OpenGL::Demo::run()
{
    // Settupping application and starting it
    application.m_on_window_open.set_callback(this, &Demo::on_window_open);
    application.m_on_render.set_callback(this, &Demo::render);
    application.set_window_title("Demo");
    application.start();
}

void OpenGL::Demo::on_window_open()
{
    /*
    You can only use OpenGL after window has been created
    And only in thread where you started application
     */

    // Creating Buffers to render
    m_square_buffers = Basic_geometry::create_square_buffers();
    m_triangle_buffers = Basic_geometry::create_triangle_buffers();

    // Compiling shader and setting projection matrix on it
    m_shader = Shaders::compile_default_shader();
    m_shader->set_uniform(Default_shader_2d::Uniforms::PROJECTION, glm::ortho(-1.0F, 1.0F, -1.0F, 1.0F));

    // Loading examble texture and binding it
    m_texture = Textures::load_texture_from_file("Test_texture.png", Texture_slot::color);
    m_texture->bind();
}

void OpenGL::Demo::render()
{
    // OpenGL logo render
    glm::mat4 model = Math::calculate_model({0.4F, 0.4F}, 45.0F, {1.0F, 0.5F});
    m_shader->set_uniform(Default_shader_2d::Uniforms::MODEL, model);
    m_shader->set_uniform(Default_shader_2d::Uniforms::USES_TEXTURE, 1);
    m_shader->set_sampler_uniform(Default_shader_2d::Uniforms::TEXTURE, Texture_slot::color);

    Renderer::draw(*m_square_buffers, *m_shader);

    // Triangle render
    model = Math::calculate_model({-0.3F, -0.3F});
    m_shader->set_uniform(Default_shader_2d::Uniforms::MODEL, model);
    m_shader->set_uniform(Default_shader_2d::Uniforms::USES_TEXTURE, 0);
    m_shader->set_uniform(Default_shader_2d::Uniforms::COLOR, 1.0F, 0.0F, 0.0F, 1.0F);

    Renderer::draw(*m_triangle_buffers, *m_shader);
}
