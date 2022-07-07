#pragma once

#include <iostream>

namespace Receivers
{
    class Light {
    public:
        void on() { std::cout << "Light turning on\n"; }
        void off() { std::cout << "Light turning off\n"; }
        ~Light() { std::cout << "~Light\n"; }
    };

    class Stereo {
    public:
        void on() { std::cout << "Stereo turning on\n"; }
        void off() { std::cout << "Stereo turning off\n"; }
        void setCD() { std::cout << "Stereo setting CD\n"; }

        void setVolume(int volume) {
            std::cout << "Stereo setting volume to " << volume << "\n";
            mVolume = volume;
        }

        ~Stereo() { std::cout << "~Stereo\n"; }

    private:
        int mVolume;
    };
} // Receivers
