#pragma once

#include "core/object.hpp"
#include "core/input/event.hpp"
#include "core/input/app_event.hpp"
#include "core/input/mouse_event.hpp"
#include "core/input/key_event.hpp"
#include "core/input/key_codes.hpp"
#include "core/input/mouse_codes.hpp"

#include <string>

class Application : public Object
{
public:
    Application(const std::string &name)
        : m_name(name)
    {}

    virtual void run() {}

protected:
    std::string m_name;
};