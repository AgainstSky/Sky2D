//
// Created by sky on 2026/10/7.
//

#ifndef TIME_H
#define TIME_H

namespace sky2d {
    class Time {
    public:
        Time(): deltaTime_(0), totalTime_(0), timeScale_(1.0f) {
        };

        Time &setTimeScale(float timeScale) {
            timeScale_ = timeScale;
            return *this;
        }

        float getTimeScale() { return timeScale_; }
        int getDeltaTime() { return deltaTime_ * timeScale_; }
        int getTotalTime() { return totalTime_; }

    private:
        int deltaTime_;
        int totalTime_;
        float timeScale_;
    };
} // sky2d

#endif //TIME_H
