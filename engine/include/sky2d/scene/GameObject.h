//
// Created by sky on 2026/10/8.
//

#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include <memory>
#include <vector>

#include "sky2d/core/Time.h"
#include <sky2d/component/Transform.h>
namespace sky2d {
class Component;
class GameObject {
public:
    GameObject()=default;
    ~GameObject();
    GameObject(const GameObject&) = delete;
    GameObject& operator=(const GameObject&) = delete;

    Transform& transform();

    template<typename T,typename ...Args>
    T* addComponent(Args&&... args);

    template<typename T>
    T* getComponent();

    virtual void draw();
    virtual void update(Time time);

protected:

private:
    Transform transform_;
    std::vector<std::unique_ptr<Component>> components_;

};

} // sky2d

#include <sky2d/component/Component.h>
namespace sky2d {
    template<typename T, typename... Args>
    T *GameObject::addComponent(Args &&... args) {
        static_assert(std::is_base_of<Component, T>::value,"T must derive from Component");
        auto component = std::make_unique<T>(std::forward<Args>(args)...);
        T* result = component.get();
        components_.push_back(std::move(component));
        result.onAttach();
        return result;
    }

    template<typename T>
    T *GameObject::getComponent() {
        static_assert(std::is_base_of<Component, T>::value,"T must derive from Component");
        for (auto &component : components_) {
            if (auto *result = dynamic_cast<T*>(component.get())) {
                return result;
            }
        }
        return nullptr;
    }


}

#endif //GAMEOBJECT_H
