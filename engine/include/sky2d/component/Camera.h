//
// Created by sky on 2026/10/8.
//

#ifndef CAMERA_H
#define CAMERA_H
#include "raylib.h"

namespace sky2d {

class Camera {
public:
    Camera();
    [[nodiscard]]
    Camera2D& camera() {
        return camera_;
    }
    void begin() {
        BeginMode2D(camera_);
    };
    void end() {
        EndMode2D();
    }
    ~Camera();
private:
    Camera2D camera_{};
};

} // sky2d

#endif //CAMERA_H
