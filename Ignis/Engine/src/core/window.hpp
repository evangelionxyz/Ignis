#pragma once

#include "object.hpp"

#include "input/event.hpp"
#include <SDL3/SDL.h>

#include <string>
#include <functional>

using EventCallback = std::function<void(Event &)>;

class Window : public Object
{
public:
	Window() = default;
	Window(const std::string& title, int width, int height);

	virtual void destroy() override;

	void poll_events();
	void swap_buffers();
	bool is_running();

	void close_window();
	void set_vsync(bool enable);
	void set_icon(const char* filepath);
	void set_icon(unsigned char* data, i32 width, i32 height);

	void set_event_callback(const EventCallback& callback);
	void minimize();
	void maximize();
	void get_size(i32 *width, i32 *height);
	void get_position(i32 *pos_x, i32 *pos_y);

	const char* get_title();

	SDL_Window* get_native_window();
	SDL_GLContext get_gl_context();
private:
	bool m_is_running;
	SDL_Window *m_window;
	SDL_GLContext m_gl_context;

	i32 m_width, m_height, m_pos_x, m_pos_y, m_fb_width, m_fb_height;
	bool m_maximized, m_fullscreen, m_vsync;

	const char* m_title;

	EventCallback m_event_callback;
};