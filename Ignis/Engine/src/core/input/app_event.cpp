#include "app_event.hpp"

const char *WindowResizeEvent::to_string() const
{
    std::stringstream ss;
    ss << "WindowResizeEvent: " << m_width << ", " << m_height;

    std::string out = ss.str();
    return out.c_str();
};

const char *WindowCloseEvent::to_string() const
{
    std::stringstream ss;
    ss << "WindowCloseEvent: Window Closed!";

    std::string out = ss.str();
    return out.c_str();
};

const char *FramebufferResizeEvent::to_string() const
{
    std::stringstream ss;
    ss << "FramebufferResizeEvent: " << m_Width << ", " << m_Height;

    std::string out = ss.str();
    return out.c_str();
}

WindowDropEvent::WindowDropEvent(const char **filepaths, i32 count)
    : m_filepaths(filepaths), m_count(count)
{
}
const char *WindowDropEvent::to_string() const
{
    std::stringstream ss;
    ss << "WindoDropEvent: \nDropping files: ";
    
    for (i32 i = 0; i < m_count; ++i)
    {
        ss << m_filepaths[i] << "\n";
    }

    std::string out = ss.str();
    return out.c_str();
}
    
void WindowDropEvent::get_paths(const char ***filepaths, i32 *count) const
{
    *filepaths = m_filepaths;
    *count = m_count;
}