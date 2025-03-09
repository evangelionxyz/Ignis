#pragma once

#include "core/types.hpp"
#include <filesystem>

struct ProjectInfo
{

};

class Project
{
public:
    Project() = default;
    
    static Ref<Project> create();
private:
    ProjectInfo m_info;
};