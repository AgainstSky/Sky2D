//
// Created by sky on 2026/10/6.
//

#ifndef ENGINE_H
#define ENGINE_H
#include "raylib.h"
#include "ResourceManager.h"

namespace sky2d {

    class Engine {
    public:
        Engine(const int width,const int height, const char* title):width_(width),height_(height),title_(title) {
            InitWindow(width_, height_, title_);
        };

        void run();
    private:
        ResourceManager resource_;
        int width_, height_;
        const char* title_;
    };

} // sky2d

#endif //ENGINE_H
