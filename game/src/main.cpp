//
// Created by sky on 2026/10/6.
//
#include <filesystem>
#include <iostream>
#include <sky2d/core/Engine.h>
#include <sky2d/component/SpriteRenderer.h>
#include <sky2d/component/Camera.h>
#include "sky2d/core/ResourceManager.h"
#include <sky2d/input/Input.h>
using namespace std;
using namespace sky2d;

class GameScene: public Scene {
public:
    explicit GameScene(ResourceManager* resourceManager) {
        resourceManager_ = resourceManager;
    }
    void onEnter() override {
        player_= createGameObject();
        player_->transform().position ={300.0f, 300.0f};
        sprite_ = player_->addComponent<SpriteRenderer>();
        auto texture = resourceManager_->getTexture("image/playerPlane.png");
        sprite_->setTexture(texture);
        cameraObj_ = createGameObject();
        camera_ = cameraObj_->addComponent<sky2d::Camera>();
        camera_->camera().target = player_->transform().position;
        camera_->camera().offset = player_->transform().position;

    }
    void update(Time const &time) override {
        Scene::update(time);
        auto playerPos = player_->transform().position;
        auto mousePos = Input::mousePosition();
        auto detalX = mousePos.x - playerPos.x;
        auto detalY = mousePos.y - playerPos.y;
        player_->transform().position.x += detalX * speed ;
        player_->transform().position.y += detalY * speed ;
        camera_->camera().target = player_->transform().position;
    }

private:
    GameObject* player_{nullptr};
    GameObject* cameraObj_{nullptr};
    SpriteRenderer* sprite_{nullptr};
    sky2d::Camera* camera_{nullptr};
    ResourceManager* resourceManager_{nullptr};
    int speed{100};
};

int main() {
    Engine engine;
    engine.init(720,1280,"demo");
    engine.initResources("../../game/resources");
    //
    // sky2d::ResourceManager resourceManager("../../game/resources");
    // auto texture = resourceManager.getTexture("image/playerPlane.png");

    auto gameScene = std::make_unique<GameScene>(engine.resourceManager());
    engine.sceneManager().pushScene(std::move(gameScene));

    std::cout << "Working directory: "
              << std::filesystem::current_path()
              << '\n';
    engine.run();
    return 0;
}
