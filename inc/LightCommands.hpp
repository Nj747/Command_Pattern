#pragma once

#include "Receivers.hpp"

namespace Commands {
    class LightOnCommand : public Command {
    public:
        LightOnCommand(std::shared_ptr<Receivers::Light> light) : mLight(light) {}

        ~LightOnCommand() {
            std::cout << "~LightOnCmd\n";
        }

        virtual void execute() { mLight->on(); }
        virtual void undo() { mLight->off(); }

    private:
        std::shared_ptr<Receivers::Light> mLight;
    };

    class LightOffCommand : public Command {
    public:
        LightOffCommand(std::shared_ptr<Receivers::Light> light) : mLight(light) {}
        virtual void execute() { mLight->off(); }
        virtual void undo() { mLight->on(); }

        ~LightOffCommand() {
            std::cout << "~LightOffCmd\n";
        }

    private:
        std::shared_ptr<Receivers::Light> mLight;
    };
} // Commands
