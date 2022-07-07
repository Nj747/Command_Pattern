#pragma once
#include <iostream>
#include <vector>
#include "Command.hpp"

// Invoker
class RemoteControl {
private:
    std::vector<Commands::Command*> mOnCommands;
    std::vector<Commands::Command*> mOffCommands;
    Commands::Command* mUndoCommands;
public:
    void setCommand(Commands::Command* onCommand, Commands::Command* offCommand) {
        mOnCommands.emplace_back(onCommand);
        mOffCommands.emplace_back(offCommand);
    }

    void onButtonWasPushed(int slot) {
        mOnCommands[slot]->execute();
        mUndoCommands = mOnCommands[slot];
    }

    void offButtonWasPushed(int slot) {
        mOffCommands[slot]->execute();
        mUndoCommands = mOffCommands[slot];
    }

    void onUndoButtonWasPushed() {
        mUndoCommands->undo();
    }
};