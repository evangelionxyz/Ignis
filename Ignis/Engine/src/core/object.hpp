#pragma once

#include "base.hpp"
#include "types.hpp"

#include "logger.hpp"
#include "input/event.hpp"

class IGNIS_API Object
{
public:
    virtual ~Object() = default;

    virtual void destroy() {}
    virtual void on_event(Event &e) {}
};