#pragma once

#include "Receivers.hpp"
#include "MacroCommand.hpp"

namespace Commands {

    class StereoOnCommand : public Command {
    public:
        StereoOnCommand(std::shared_ptr<Receivers::Stereo> stereo) : mStereo(stereo) {}

        ~StereoOnCommand() { std::cout << "~StereoOnCommand\n"; }

        virtual void execute() {
            mStereo->on();
        }

        //virtual void undo() { mStereo->off(); }

    private:
        std::shared_ptr<Receivers::Stereo> mStereo;
    }; // StereoOnWithCDCommand

    class StereoOffCommand : public Command {
    public:
        StereoOffCommand(std::shared_ptr<Receivers::Stereo> stereo) : mStereo(stereo) {}

        ~StereoOffCommand() { std::cout << "~StereoOffCommand\n"; }

        virtual void execute() { mStereo->off(); }
        //virtual void undo() { mStereo->on(); }

    private:
        std::shared_ptr<Receivers::Stereo> mStereo;
    }; // StereoOffCommand
} // Commands