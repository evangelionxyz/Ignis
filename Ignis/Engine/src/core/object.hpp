#pragma once

#include "types.hpp"
#include "logger.hpp"
#include "input/event.hpp"

class Object
{
public:
    virtual ~Object() = default;

    virtual void destroy() {}
    virtual void on_event(Event &e) {}
};