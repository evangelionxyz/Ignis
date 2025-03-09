#pragma once

#include "assets/asset.hpp"
#include "core/types.hpp"
#include "core/uuid.hpp"

#include <filesystem>

struct ProjectInfo
{
    std::string name;
    AssetHandle handle;
    std::filesystem::path filepath;

    AssetHandle default_scene_handle;

    std::string asset_registry_filepath = "asset_registry";
};

class Project : public Asset
{
public:
    Project() = default;
    Project(const ProjectInfo &info);

    void destroy() override;

    static Ref<Project> create(const ProjectInfo &info);

    static Project *get_active();

    static AssetType get_static_type() { return ASSET_TYPE_PROJECT; }
    AssetType get_type() const override { return get_static_type();}

private:
    static Project *s_active;
    ProjectInfo m_info;
};