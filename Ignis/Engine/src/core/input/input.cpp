#include "input.hpp"

struct InputImpl
{
    std::unordered_map<SDL_Keycode, bool> keycodes;
    std::unordered_map<SDL_Keymod, bool> modifiers;
    std::unordered_map<u8, bool> mouse_buttons;
    SDL_Point mouse_position = {0, 0};
};

InputImpl *impl = new InputImpl();

Input::Input()
{
    impl = new InputImpl();
}

Input::~Input()
{
    if (impl)
        delete impl;
}

bool Input::is_key_pressed(SDL_Keycode key)
{
    return impl->keycodes[key];
}

bool Input::is_modifier_pressed(SDL_Keymod mod)
{
    return impl->modifiers[mod];
}

bool Input::is_mouse_button_pressed(u8 button)
{
    return impl->mouse_buttons[button];
}

SDL_Point Input::get_mouse_position()
{
    return impl->mouse_position;
}

void Input::set_key(SDL_Keycode key, bool pressed)
{
    impl->keycodes[key] = pressed;
}

void Input::set_modifier(SDL_Keymod mod, bool pressed)
{
    impl->modifiers[mod] = pressed;
}

void Input::set_mouse_button(u8 button, bool pressed)
{
    impl->mouse_buttons[button] = pressed;
}

void Input::set_mouse_position(int x, int y)
{
    impl->mouse_position = {x, y};
}
