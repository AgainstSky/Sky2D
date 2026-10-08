//
// Created by sky on 2026/10/8.
//

#include <sky2d/scene/GameObject.h>

namespace sky2d {

    GameObject::~GameObject() {
        for (auto& component:components_) {
            component->onDetach();
        }
    }

    void GameObject::update(Time time) {
        for (auto& component:components_) {
            component->update(time);
        }
    }

    void GameObject::draw() {
        for (auto& component:components_) {
            component->draw();
        }
    }

    Transform &GameObject::transform() {
        return transform_;
    }

} // sky2d