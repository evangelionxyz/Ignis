#include "asset.hpp"

IGNIS_API const char *get_asset_type_string(AssetType type)
{
    switch(type)
    {
    case ASSET_TYPE_TEXTURE: return "Asset_Texture";
    case ASSET_TYPE_AUDIO: return "Asset_Audio";
    case ASSET_TYPE_SCENE: return "Asset_Scene";
    case ASSET_TYPE_PROJECT: return "Asset_Project";
    default: return "Invalid";
    }
}

Asset::Asset(AssetHandle handle)
    : handle(handle)
{
}
