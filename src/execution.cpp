#include "execution.h"
#include "data.h"
#include "database.h"
#include <iostream>
#include <ostream>
#include <vector>

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

        // DEL
        if (command.getOperation() == 2) {
            dataBase->remove(command.getTargetName(), command.getTargetId());

            std::cout << "OK" << std::endl;
        }

        // EXISTS
        if (command.getOperation() == 3) {
            std::vector<Data> matchData = dataBase->find(command.getTargetName(), command.getTargetId());

            std::cout << (matchData.size() > 0 ? "TRUE" : "FALSE") << std::endl;
        }
    } catch (const std::invalid_argument& error) {
        std::cout << error.what() << std::endl;
    }
};
