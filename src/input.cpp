#include "input.h"
#include "command.h"
#include <iostream>
#include <vector>

std::vector<Command> checkUserCliInput() {
    std::string inputBuffer;

    std::cout << "> ";
    std::cin >> inputBuffer;

    std::vector<Command> commands;

    std::cout << "input: " << inputBuffer;

    return commands;
};
