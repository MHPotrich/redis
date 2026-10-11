#include "execution.h"
#include "data.h"
#include "database.h"
#include <iostream>

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

            for (Data item : matchData) {
                std::cout << item.getValue();
            }
        }

        // SET
        if (command.getOperation() == 1) {
            Data *newData = new Data(command.getTargetName(), command.getTargetId(), command.getValue());

            dataBase->add(*newData);

            std::cout << "OK";
        }
    } catch (const std::runtime_error& error) {
        std::cout << error.what();
    }
};
