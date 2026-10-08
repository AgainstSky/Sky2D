//
// Created by sky on 2026/10/8.
//

#ifndef COMPONENT_H
#define COMPONENT_H

namespace sky2d {
    class GameObject;
    class Time;
class Component {
public:
    virtual ~Component() =default;

    virtual void onAttach() {}
    virtual void onDetach() {}

    virtual void update(Time& time) {}
    virtual void draw() {}

    [[nodiscard]]
    GameObject* gameObject() const;
private:
    friend class GameObject;
    GameObject* gameObject_;
};

} // sky2d

#endif //COMPONENT_H
