#include "cli.h"
#include "command.h"
#include <iostream>
#include <string>
#include <vector>

std::vector<Command> checkUserCliInput() {
    std::string inputBuffer;

    std::cout << "> ";
    std::getline(std::cin, inputBuffer);

    std::vector<Command> commands;
    Command* command = new Command(inputBuffer);

    commands.push_back(*command);

    return commands;
};
