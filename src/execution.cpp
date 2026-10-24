#include "execution.h"
#include "cli.h"
#include "command.h"
#include "data.h"
#include "database.h"
#include <string>
#include <vector>

void executeCommand(Command command, Database *dataBase) {
    try {
        // GET
        if (command.getOperation() == 0) {
            std::vector<Data> matchData = dataBase->find(command.getTarget());

            if(matchData.size() > 0) {
                for (int i = 0; i < matchData.size(); i++) {
                    printStr(matchData.at(i).getValue());
                }
            } else {
                printNull();
            }
        }

        // SET
        if (command.getOperation() == 1) {
            Data *newData = new Data(command.getTarget(), command.getValue());

            dataBase->add(*newData);

            printOk();
        }

        // DEL
        if (command.getOperation() == 2) {
            int amountMatchs = dataBase->remove(command.getTarget());

            printInt(amountMatchs);
        }

        // EXISTS
        if (command.getOperation() == 3) {
            std::vector<Data> matchData = dataBase->find(command.getTarget());

            printInt(matchData.size());
        }

        // INCR | INCRBY
        if (command.getOperation() == 4 || command.getOperation() == 7) {
            std::vector<Data> matchData = dataBase->find(command.getTarget());

            for(Data item : matchData) {
                try {
                    int value = std::stoi(item.getValue());
                    int increaseValue = 1;

                    if (command.getOperation() == 7) {
                        if (!command.getValue().empty()) {
                            increaseValue = std::stoi(command.getValue());
                        } else {
                            printError("wrong number of arguments for 'incrby' command");
                            return;
                        }
                    }

                    value = value + increaseValue;
                    dataBase->update(command.getTarget(), std::to_string(value));

                    printInt(value);
                } catch (const std::invalid_argument& error) {
                    printError("value is not an integer or out of range");
                } catch (const std::out_of_range& error) {
                    printError("value is not an integer or out of range");
                }
            }

        }

        // DECR | DECRBY
        if (command.getOperation() == 5 || command.getOperation() == 8) {
            std::vector<Data> matchData = dataBase->find(command.getTarget());

            for(Data item : matchData) {
                try {
                    int value = std::stoi(item.getValue());
                    int increaseValue = 1;

                    if (command.getOperation() == 8) {
                        if (!command.getValue().empty()) {
                            increaseValue = std::stoi(command.getValue());
                        } else {
                            printError("wrong number of arguments for 'decrby' command");
                            return;
                        }
                    }

                    value = value - increaseValue;
                    dataBase->update(command.getTarget(), std::to_string(value));

                    printInt(value);
                } catch (const std::invalid_argument& error) {
                    printError("value is not an integer or out of range");
                } catch (const std::out_of_range& error) {
                    printError("value is not an integer or out of range");
                }
            }
        }

        // APPEND
        if (command.getOperation() == 6) {
            std::vector<Data> matchData = dataBase->find(command.getTarget());

            for (Data item : matchData) {
                std::string newValue = item.getValue() + command.getValue();

                dataBase->update(command.getTarget(), newValue);
                printInt(newValue.length());
            }
        }
    } catch (const std::invalid_argument& error) {
        std::cout << error.what() << std::endl;
    }
};
