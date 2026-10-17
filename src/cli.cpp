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

void printInt(int value) {
    std::cout << "(integer) " << value << std::endl;
}

void printStr(std::string content) {
    std::cout << '"' << content << '"' << std::endl;
}

void printNull() {
    std::cout << "(nil)" << std::endl;
}

void printError(std::string message) {
    std::cout << "(error) ERR " << message << std::endl;
}

void printOk() {
    std::cout << "OK" << std::endl;
}
