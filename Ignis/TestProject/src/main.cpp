#include <iostream>

extern "C"
{
__declspec(dllexport) const char *get_hello_world()
{
    return "Hello world";
}
}