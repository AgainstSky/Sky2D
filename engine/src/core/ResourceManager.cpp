//
// Created by sky on 2026/10/7.
//

#include <sky2d/core/ResourceManager.h>

namespace sky2d {
    Texture2D ResourceManager::loadTexture(const std::string& texturePath) const {
        const std::string path = assetsRootPath_ +"/"+ texturePath;
        auto image = LoadImage(path.c_str());
        auto texture = LoadTextureFromImage(image);
        UnloadImage(image);
        return texture;
    }
    Texture2D& ResourceManager::getTexture(const std::string& texturePath){
        if (!textureMap_.contains(texturePath)) {
            textureMap_[texturePath] = loadTexture(texturePath);
        }
        return textureMap_[texturePath];
    }
    void ResourceManager::unloadAll() {
        for (auto &item:textureMap_) {
            UnloadTexture(item.second);
        }
        textureMap_.clear();
    }
}