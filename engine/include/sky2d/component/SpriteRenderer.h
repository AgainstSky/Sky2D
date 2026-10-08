//
// Created by sky on 2026/10/8.
//

#ifndef SPRITERENDERER_H
#define SPRITERENDERER_H
#include "Component.h"
#include "raylib.h"

namespace sky2d {

class SpriteRenderer:public Component{
public:
    SpriteRenderer() = default;
    void draw();

    void setTexture( Texture2D* texture){texture_ = texture;};
    Texture2D* getTexture()const {return texture_;};
private:
    Texture2D* texture_;

    Color tint_{WHITE};

    Vector2 origin_{0.0f, 0.0f};
};

} // sky2d

#endif //SPRITERENDERER_H
