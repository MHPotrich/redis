#ifndef CLI_H
#define CLI_H

#include "command.h"
#include <string>
#include <vector>

std::vector<Command> checkUserCliInput();

void print(std::string content);

#endif // CLI_H
