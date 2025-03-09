#pragma once
#include "serializer.hpp"
#include "project/project.hpp"

class ProjectSerializer
{
public:
    ProjectSerializer(Ref<Project> project, const std::filesystem::path &filepath);
    void serialize();

    static Ref<Project> deserialize(const std::filesystem::path &filepath);
private:
    Ref<Project> m_project;
};