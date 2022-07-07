#pragma once

#include <iostream>

// Interface
namespace Commands {
    class Command {
    public:
        virtual ~Command() { std::cout << "~Command\n"; }
        virtual void execute() = 0;
    };
}
