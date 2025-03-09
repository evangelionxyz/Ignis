#pragma once
#include "core/object.hpp"
#include "core/uuid.hpp"

enum AssetType
{
    ASSET_TYPE_UNKNOWN = 0,
    ASSET_TYPE_TEXTURE,
    ASSET_TYPE_AUDIO,
    ASSET_TYPE_SCENE,
    ASSET_TYPE_PROJECT
};

static std::string get_asset_type_string(AssetType type)
{
    switch(type)
    {
    case ASSET_TYPE_TEXTURE: return "Asset_Texture";
    case ASSET_TYPE_AUDIO: return "Asset_Audio";
    case ASSET_TYPE_SCENE: return "Asset_Scene";
    case ASSET_TYPE_PROJECT: return "Asset_Project";
    default:
        return "Invalid";
    }
}

using AssetHandle = UUID;
class Asset : public Object {
public:
    Asset() = default;
    Asset(AssetHandle handle);

    virtual AssetType get_type() const = 0;

    AssetHandle handle;
};
