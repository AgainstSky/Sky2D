//
// Created by sky on 2026/10/8.
//

#include <sky2d/component/Component.h>

namespace sky2d {
    GameObject *Component::gameObject() const {
        return gameObject_;
    }

} // sky2d