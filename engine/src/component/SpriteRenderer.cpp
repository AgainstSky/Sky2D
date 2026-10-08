//
// Created by sky on 2026/10/8.
//

#include <sky2d/component/SpriteRenderer.h>

#include "sky2d/scene/GameObject.h"

namespace sky2d {
    void SpriteRenderer::draw() {
        if (!texture_) {
            return;
        }
        const auto& transform = gameObject()->transform();

        Rectangle source{
            0.0f,
            0.0f,
            static_cast<float>(texture_->width),
            static_cast<float>(texture_->height)
        };
        Rectangle destination{
            transform.position.x,
            transform.position.y,
            static_cast<float>(texture_->width) *
                transform.scale.x,
            static_cast<float>(texture_->height) *
                transform.scale.y
        };

        DrawTexturePro(
            *texture_,
            source,
            destination,
            origin_,
            transform.rotation,
            tint_
        );
    }
} // sky2d