#pragma once

#include "core/types.hpp"
#include <SDL3/SDL.h>
#include <memory>
#include <unordered_map>

struct IGNIS_API Input
{
    Input();
    ~Input();

    static bool is_key_pressed(SDL_Keycode key);
    static bool is_modifier_pressed(SDL_Keymod mod);
    static bool is_mouse_button_pressed(u8 button);
    static SDL_Point get_mouse_position();

    static void set_key(SDL_Keycode key, bool pressed);
    static void set_modifier(SDL_Keymod mod, bool pressed);
    static void set_mouse_button(u8 button, bool pressed);
    static void set_mouse_position(int x, int y);
};
