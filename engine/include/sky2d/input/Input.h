//
// Created by sky on 2026/10/9.
//

#ifndef INPUT_H
#define INPUT_H
#include "raylib.h"

namespace sky2d {

class Input {
public:
    static bool isKeyDown(int key);
    static bool isKeyPressed(int key);
    static bool isKeyReleased(int key);

    static bool isMouseButtonDown(int button);
    static bool isMouseButtonPressed(int button);
    static bool isMouseButtonReleased(int button);

    static Vector2 mousePosition();
    static float mouseWheelMove();
};

} // sky2d

#endif //INPUT_H
