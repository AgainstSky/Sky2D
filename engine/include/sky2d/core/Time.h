//
// Created by sky on 2026/10/7.
//

#ifndef TIME_H
#define TIME_H

namespace sky2d {
    class Time {
    public:

        Time &setTimeScale(const float timeScale) {
            timeScale_ = timeScale;
            return *this;
        }
        [[nodiscard]]
        float getTimeScale() { return timeScale_; }

        [[nodiscard]]
        int getDeltaTime() { return deltaTime_; }

        [[nodiscard]]
        int getElapsedTime() { return elapsedTime_; }

        [[nodiscard]]
        int getFPS() { return fps_; }

        void update();

    private:
        int deltaTime_{0};
        int elapsedTime_{0};
        float timeScale_{1.0f};
        int fps_{1};
    };
} // sky2d

#endif //TIME_H
