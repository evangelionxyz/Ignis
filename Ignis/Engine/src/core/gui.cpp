#pragma once
#include "input/event.hpp"
#include "input/app_event.hpp"
#include "input/key_event.hpp"
#include "input/mouse_event.hpp"

#include "object.hpp"

class Application : public Object
{
public:
    Application(const char* title, i32 width, i32 height);

    virtual void on_event(Event& event) = 0;
    virtual void run() = 0;

private:
    const char* m_title;
};