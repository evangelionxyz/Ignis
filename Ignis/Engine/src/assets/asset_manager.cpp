#include "asset_manager.hpp"

AssetMap AssetManager::asset_map;

static std::map<AssetType, AssetImportFunc> s_asset_import_funcs = 
{
    {ASSET_TYPE_TEXTURE, AssetImporter::import_texture}
};

Ref<Asset> AssetImporter::import(AssetHandle handle, const AssetMetaData &metadata)
{
    if (AssetManager::asset_map.contains(handle))
    {
        if (Ref<Asset> asset = AssetManager::asset_map.at(handle).asset)
            return asset;
    }

    if (!s_asset_import_funcs.contains(metadata.type))
    {
        LOG_ERROR("No importer available for this asset type: {}", get_asset_type_string(metadata.type));
        return nullptr;
    }

    return s_asset_import_funcs.at(metadata.type)(handle, metadata);
}

Ref<Texture> AssetImporter::import_texture(AssetHandle handle, const AssetMetaData &metadata)
{
    return Texture::create(metadata.filepath.string());
}