//
// Created by sky on 2026/10/7.
//

#include <sky2d/scene/SceneManager.h>
#include <sky2d/scene/Scene.h>
namespace sky2d {
    void SceneManager::pushScene(ScenePtr &scene) {
        if (!scene) {
            return;
        }
        if (currentScene()) {
            currentScene()->onEnter();
        }
        scene->onEnter();

        sceneStack_.push_back(std::move(scene));
    }

    void SceneManager::popScene() {
        if (sceneStack_.empty()) {
            return;
        }
        auto& scene = sceneStack_.back();
        scene->onExit();
        sceneStack_.pop_back();
        if (currentScene()) {
            currentScene()->onEnter();
        }
    }

    void SceneManager::update(const Time time) {
        auto scene = currentScene();
        if (scene) {
            scene->update(time);
        }

    }

    void SceneManager::draw() {
        auto scene = currentScene();
        if (scene) {
            scene->draw();
        }
    }
}