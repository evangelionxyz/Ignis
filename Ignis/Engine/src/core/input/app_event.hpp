#pragma once

#include "event.hpp"

#include <vector>
#include <filesystem>

class IGNIS_API WindowResizeEvent : public Event
{
private:
    u32 m_width, m_height;
public:
    WindowResizeEvent(u32 width, u32 height)
        : m_width(width), m_height(height) {
    }

    inline u32 get_width() const { return m_width; }
    inline u32 get_height() const { return m_height; }

    const char *to_string() const override;

    static EventType get_static_type() { return EventType::WindowResize; }
    virtual EventType get_event_type() const override { return get_static_type(); }
    virtual i32 get_category_flags() const override { return EventCategory_Application; }
};

class IGNIS_API WindowCloseEvent : public Event
{
public:
    WindowCloseEvent() {}

    const char *to_string() const override;

    static EventType get_static_type() { return EventType::WindowClose; }
    virtual EventType get_event_type() const override { return get_static_type(); }
    virtual i32 get_category_flags() const override { return EventCategory_Application; }
};

class FramebufferResizeEvent : public Event
{
private:
    i32 m_Width, m_Height;
public:
    FramebufferResizeEvent(i32 width, i32 height)
        : m_Width(width), m_Height(height) {
    }

    inline i32 get_width() const { return m_Width; }
    inline i32 get_height() const { return m_Height; }

    const char *to_string() const override;

    static EventType get_static_type() { return EventType::FramebufferResize; }
    virtual EventType get_event_type() const override { return get_static_type(); }
    virtual i32 get_category_flags() const override { return EventCategory_Application; }
};

class WindowDropEvent : public Event
{
public:
    WindowDropEvent(const char **filepaths, i32 count);
    const char *to_string() const override;

    void get_paths(const char ***filepaths, i32 *count) const;

    static EventType get_static_type() { return EventType::WindowDrop; }
    virtual EventType get_event_type() const override { return get_static_type(); }
    virtual i32 get_category_flags() const override { return EventCategory_Application; }
private:
    const char **m_filepaths;
    i32 m_count;
};