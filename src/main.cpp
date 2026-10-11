#include "database.h"
#include "execution.h"
#include "input.h"
#include <vector>

int main() {
    bool isRunning = true;
    Database* dataBase = new Database();

    while(isRunning) {
        std::vector<Command> commands = checkUserCliInput();

        for (Command command : commands) {
            executeCommand(command, dataBase);
        }
    }

    return 0;
}
