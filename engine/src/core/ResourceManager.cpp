//
// Created by sky on 2026/10/7.
//

#include <sky2d/core/ResourceManager.h>

namespace sky2d {
    void ResourceManager::setRootPath(const std::string &rootPath) {
        assetsRootPath_ = rootPath;
    }

    Texture2D ResourceManager::loadTexture(const std::string& texturePath) const {
        const std::string path = assetsRootPath_ +"/"+ texturePath;
        auto image = LoadImage(path.c_str());

        if (image.data == nullptr)
        {
            TraceLog(
                LOG_ERROR,
                "Failed to load image: %s",
                path.c_str()
            );

            return Texture2D{};
        }

        auto texture = LoadTextureFromImage(image);
        UnloadImage(image);
        return texture;
    }
    Texture2D* ResourceManager::getTexture(const std::string& texturePath){
        auto it = textureMap_.find(texturePath);
        if (it == textureMap_.end()) {
            auto [newIt,inserted] = textureMap_.emplace(texturePath,loadTexture(texturePath));
            return &newIt->second;
        }
        return &it->second;
    }
    void ResourceManager::unloadAll() {
        for (auto &item:textureMap_) {
            if (item.second.id!=0) {
                UnloadTexture(item.second);
            }

        }
        textureMap_.clear();
    }
}