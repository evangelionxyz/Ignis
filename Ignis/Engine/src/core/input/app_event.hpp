#pragma once

#include "event.hpp"

#include <vector>
#include <filesystem>

class WindowResizeEvent : public Event
{
private:
    u32 m_width, m_height;
public:
    WindowResizeEvent(u32 width, u32 height)
        : m_width(width), m_height(height) {
    }

    inline u32 get_width() const { return m_width; }
    inline u32 get_height() const { return m_height; }

    std::string to_string() const override
    {
        std::stringstream ss;
        ss << "WindowResizeEvent: " << m_width << ", " << m_height;
        return ss.str();
    };

    static EventType get_static_type() { return EventType::WindowResize; }
    virtual EventType get_event_type() const override { return get_static_type(); }
    virtual i32 get_category_flags() const override { return EventCategory_Application; }
};

class WindowCloseEvent : public Event
{
public:
    WindowCloseEvent() {}

    std::string to_string() const override
    {
        std::stringstream ss;
        ss << "WindowCloseEvent: Window Closed!";
        return ss.str();
    };

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

    inline i32 GetWidth() const { return m_Width; }
    inline i32 GetHeight() const { return m_Height; }

    std::string to_string() const override
    {
        std::stringstream ss;
        ss << "FramebufferResizeEvent: " << m_Width << ", " << m_Height;
        return ss.str();
    }

    static EventType get_static_type() { return EventType::FramebufferResize; }
    virtual EventType get_event_type() const override { return get_static_type(); }
    virtual i32 get_category_flags() const override { return EventCategory_Application; }
};

class WindowDropEvent : public Event
{
public:
    WindowDropEvent(const std::vector<std::filesystem::path>& paths)
        : m_Paths(paths) {
    }
    WindowDropEvent(std::vector <std::filesystem::path>&& paths)
        : m_Paths(std::move(paths)) {
    }

    std::string to_string() const override
    {
        std::stringstream ss;
        ss << "WindoDropEvent: \nDropping files: ";
        for (auto& path : m_Paths)
        {
            ss << path.generic_string() << "\n";
        }
        return ss.str();
    }

    const std::vector<std::filesystem::path>& GetPaths() const { return m_Paths; }

    static EventType get_static_type() { return EventType::WindowDrop; }
    virtual EventType get_event_type() const override { return get_static_type(); }
    virtual i32 get_category_flags() const override { return EventCategory_Application; }
private:
    std::vector<std::filesystem::path> m_Paths;
};