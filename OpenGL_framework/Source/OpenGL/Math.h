#pragma once

#include "glm/mat4x4.hpp"
#include "glm/vec2.hpp"
#include "glm/vec3.hpp"

namespace OpenGL
{
    class Math
    {
    public:
        Math() = delete;

        [[nodiscard]] static glm::mat4 calculate_rotation_matrix(glm::vec3 rotation);
        [[nodiscard]] static glm::mat4 calculate_rotation_matrix(float rotation);

        [[nodiscard]] static glm::mat4 calculate_scale_matrix(glm::vec3 scale);
        [[nodiscard]] static glm::mat4 calculate_scale_matrix(glm::vec2 scale);

        [[nodiscard]] static glm::mat4 calculate_translate_matrix(glm::vec3 location);
        [[nodiscard]] static glm::mat4 calculate_translate_matrix(glm::vec2 location);

        [[nodiscard]] static glm::mat4 calculate_model(
            glm::vec3 location, glm::vec3 rotation = {0.0f, 0.0f, 0.0f}, glm::vec3 scale = {1.0f, 1.0f, 1.0f});
        [[nodiscard]] static glm::mat4 calculate_model(
            glm::vec2 location, float rotation = 0.0f, glm::vec2 scale = {1.0f, 1.0f});
    };
} // namespace OpenGL
