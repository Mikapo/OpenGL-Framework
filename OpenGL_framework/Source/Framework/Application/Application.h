#pragma once

#define GLEW_STATIC

#include <GL/glew.h>

#include "Key.h"
#include <functional>
#include <memory>
#include <string>

struct GLFWwindow;

namespace OpenGL
{
    struct Window_background_color
    {
        float r = 0;
        float b = 0;
        float g = 0;
        float a = 0;
    };

    class Application
    {
    public:
        void start();

        template <typename Func_type>
        void set_on_window_open_callback(const Func_type& func)
        {
            m_on_window_open_callback = func;
        }

        template <typename Func_type>
        void set_render_callback(const Func_type& func)
        {
            m_render_callback = func;
        }

        template <typename Func_type>
        void set_cleanup_callback(const Func_type& func)
        {
            m_cleanup_callback = func;
        }

        template <typename Func_type>
        void set_on_key_event_callback(const Func_type& func)
        {
            m_on_key_event_callback = func;
        }

        template <typename Func_type>
        void set_window_resize_callback(const Func_type& func)
        {
            m_window_resize_callback = func;
        }

        [[nodiscard]] GLFWwindow* get_window() const noexcept;
        void get_window_dimensions(int32_t& out_width, int32_t& out_height) const noexcept;
        void set_window_dimensions(int32_t width, int32_t height) noexcept;
        void set_window_background_color(Window_background_color new_color) noexcept;

        // Needs to be called before start is called
        void set_window_title(std::string_view name);

    private:
        void setup_callbacks() const noexcept;
        static void setup_opengl_settings() noexcept;
        void init();
        void cleanup();
        void render_loop();

        // GLFW callbacks
        void on_window_resize(GLFWwindow* window, int32_t new_width, int32_t new_height);
        void on_key_event(int32_t key, int32_t scancode, int32_t action, int32_t mods);

        std::string m_name = "Window";
        int32_t m_width = 1000, m_height = 1000;
        Window_background_color m_background_color = {0.0F, 0.0F, 0.0F, 0.0F};

        GLFWwindow* m_window = nullptr;
        bool m_has_started = false;

        // Callbacks
        std::function<void(GLFWwindow*)> m_on_window_open_callback;
        std::function<void()> m_render_callback;
        std::function<void()> m_cleanup_callback;
        std::function<void(int32_t, int32_t)> m_window_resize_callback;
        std::function<void(Input_key, Input_action)> m_on_key_event_callback;
    };

} // namespace OpenGL
