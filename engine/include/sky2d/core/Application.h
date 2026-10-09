//
// Created by sky on 2026/10/9.
//

#ifndef APPLICATION_H
#define APPLICATION_H

namespace sky2d {
    class Application {
    public:
        virtual ~Application() = default;

        virtual void onInit() {}
        virtual void onUpdate( Time const& time) {}
        virtual void onDraw() {}
        virtual void onShutdown() {}
    };
}
#endif //APPLICATION_H
