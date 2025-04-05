#pragma once
#include <string>
#include <fstream>
#include <sstream>

extern "C"
{

IGNIS_API const char *read_file(const char *filepath)
{
    static std::string content;
    std::fstream file(filepath, std::ios::in);
    if (file.is_open())
    {
        std::stringstream ss;
        ss << file.rdbuf();
        file.close();

        content = ss.str();

        return content.c_str();
    }
    return "";
}

}
