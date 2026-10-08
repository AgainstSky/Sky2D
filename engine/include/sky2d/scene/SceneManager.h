//
// Created by sky on 2026/10/7.
//

#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H
#include <memory>
#include <vector>


#include "../core/Time.h"

namespace sky2d {
    class Scene;
    class Time;
    class SceneManager {
        using ScenePtr = std::unique_ptr<Scene>;
        SceneManager() {
            sceneStack_=std::vector<ScenePtr>();
            sceneStack_.reserve(5);
        }
        void pushScene(ScenePtr &scene) ;
        void popScene();
        Scene *currentScene() const{
            if (sceneStack_.empty()) {
                return nullptr;
            }
            return sceneStack_.back().get();
        }
        void update(const Time time) ;
        void draw();
    private:
        std::vector<ScenePtr> sceneStack_;
    };
}



#endif //SCENEMANAGER_H
