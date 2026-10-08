//
// Created by sky on 2026/10/7.
//

#include "Time.h"
#include "sky2d/core/Time.h"

#include "raylib.h"

namespace sky2d {
    void Time::update() {
        deltaTime_ = GetFrameTime() * timeScale_;
        elapsedTime_ += deltaTime_;
        fps_= static_cast<int>(GetFPS());
    }
} // sky2d