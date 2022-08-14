#include "Math.h"

#include "glm/ext/matrix_transform.hpp"

glm::mat4 OpenGL::Math::calculate_rotation_matrix(glm::vec3 rotation)
{
    const glm::mat4 identity = glm::mat4(1);

    const glm::mat4 x_rotation = glm::rotate(identity, rotation.x, glm::vec3(1.0F, 0.0F, 0.0F));
    const glm::mat4 y_rotation = glm::rotate(identity, rotation.y, glm::vec3(0.0F, 1.0F, 0.0F));
    const glm::mat4 z_rotation = glm::rotate(identity, rotation.z, glm::vec3(0.0F, 0.0F, 1.0F));

    return x_rotation * y_rotation * z_rotation;
}

glm::mat4 OpenGL::Math::calculate_rotation_matrix(float rotation)
{
    return calculate_rotation_matrix(glm::vec3(0.0F, 0.0F, rotation));
}

glm::mat4 OpenGL::Math::calculate_scale_matrix(glm::vec3 scale)
{
    const glm::mat4 identity = glm::mat4(1);
    const glm::mat4 scale_mat = glm::scale(identity, scale);
    return scale_mat;
}

glm::mat4 OpenGL::Math::calculate_scale_matrix(glm::vec2 scale)
{
    return calculate_scale_matrix(glm::vec3(scale, 1.0F));
}

glm::mat4 OpenGL::Math::calculate_translate_matrix(glm::vec3 location)
{
    const glm::mat4 identity = glm::mat4(1);
    const glm::mat4 translate_mat = glm::translate(identity, location);
    return translate_mat;
}

glm::mat4 OpenGL::Math::calculate_translate_matrix(glm::vec2 location)
{
    return calculate_translate_matrix(glm::vec3(location, 0.0F));
}

glm::mat4 OpenGL::Math::calculate_model(glm::vec3 location, glm::vec3 rotation, glm::vec3 scale)
{
    const glm::mat4 translate_mat = calculate_translate_matrix(location);
    const glm::mat4 rotation_mat = calculate_rotation_matrix(rotation);
    const glm::mat4 scale_mat = calculate_scale_matrix(scale);

    return translate_mat * rotation_mat * scale_mat;
}

glm::mat4 OpenGL::Math::calculate_model(glm::vec2 location, float rotation, glm::vec2 scale)
{
    return calculate_model(glm::vec3(location, 0.0F), glm::vec3(0.0F, 0.0F, rotation), glm::vec3(scale, 1.0F));
}
