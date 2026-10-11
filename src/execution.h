#ifndef EXECUTION_H
#define EXECUTION_H

#include "command.h"
#include "data.h"
#include "database.h"
#include <vector>

void executeCommand(Command command, Database *dataBase);

#endif // EXECUTION_H
