#pragma once

#include "core/base.hpp"
#include "core/types.hpp"

#include <sstream>

enum class EventType
{
	None = 0,
	WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved, WindowDrop,
	FramebufferResize,
	KeyPressed, KeyReleased, KeyTyped,
	MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
};

enum EventCategory
{
	EventCategory_Application = BIT(0),
	EventCategory_Input = BIT(1),
	EventCategory_Keyboard = BIT(2),
	EventCategory_Mouse = BIT(3),
	EventCategory_MouseButton = BIT(4)
};

class Event
{
public:
	virtual ~Event() = default;

	bool Handled = false;

	virtual EventType get_event_type() const = 0;
	virtual int get_category_flags() const = 0;

	virtual std::string to_string() const = 0;

	bool is_in_category(EventCategory category)
	{
		return get_category_flags() & category;
	}
};

class EventDispatcher
{
public:
	EventDispatcher(Event& event)
		: m_event(event)
	{
	}

	// F will be deduced by the compiler
	template<typename T, typename F>
	bool dispatch(const F& func)
	{
		if (m_event.get_event_type() == T::get_static_type())
		{
			m_event.Handled = func(static_cast<T&>(m_event));
			return true;
		}
		return false;
	}
private:
	Event& m_event;
};