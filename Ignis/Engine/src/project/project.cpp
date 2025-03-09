#include "project.hpp"

Project *Project::s_active;

Project::Project(const ProjectInfo &info)
    : m_info(info)
{  
    s_active = this;
}

Ref<Project> Project::create(const ProjectInfo &info)
{
    return CreateRef<Project>(info);
}

Project *Project::get_active()
{
    return s_active;
}