#include "GL/glew.h"

#include "Buffers/Buffers.h"
#include "Renderer.h"
#include "Shading/Shader.h"

void OpenGL::Renderer::draw(Buffers& buffers, const Shader& shader)
{
    buffers.bind();
    shader.bind();

    const auto indices_count = static_cast<GLsizei>(buffers.get_indices_count());
    glDrawElements(GL_TRIANGLES, indices_count, GL_UNSIGNED_INT, nullptr);
}
