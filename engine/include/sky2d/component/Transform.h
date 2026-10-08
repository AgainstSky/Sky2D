//
// Created by sky on 2026/10/8.
//

#ifndef TRANSFORM_H
#define TRANSFORM_H
#include "raylib.h"

namespace sky2d {

struct Transform {
    Vector2 position{0.0f, 0.0f};
    Vector2 scale{1.0f, 1.0f};
    float rotation{0.0f};
};

} // sky2d

#endif //TRANSFORM_H
