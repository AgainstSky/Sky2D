//
// Created by sky on 2026/10/6.
//

#ifndef ENGINE_H
#define ENGINE_H
#include "raylib.h"
#include "ResourceManager.h"
#include <sky2d/scene/SceneManager.h>
#include "Time.h"

namespace sky2d {

    class Application;
    class Engine {
    public:
        Engine() = default;
        ~Engine() {
            shutdown();
        }
        void quit();
        void shutdown();
        void initResources(const std::string& resourcesPath);
        ResourceManager* resourceManager();
        Time& time();
        SceneManager& sceneManager();

        void setApplication(Application* application);

        [[nodiscard]]
        bool isRunning() const;
        bool init(int width,int height,const std::string& title);
        void run();
    private:
        bool inited_{false};
        bool running_{false};
        Application* app_{nullptr};
        std::unique_ptr<ResourceManager> resource_;
        Time time_;
        SceneManager sceneManager_;
        int width_, height_;
        const char* title_;
        int targetFPS_{120};

    };

} // sky2d

#endif //ENGINE_H
