//
// Created by sky on 2026/10/6.
//

#include "../include/sky2d/core/Engine.h"

#include "raylib.h"

namespace sky2d {

    void Engine::run() {
        while (!WindowShouldClose()) {
            BeginDrawing();
            ClearBackground(RAYWHITE);
            EndDrawing();
        }
    }


} // sky2d