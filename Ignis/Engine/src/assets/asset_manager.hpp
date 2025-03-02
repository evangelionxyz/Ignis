#pragma once
#include "core/types.hpp"

#include "asset.hpp"
#include "core/uuid.hpp"
#include <unordered_map>

using AssetMap = std::unordered_map<UUID, Ref<Asset>>;
class AssetManager {
public:
    AssetManager();


    static AssetMap assets;
};
