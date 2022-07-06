#pragma once

#include "Command.hpp"
#include "Receivers.hpp"

namespace Commands {
    class StereoOnWithCDCommand : public Command {
    public:
        StereoOnWithCDCommand(Receivers::Stereo* stereo) : mStereo(stereo) {}

        ~StereoOnWithCDCommand() { delete mStereo; std::cout << "~StereoOnWithCDCommand\n"; }

        virtual void execute() {
            mStereo->on();
            mStereo->setCD();
            mStereo->setVolume(10);
        }

        virtual void undo() { mStereo->off(); }

    private:
        Receivers::Stereo* mStereo;
    }; // StereoOnWithCDCommand

    class StereoOffCommand : public Command {
    public:
        StereoOffCommand(Receivers::Stereo* stereo) : mStereo(stereo) {}

        ~StereoOffCommand() { delete mStereo; std::cout << "~StereoOnWithCDCommand\n"; }

        virtual void execute() { mStereo->off(); }
        virtual void undo() { mStereo->on(); }

    private:
        Receivers::Stereo* mStereo;
    }; // StereoOffCommand
} // Commands