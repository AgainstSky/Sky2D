//
// Created by sky on 2026/10/6.
//

#include "../include/sky2d/core/Engine.h"

#include "raylib.h"
#include "sky2d/core/Application.h"
#include <sky2d/scene/SceneManager.h>

namespace sky2d {
    void Engine::quit() {
        running_ = false;
    }

    void Engine::shutdown() {
        if (!inited_) {
            return;
        }
        running_ = false;
        if (app_) {
            app_->onShutdown();
        }
        resource_->unloadAll();
        if (IsAudioDeviceReady()) {
            CloseAudioDevice();
        }
        if (IsWindowReady()) {
            CloseWindow();
        }
        inited_ = false;

    }

    void Engine::initResources(const std::string &resourcesPath) {
        resource_ = std::make_unique<ResourceManager>(resourcesPath);
    }

    ResourceManager * Engine::resourceManager() {
        return resource_.get();
    }

    Time & Engine::time() {
        return time_;
    }

    SceneManager & Engine::sceneManager() {
        return sceneManager_;
    }

    void Engine::setApplication(Application *application) {
        this->app_ = application;
    }

    bool Engine::isRunning() const {
        return running_;
    }

    bool Engine::init(int width, int height, const std::string &title) {
        if (inited_) {
            return true;
        }
        InitWindow(width,height,title.c_str());

        if (!IsWindowReady()) {
            return false;
        }
        SetTargetFPS(targetFPS_);
        InitAudioDevice();
        if (app_) {
            app_->onInit();
        }

        inited_ = true;
        return true;
    }

    void Engine::run() {
        if (!inited_) {
            return;
        }
        running_ = true;
        while (running_&&!WindowShouldClose()) {
            time_.update();
            if (app_) {
                app_->onUpdate(time_);
            }
            sceneManager_.update(time_);
            BeginDrawing();
            ClearBackground(BLACK);

            sceneManager_.draw();
            if (app_) {
                app_->onDraw();
            }

            EndDrawing();
        }
    }


} // sky2d