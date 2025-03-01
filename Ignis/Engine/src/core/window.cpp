#include "window.hpp"

#define STB_IMAGE_IMPLEMENTATION
#include "stbi_image.h"

#include "input/event.hpp"
#include "input/mouse_event.hpp"
#include "input/key_event.hpp"
#include "input/app_event.hpp"

#include <glad/gl.h>

Window::Window(const std::string& title, int width, int height)
    : m_title(title.c_str()), m_width(width), m_height(height)
{
	SDL_InitFlags init_flags = SDL_INIT_VIDEO | SDL_INIT_JOYSTICK | SDL_INIT_CAMERA | SDL_INIT_AUDIO | SDL_INIT_HAPTIC | SDL_INIT_GAMEPAD;
	SDL_Init(init_flags);

	SDL_WindowFlags window_flags = SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL;

	m_window = SDL_CreateWindow(title.c_str(), width, height, window_flags);
	SDL_ShowWindow(m_window);
	SDL_SetWindowPosition(m_window, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);

	// Load OpenGL
	m_gl_context = SDL_GL_CreateContext(m_window);
	gladLoadGL(SDL_GL_GetProcAddress);

	m_is_running = true;
}

void Window::destroy()
{
    SDL_GL_DestroyContext(m_gl_context);
	SDL_DestroyWindow(m_window);
	SDL_Quit();

	m_window = nullptr;
	m_gl_context = nullptr;
}

void Window::poll_events()
{
    SDL_Event event;
    SDL_PollEvent(&event);

    switch(event.type) {
    case SDL_EVENT_QUIT:
    {
        m_is_running = false;
        WindowCloseEvent ev;
        m_event_callback(ev);
        break;
    }
    case SDL_EVENT_WINDOW_PIXEL_SIZE_CHANGED:
    {
        m_fb_width = event.window.data1;
        m_fb_height = event.window.data2;

        FramebufferResizeEvent ev(m_fb_width, m_fb_height);
        m_event_callback(ev);
        break;
    }
    case SDL_EVENT_WINDOW_MOVED:
    {
        m_pos_x = event.window.data1;
        m_pos_y = event.window.data2;
        break;
    }
    case SDL_EVENT_KEY_DOWN:
    case SDL_EVENT_KEY_UP:
    {
        bool pressed = (event.key.type == SDL_EVENT_KEY_DOWN);
        if (pressed)
        {

            KeyPressedEvent ev(event.key.key, event.key.mod, 0);
            m_event_callback(ev);
        }
        else
        {
            KeyReleasedEvent ev(event.key.key, event.key.mod);
            m_event_callback(ev);
        }
        break;
    }
    case SDL_EVENT_TEXT_INPUT:
    {
        KeyTypedEvent ev(event.text.text[0]);
        m_event_callback(ev);
        break;
    }
    case SDL_EVENT_MOUSE_BUTTON_DOWN:
    {
        MouseButtonPressedEvent ev(event.button.button);
        m_event_callback(ev);
        break;
    }
    case SDL_EVENT_MOUSE_BUTTON_UP:
    {
        MouseButtonReleasedEvent ev(event.button.button);
        m_event_callback(ev);
        break;
    }
    case SDL_EVENT_MOUSE_WHEEL:
    {
        MouseScrolledEvent ev(event.wheel.x, event.wheel.y);
        m_event_callback(ev);
        break;
    }
    case SDL_EVENT_MOUSE_MOTION:
    {
        MouseMovedEvent ev(event.motion.x, event.motion.y);
        m_event_callback(ev);
        break;
    }
    case SDL_EVENT_DROP_FILE:
    {
        std::vector<std::filesystem::path> filepaths;
        filepaths.emplace_back(event.drop.data);
        WindowDropEvent ev(std::move(filepaths));
        m_event_callback(ev);
        break;
    }
    }
}

void Window::swap_buffers()
{
	SDL_GL_SwapWindow(m_window);
}

bool Window::is_running()
{
    return m_is_running;
}

void Window::close_window()
{
    m_is_running = false;
}

void Window::set_vsync(bool enable)
{
	SDL_SetWindowSurfaceVSync(m_window, enable ? 1 : 0);
}

void Window::set_icon(const char* filepath)
{
    stbi_set_flip_vertically_on_load(0);
    i32 width, height, bpp;
    stbi_uc* data = stbi_load(filepath, &width, &height, &bpp, 4);

    if (!data)
    {
        return;
    }

    SDL_Surface* icon_surface = SDL_CreateSurfaceFrom(width, height, SDL_PIXELFORMAT_RGBA32, data, width * 4);
    if (!icon_surface)
    {
        stbi_image_free(data);
        return;
    }

    SDL_SetWindowIcon(m_window, icon_surface);
    SDL_DestroySurface(icon_surface);
    stbi_image_free(data);
}

void Window::set_icon(unsigned char* data, i32 width, i32 height)
{
    SDL_Surface* icon_surface = SDL_CreateSurfaceFrom(width, height, SDL_PIXELFORMAT_RGBA32, data, width * 4);
    if (!icon_surface)
    {
        stbi_image_free(data);
        return;
    }

    SDL_SetWindowIcon(m_window, icon_surface);
    SDL_DestroySurface(icon_surface);
}

void Window::set_event_callback(const EventCallback& callback)
{
	m_event_callback = callback;
}

void Window::minimize()
{
    SDL_MinimizeWindow(m_window);
}

void Window::maximize()
{
    SDL_MaximizeWindow(m_window);
}

void Window::get_size(i32* width, i32* height)
{
	SDL_GetWindowSize(m_window, width, height);
}

void Window::get_position(i32* pos_x, i32* pos_y)
{
	SDL_GetWindowPosition(m_window, pos_x, pos_y);
}

const char* Window::get_title()
{
    return m_title;
}

SDL_Window* Window::get_native_window()
{
	return m_window;
}

SDL_GLContext Window::get_gl_context()
{
	return m_gl_context;
}


