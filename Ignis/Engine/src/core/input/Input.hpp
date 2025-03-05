#pragma once

#include "core/types.hpp"

#include <SDL3/SDL.h>
#include <unordered_map>

struct Input
{
    static std::unordered_map<SDL_Keycode, bool> keycodes;
    static std::unordered_map<SDL_Keymod, bool> modifiers;
    static std::unordered_map<u8, bool> mouse_buttons;
    static SDL_Point mouse_position;
};