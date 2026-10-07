//
// Created by sky on 2026/10/6.
//
#include <filesystem>
#include <iostream>
#include <sky2d/core/Engine.h>

#include "sky2d/core/ResourceManager.h"

int main() {
    sky2d::Engine engine(720,1280,"Sky2D");

    sky2d::ResourceManager resourceManager("../../game/resources");
    auto texture = resourceManager.getTexture("image/playerPlane.png");
    std::cout << "Working directory: "
              << std::filesystem::current_path()
              << '\n';
    engine.run();
    return 0;
}
