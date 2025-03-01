#pragma once

#include "event.hpp"
#include "mouse_codes.hpp"

class MouseMovedEvent : public Event
{
public:
	MouseMovedEvent(const f32 x, const f32 y)
		: m_mouse_x(x), m_mouse_y(y) 
	{
	}

	f32 get_x() const { return m_mouse_x; }
	f32 get_y() const { return m_mouse_y; }

	std::string to_string() const override
	{
		std::stringstream ss;
		ss << "MouseMovedEvent: " << m_mouse_x << ", " << m_mouse_y;
		return ss.str();
	}

	static EventType get_static_type() { return EventType::MouseMoved; }
	virtual EventType get_event_type() const override { return get_static_type(); }
	virtual int get_category_flags() const override { return EventCategory_Mouse | EventCategory_Input; }
private:
	f32 m_mouse_x, m_mouse_y;
};

class MouseScrolledEvent : public Event
{
public:
	MouseScrolledEvent(const f32 xOffset, const f32 yOffset)
		: m_XOffset(xOffset), m_YOffset(yOffset) 
	{
	}

	f32 get_offset_x() const { return m_XOffset; }
	f32 get_offset_y() const { return m_YOffset; }

	std::string to_string() const override
	{
		std::stringstream ss;
		ss << "MouseScrolledEvent: " << get_offset_x() << ", " << get_offset_y();
		return ss.str();
	}

	static EventType get_static_type() { return EventType::MouseScrolled; }
	virtual EventType get_event_type() const override { return get_static_type(); }
	virtual int get_category_flags() const override { return EventCategory_Mouse | EventCategory_Input; }
private:
	f32 m_XOffset, m_YOffset;
};

class MouseButtonEvent : public Event
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

class MouseButtonPressedEvent : public MouseButtonEvent
{
public:
	MouseButtonPressedEvent(const MouseCode button)
		: MouseButtonEvent(button) {
	}

	std::string to_string() const override
	{
		std::stringstream ss;
		ss << "MouseButtonPressedEvent: " << m_Button;
		return ss.str();
	}

	static EventType get_static_type() { return EventType::MouseButtonPressed; }
	virtual EventType get_event_type() const override { return get_static_type(); }
};

class MouseButtonReleasedEvent : public MouseButtonEvent
{
public:
	MouseButtonReleasedEvent(const MouseCode button)
		: MouseButtonEvent(button) {
	}

	std::string to_string() const override
	{
		std::stringstream ss;
		ss << "MouseButtonReleasedEvent: " << m_Button;
		return ss.str();
	}

	static EventType get_static_type() { return EventType::MouseButtonReleased; }
	virtual EventType get_event_type() const override { return get_static_type(); }
};