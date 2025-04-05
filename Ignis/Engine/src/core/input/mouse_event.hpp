#pragma once

#include "event.hpp"
#include "mouse_codes.hpp"

class IGNIS_API MouseMovedEvent : public Event
{
public:
	MouseMovedEvent(const f32 x, const f32 y)
		: m_mouse_x(x), m_mouse_y(y) 
	{
	}

	f32 get_x() const { return m_mouse_x; }
	f32 get_y() const { return m_mouse_y; }

	const char *to_string() const override;

	static EventType get_static_type() { return EventType::MouseMoved; }
	virtual EventType get_event_type() const override { return get_static_type(); }
	virtual int get_category_flags() const override { return EventCategory_Mouse | EventCategory_Input; }
private:
	f32 m_mouse_x, m_mouse_y;
};

class IGNIS_API MouseScrolledEvent : public Event
{
public:
	MouseScrolledEvent(const f32 xOffset, const f32 yOffset)
		: m_XOffset(xOffset), m_YOffset(yOffset) 
	{
	}

	f32 get_offset_x() const { return m_XOffset; }
	f32 get_offset_y() const { return m_YOffset; }

	const char *to_string() const override;

	static EventType get_static_type() { return EventType::MouseScrolled; }
	virtual EventType get_event_type() const override { return get_static_type(); }
	virtual int get_category_flags() const override { return EventCategory_Mouse | EventCategory_Input; }
private:
	f32 m_XOffset, m_YOffset;
};

class IGNIS_API MouseButtonEvent : public Event
{
public:
	MouseCode GetButton() const { return m_Button; }
	bool Is(MouseCode bt) { return m_Button == bt; }

	virtual int get_category_flags() const override { return EventCategory_Mouse | EventCategory_Input; }
protected:
	MouseButtonEvent(const MouseCode button)
		: m_Button(button) 
	{
	}

	MouseCode m_Button;
};

class IGNIS_API MouseButtonPressedEvent : public MouseButtonEvent
{
public:
	MouseButtonPressedEvent(const MouseCode button)
		: MouseButtonEvent(button) {
	}

	const char *to_string() const override;

	static EventType get_static_type() { return EventType::MouseButtonPressed; }
	virtual EventType get_event_type() const override { return get_static_type(); }
};

class IGNIS_API MouseButtonReleasedEvent : public MouseButtonEvent
{
public:
	MouseButtonReleasedEvent(const MouseCode button)
		: MouseButtonEvent(button) {
	}

	const char *to_string() const override;

	static EventType get_static_type() { return EventType::MouseButtonReleased; }
	virtual EventType get_event_type() const override { return get_static_type(); }
};