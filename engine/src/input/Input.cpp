//
// Created by sky on 2026/10/9.
//

#include <sky2d/input/Input.h>

namespace sky2d {

    bool Input::isKeyDown(int key)
    {
        return IsKeyDown(key);
    }

    bool Input::isKeyPressed(int key)
    {
        return IsKeyPressed(key);
    }

    bool Input::isKeyReleased(int key)
    {
        return IsKeyReleased(key);
    }

    bool Input::isMouseButtonDown(int button)
    {
        return IsMouseButtonDown(button);
    }

    bool Input::isMouseButtonPressed(int button)
    {
        return IsMouseButtonPressed(button);
    }

    bool Input::isMouseButtonReleased(int button)
    {
        return IsMouseButtonReleased(button);
    }

    Vector2 Input::mousePosition()
    {
        return GetMousePosition();
    }

    float Input::mouseWheelMove()
    {
        return GetMouseWheelMove();
    }
} // sky2d