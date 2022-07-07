#pragma once

#include "Command.hpp"
#include "Receivers.hpp"

namespace Commands {
    class LightOnCommand : public Command {
    public:
        LightOnCommand(Receivers::Light* light) : mLight(light) {}

        ~LightOnCommand() {
            std::cout << "LightOnCommand Destructor\n";
            delete mLight;
        }

        virtual void execute() { mLight->on(); }
        virtual void undo() { mLight->off(); }

    private:
        Receivers::Light* mLight;
    };

    class LightOffCommand : public Command {
    public:
        LightOffCommand(Receivers::Light* light) : mLight(light) {}
        virtual void execute() { mLight->off(); }
        virtual void undo() { mLight->on(); }

        ~LightOffCommand() {
            std::cout << "~LightOnCommand\n";
            delete mLight;
        }

    private:
        Receivers::Light* mLight;
    };
} // Commands
