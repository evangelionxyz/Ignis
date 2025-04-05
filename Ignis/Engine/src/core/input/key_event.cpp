#include "key_event.hpp"

const char *KeyPressedEvent::to_string() const
{
    std::stringstream ss;
    ss << "KeyPressedEvent: " << (char)m_key_code << " Mod: " << m_key_mod_code << " (" << m_repeat_count << " repeats)";
    std::string out = ss.str();
    return out.c_str();
}

const char *KeyReleasedEvent::to_string() const
{
    std::stringstream ss;
    ss << "KeyReleasedEvent: " << (char)m_key_code << " Mod: " << m_key_mod_code;
    std::string out = ss.str();
    return out.c_str();
}

const char *KeyTypedEvent::to_string() const
{
    std::stringstream ss;
    ss << "KeyTypedEvent: " << (char)m_key_code;
    std::string out = ss.str();
    return out.c_str();
}