//
// Created by sky on 2026/10/8.
//

#include <sky2d/component/Camera.h>

namespace sky2d {

    Camera::Camera() {
        camera_.offset={0.0f,0.0f};
        camera_.zoom=1.0f;
        camera_.target={0.0f,0.0f};
        camera_.rotation=0.0f;
    }

} // sky2d