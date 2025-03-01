#pragma once

#include "event.hpp"
#include "key_codes.hpp"

class KeyEvent : public Event
{
public:

	KeyEvent(const KeyCode keycode, const KeyModCode keymod)
		: m_key_code(keycode), m_key_mod_code(keymod) 
	{
	}

	KeyCode get_key_code() const { return m_key_code; }
	KeyModCode get_key_mod_code() const { return m_key_mod_code; }

	virtual i32 get_category_flags() const override { return EventCategory_Keyboard | EventCategory_Input; }

protected:
	KeyCode m_key_code;
	KeyModCode m_key_mod_code;
};

class KeyPressedEvent : public KeyEvent
{
public:
	KeyPressedEvent(const KeyCode keycode, const KeyModCode keymod, const u16 repeatCount)
		: KeyEvent(keycode, keymod), m_repeat_count(repeatCount) {
	}

	u16 GetRepeatCount() const { return m_repeat_count; }

	std::string to_string() const override
	{
		std::stringstream ss;
		ss << "KeyPressedEvent: " << (char)m_key_code << " Mod: " << m_key_mod_code << " (" << m_repeat_count << " repeats)";
		return ss.str();
	}

	static EventType get_static_type() { return EventType::KeyPressed; }
	virtual EventType get_event_type() const override { return get_static_type(); }
private:
	u16 m_repeat_count;
};

class KeyReleasedEvent : public KeyEvent
{
public:
	KeyReleasedEvent(const KeyCode keycode, const KeyModCode keymod)
		: KeyEvent(keycode, keymod) {
	}

	std::string to_string() const override
	{
		std::stringstream ss;
		ss << "KeyReleasedEvent: " << (char)m_key_code << " Mod: " << m_key_mod_code;
		return ss.str();
	}

	static EventType get_static_type() { return EventType::KeyPressed; }
	virtual EventType get_event_type() const override { return get_static_type(); }
};

class KeyTypedEvent : public KeyEvent
{
public:
	KeyTypedEvent(const KeyCode keycode)
		: KeyEvent(keycode, IGN_KEY_UNKNOWN) {
	}

	std::string to_string() const override
	{
		std::stringstream ss;
		ss << "KeyTypedEvent: " << (char)m_key_code;
		return ss.str();
	}

	static EventType get_static_type() { return EventType::KeyTyped; }
	virtual EventType get_event_type() const override { return get_static_type(); }
};