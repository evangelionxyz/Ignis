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

extern "C" {
IGNIS_API const char *get_asset_type_string(AssetType type);
}

using AssetHandle = UUID;
class IGNIS_API Asset : public Object {
public:
    Asset() = default;
    Asset(AssetHandle handle);

    virtual AssetType get_type() const = 0;

    AssetHandle handle;
};
