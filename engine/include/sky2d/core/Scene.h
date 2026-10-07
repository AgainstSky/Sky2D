//
// Created by sky on 2026/10/7.
//

#ifndef SCENE_H
#define SCENE_H

namespace sky2d {
    class Time;
    class Scene {
    public:
        virtual ~Scene() = default;
        virtual void onEnter();
        virtual void onExit();
        virtual void render()=0;
        virtual void update(Time time) = 0;
    };
}




#endif //SCENE_H
