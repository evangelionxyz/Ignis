#pragma once

#include "object.hpp"

#include "input/event.hpp"
#include <SDL3/SDL.h>
#include <SDL3/SDL_system.h>

#include <string>
#include <functional>

#include <Windows.h>

using EventCallback = std::function<void(Event &)>;
using GuiEventCallback = std::function<void(const SDL_Event *)>;

class IGNIS_API Window : public Object
{
private:
	
public:
	Window() = default;
	Window(const char *title, i32 width, i32 height);

	void destroy() override;

	void poll_events();
	void swap_buffers();
	bool is_running();

	void close_window();
	void set_vsync(bool enable);
	void set_icon(const char* filepath);
	void set_icon(unsigned char* data, i32 width, i32 height);
	void set_position(i32 x, i32 y);
	void set_event_callback(const EventCallback& callback);
	void set_gui_event_callback(const GuiEventCallback& callback);

	void minimize();
	void maximize();

	void get_size(i32 *width, i32 *height);
	void get_position(i32 *pos_x, i32 *pos_y);
	void get_framebuffer_size(i32 *width, i32 *height);

	const char* get_title();

	SDL_Window* get_native_window();

	void set_gl_context(SDL_GLContext context);
	
	SDL_GLContext get_gl_context();

	HWND get_native_handle();
private:
	bool m_is_running;
	SDL_Window *m_window;
	SDL_GLContext m_gl_context;

	i32 m_width, m_height, m_pos_x, m_pos_y, m_fb_width, m_fb_height;
	bool m_maximized, m_fullscreen, m_vsync;

	const char* m_title;

	class EventCallbackImpl;
	EventCallbackImpl *m_event_impl;
};