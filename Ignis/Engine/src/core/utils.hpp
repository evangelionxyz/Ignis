#pragma once
#include <string>
#include <fstream>
#include <sstream>

static std::string read_file(const std::string &filepath)
{
    std::fstream file(filepath, std::ios::in);
    if (file.is_open())
    {
        std::stringstream ss;
        ss << file.rdbuf();

        file.close();
        return ss.str();
    }
    return "";
}