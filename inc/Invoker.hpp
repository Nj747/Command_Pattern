#pragma once
#include <iostream>
#include <vector>
#include <memory>
#include "Command.hpp"

// Invoker
//class RemoteControl {
//private:
//    std::vector<Commands::Command*> mOnCommands;
//    std::vector<Commands::Command*> mOffCommands;
//    Commands::Command* mUndoCommands;
//public:
//    void setCommand(Commands::Command* onCommand, Commands::Command* offCommand) {
//        mOnCommands.emplace_back(onCommand);
//        mOffCommands.emplace_back(offCommand);
//    }
//
//    void onButtonWasPushed(int slot) {
//        mOnCommands[slot]->execute();
//        mUndoCommands = mOnCommands[slot];
//    }
//
//    void offButtonWasPushed(int slot) {
//        mOffCommands[slot]->execute();
//        mUndoCommands = mOffCommands[slot];
//    }
//
//    void onUndoButtonWasPushed() {
//        mUndoCommands->undo();
//    }
//};

class RemoteControl {
private:
    std::vector<std::shared_ptr<Commands::Command>> mOnCommands;
    std::vector<std::shared_ptr<Commands::Command>> mOffCommands;
public:
    void setCommand(std::shared_ptr<Commands::Command> onCommand, std::shared_ptr<Commands::Command> offCommand) {
        mOnCommands.emplace_back(onCommand);
        mOffCommands.emplace_back(offCommand);
    }

    void onButtonWasPushed(int slot) {
        mOnCommands[slot]->execute();
        // mUndoCommands = mOnCommands[slot];
    }

    void offButtonWasPushed(int slot) {
        mOffCommands[slot]->execute();
        // mUndoCommands = mOffCommands[slot];
    }

    /*void onUndoButtonWasPushed() {
        mUndoCommands->undo();
    }*/
};