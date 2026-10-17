#ifndef CLI_H
#define CLI_H

#include "command.h"
#include <string>
#include <vector>

std::vector<Command> checkUserCliInput();

void printStr(std::string content);

void printInt(int value);

void printNull();

void printError(std::string message);

void printOk();

#endif // CLI_H
