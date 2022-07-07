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
        ~Stereo() { std::cout << "~Stereo\n"; }
    };
} // Receivers
