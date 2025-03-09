#pragma once
#include "core/types.hpp"
#include "renderer/texture.hpp"

#include "asset.hpp"
#include "core/uuid.hpp"

#include <unordered_map>
#include <filesystem>

struct AssetMetaData
{
    Ref<Asset> asset;
    std::filesystem::path filepath;
    AssetType type;
};

using AssetMap = std::unordered_map<AssetHandle, AssetMetaData>;
using AssetImportFunc = std::function<Ref<Asset>(AssetHandle, const AssetMetaData &)>;

struct AssetImporter
{
    static Ref<Asset> import(AssetHandle handle, const AssetMetaData &metadata);
    static Ref<Texture> import_texture(AssetHandle handle, const AssetMetaData &metadata);
};

class AssetManager {
public:
    AssetManager();

    template<typename T>
    static Ref<T> get_asset(AssetHandle handle)
    {
        Ref<Asset> asset = asset_map.at(handle).asset;
        return std::static_pointer_cast<T>(asset);
    }

    static AssetMap asset_map;
};
