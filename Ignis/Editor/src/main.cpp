#include "ignis.hpp"

int main()
{
    Logger::init();
    IgnisEditor editor;
    editor.run();
    editor.destroy();
    Logger::shutdown();
    return 0;
}
