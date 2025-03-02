#include "input.hpp"

std::unordered_map<SDL_Keycode, bool> Input::keycodes;
std::unordered_map<SDL_Keymod, bool> Input::modifiers;
std::unordered_map<u8, bool> Input::mouse_buttons;