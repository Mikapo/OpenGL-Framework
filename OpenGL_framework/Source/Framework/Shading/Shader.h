#pragma once

#include "../Texture/Texture_slots.h"
#include <array>
#include <glm/matrix.hpp>
#include <string>
#include <unordered_map>
#include <vector>

namespace OpenGL
{
    class Shader
    {
    public:
        Shader(std::string_view fert_path, std::string_view frag_shader);
        ~Shader();
        Shader(const Shader&) = delete;
        Shader(Shader&&) = delete;

        Shader& operator=(const Shader&) = delete;
        Shader& operator=(Shader&&) = delete;

        void bind() const noexcept;
        static void unbind() noexcept;

        void set_sampler_uniform(std::string_view name, Texture_slot slot);

        template <typename... Types>
        void set_uniform(std::string_view name, Types... values)
        {
            const int32_t pos = get_uniform_location(name);

            if (pos != -1)
            {
                bind();
                call_gl_uniform(pos, std::forward<Types>(values)...);
            }
        }

    private:
        struct shader_source
        {
            std::string vertex_source;
            std::string fragment_source;
        };

        static void call_gl_uniform(int32_t pos, float value1, float value2, float value3, float value4) noexcept;
        static void call_gl_uniform(
            int32_t pos, int32_t count, const std::vector<std::array<float, 4>>& arrau) noexcept;
        static void call_gl_uniform(int32_t pos, float value1, float value2, float value3) noexcept;
        static void call_gl_uniform(
            int32_t pos, int32_t count, const std::vector<std::array<float, 3>>& array) noexcept;
        static void call_gl_uniform(int32_t pos, float value1, float value2) noexcept;
        static void call_gl_uniform(int32_t pos, float value) noexcept;
        static void call_gl_uniform(int32_t pos, int32_t value) noexcept;
        static void call_gl_uniform(int32_t pos, bool value) noexcept;
        static void call_gl_uniform(int32_t pos, const glm::mat4& matrix) noexcept;

        [[nodiscard]] static uint32_t create_shader(std::string_view vertex_shader, std::string_view fragment_shader);
        [[nodiscard]] static uint32_t compile_shader(uint32_t type, std::string_view source);
        [[nodiscard]] int32_t get_uniform_location(std::string_view name);

        uint32_t m_shader_id = 0;
        std::unordered_map<std::string_view, int32_t> m_uniform_location_cache;
    };
} // namespace OpenGL
