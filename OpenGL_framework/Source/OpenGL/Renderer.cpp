#include "GL/glew.h"

#include "Buffers/Buffers.h"
#include "Renderer.h"
#include "Shading/Shader.h"

void OpenGL::Renderer::draw(const Buffers& buffers, const Shader& shader) noexcept
{
    buffers.bind();
    shader.bind();

    const auto indices_count = static_cast<GLsizei>(buffers.get_indices_count());
    glDrawElements(GL_TRIANGLES, indices_count, GL_UNSIGNED_INT, nullptr);
}
