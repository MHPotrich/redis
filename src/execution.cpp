#include "execution.h"
#include "data.h"
#include "database.h"
#include <iostream>
#include <ostream>

void executeCommand(Command command, Database *dataBase) {
    try {
        // GET
        if (command.getOperation() == 0) {
            std::vector<Data> matchData;

            if (command.getTargetId() != -1) {
                matchData = dataBase->find(command.getTargetName(), command.getTargetId());
            } else {
                matchData = dataBase->find(command.getTargetName());
            }

            std::cout << "$" << matchData.size() << std::endl;
            for (int i = 0; i < matchData.size(); i++) {
                std::cout << "*" << i + 1 << std::endl;
                std::cout << matchData.at(i).getValue() << std::endl;
            }
        }

        // SET
        if (command.getOperation() == 1) {
            Data *newData = new Data(command.getTargetName(), command.getTargetId(), command.getValue());

            dataBase->add(*newData);

            std::cout << "OK" << std::endl;
        }
    } catch (const std::runtime_error& error) {
        std::cout << error.what() << std::endl;
    }
};
