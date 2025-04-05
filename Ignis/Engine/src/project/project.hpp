#pragma once

#include "assets/asset.hpp"
#include "core/types.hpp"
#include "core/uuid.hpp"

#include <filesystem>

struct IGNIS_API ProjectInfo
{
    const char *name;
    const char *filepath;
    const char *asset_registry_filepath = "asset_registry";
    AssetHandle handle;

    AssetHandle default_scene_handle;
};

class IGNIS_API Project : public Asset
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