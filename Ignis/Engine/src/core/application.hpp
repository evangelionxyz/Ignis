#pragma once

#include "object.hpp"
#include "input/event.hpp"
#include "input/app_event.hpp"
#include "input/mouse_event.hpp"
#include "input/key_event.hpp"
#include "input/key_codes.hpp"
#include "input/mouse_codes.hpp"

#include <string>

class IGNIS_API Application : public Object
{
public:
    Application(const std::string &name);
    virtual void run();

protected:
    const char *m_name;
};