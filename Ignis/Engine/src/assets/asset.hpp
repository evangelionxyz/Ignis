#pragma once
#include "core/object.hpp"
#include "core/uuid.hpp"

enum AssetType
{
    ASSET_TYPE_UNKNOWN = 0,
    ASSET_TYPE_TEXTURE,
    ASSET_TYPE_AUDIO
};

using AssetHandle = UUID;
class Asset : public Object {
public:
    void destroy() override;
    virtual AssetType get_type() const = 0;

    AssetHandle handle;
};
