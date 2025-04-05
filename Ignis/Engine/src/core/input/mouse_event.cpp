#include "mouse_event.hpp"

const char *MouseMovedEvent::to_string() const
{
    std::stringstream ss;
    ss << "MouseMovedEvent: " << m_mouse_x << ", " << m_mouse_y;
    std::string out = ss.str();
    return out.c_str();
}

const char *MouseScrolledEvent::to_string() const
{
    std::stringstream ss;
    ss << "MouseScrolledEvent: " << get_offset_x() << ", " << get_offset_y();
    std::string out = ss.str();
    return out.c_str();
}

const char *MouseButtonPressedEvent::to_string() const
{
    std::stringstream ss;
    ss << "MouseButtonPressedEvent: " << m_Button;
    std::string out = ss.str();
    return out.c_str();
}

const char *MouseButtonReleasedEvent::to_string() const
{
    std::stringstream ss;
    ss << "MouseButtonReleasedEvent: " << m_Button;
    std::string out = ss.str();
    return out.c_str();
}