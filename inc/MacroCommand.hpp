#pragma once

#include <iostream>
#include <memory>
#include <vector>
#include "Command.hpp"

namespace Commands {
	class MacroCommand : public Command {
	public:
		MacroCommand(std::vector<std::shared_ptr<Command>> cmd) {
			mCommands = cmd;
		}

		virtual void execute() {
			for (auto& cmd : mCommands) {
				cmd->execute();
			}
		}

		~MacroCommand() { std::cout << "~MacroCommand\n"; }

	private:
		std::vector<std::shared_ptr<Command>> mCommands;
	};
}
