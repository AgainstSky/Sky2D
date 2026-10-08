//
// Created by sky on 2026/10/7.
//

#ifndef SCENE_H
#define SCENE_H
#include <memory>
#include <vector>
#include <sky2d/core/Time.h>

#include "GameObject.h"

namespace sky2d {
    // class Time;
    class GameObject;
    class Scene {
    public:
        virtual ~Scene() = default;
        virtual void onEnter();
        virtual void onExit();
        virtual void draw();

        virtual void update(Time time);
        GameObject* createGameObject();
        void destroyGameObject(GameObject* gameObject);

    protected:
        std::vector<std::shared_ptr<GameObject>> gameObjects_;
    };
}




#endif //SCENE_H
