//
// Created by sky on 2026/10/7.
//

#include <sky2d/scene/Scene.h>
#include <sky2d/scene/GameObject.h>

namespace sky2d {
    void Scene::update(Time time) {
        for (const auto &obj:gameObjects_) {
            obj->update(time);
        }
    }

    GameObject * Scene::createGameObject() {
        auto object = std::make_unique<GameObject>();
        auto result = object.get();
        gameObjects_.push_back(std::move(object));
        return result;
    }

    void Scene::destroyGameObject(GameObject *gameObject) {
        if (!gameObject) {
            return;
        }
        auto it = std::find_if(gameObjects_.begin(), gameObjects_.end(),
            [gameObject](const auto& object){return gameObject == object.get();}
        );
        if (it != gameObjects_.end()) {
            gameObjects_.erase(it);
        }
    };

    // void Scene::onEnter() {
    // }
    //
    // void Scene::onExit() {
    // }

    void Scene::draw() {
        for (const auto &obj:gameObjects_) {
            obj->draw();
        }
    }

};
