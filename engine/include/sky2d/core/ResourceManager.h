//
// Created by sky on 2026/10/7.
//

#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H
#include <string>
#include <unordered_map>

#include "raylib.h"


namespace sky2d {

    class ResourceManager {
    public:
        ResourceManager()=default;
        explicit ResourceManager(const std::string& rootPath):assetsRootPath_(rootPath) {}
        Texture2D* getTexture(const std::string& texturePath) ;
        void unloadAll();
        ~ResourceManager(){unloadAll();};
        void setRootPath(const std::string& rootPath);
    private:
        Texture2D loadTexture(const std::string& texturePath) const;
        std::string assetsRootPath_;
        std::unordered_map<std::string,Texture2D> textureMap_;
    };

}



#endif //RESOURCEMANAGER_H
