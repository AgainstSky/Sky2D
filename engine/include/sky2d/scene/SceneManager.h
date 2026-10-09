//
// Created by sky on 2026/10/7.
//

#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H
#include <memory>
#include <vector>
#include <sky2d/scene/Scene.h>


#include "../core/Time.h"

namespace sky2d {
    class Time;
    class SceneManager {
    public:
        using ScenePtr = std::unique_ptr<Scene>;
        SceneManager() ;
        void pushScene(ScenePtr scene) ;
        void popScene();

        [[nodiscard]]
        Scene *currentScene() const{
            if (sceneStack_.empty()) {
                return nullptr;
            }
            return sceneStack_.back().get();
        }

        void update( Time const& time) ;
        void draw();
    private:
        std::vector<ScenePtr> sceneStack_;
    };
}



#endif //SCENEMANAGER_H
