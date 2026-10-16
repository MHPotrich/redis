#include "execution.h"
#include "command.h"
#include "data.h"
#include "database.h"
#include <iostream>
#include <ostream>
#include <string>
#include <vector>

void executeCommand(Command command, Database *dataBase) {
    try {
        // GET
        if (command.getOperation() == 0) {
            std::vector<Data> matchData = dataBase->find(command.getTarget());

            if(matchData.size() > 0) {
                for (int i = 0; i < matchData.size(); i++) {
                    std::cout << '"' << matchData.at(i).getValue() << '"' << std::endl;
                }
            } else {
                std::cout << "(nil)" << std::endl;
            }
        }

        // SET
        if (command.getOperation() == 1) {
            Data *newData = new Data(command.getTarget(), command.getValue());

            dataBase->add(*newData);

            std::cout << "OK" << std::endl;
        }

        // DEL
        if (command.getOperation() == 2) {
            int amountMatchs = dataBase->remove(command.getTarget());

            std::cout << "(integer) " << amountMatchs << std::endl;
        }

        // EXISTS
        if (command.getOperation() == 3) {
            std::vector<Data> matchData = dataBase->find(command.getTarget());

            std::cout << "(integer) " << matchData.size() << std::endl;
        }

        // INCR
        if (command.getOperation() == 4) {
            std::vector<Data> matchData = dataBase->find(command.getTarget());

            for(Data item : matchData) {
                try {
                    int value = std::stoi(item.getValue());
                    int increaseValue = 1;

                    if (!command.getValue().empty()) {
                        increaseValue = std::stoi(command.getValue());
                    }

                    value = value + increaseValue;
                    dataBase->update(command.getTarget(), std::to_string(value));

                    std::cout << "(integer) " << value << std::endl;
                } catch (const std::invalid_argument& error) {
                    std::cout << "(error) ERR value is not an integer or out of range" << std::endl;
                } catch (const std::out_of_range& error) {
                    std::cout << "(error) ERR value is not an integer or out of range" << std::endl;
                }
            }

        }

        // DECR
        if (command.getOperation() == 5) {
            std::vector<Data> matchData = dataBase->find(command.getTarget());

            for(Data item : matchData) {
                try {
                    int value = std::stoi(item.getValue());
                    int increaseValue = 1;

                    if (!command.getValue().empty()) {
                        increaseValue = std::stoi(command.getValue());
                    }

                    value = value - increaseValue;
                    dataBase->update(command.getTarget(), std::to_string(value));

                    std::cout << "(integer) " << value << std::endl;
                } catch (const std::invalid_argument& error) {
                    std::cout << "(error) ERR value is not an integer or out of range" << std::endl;
                } catch (const std::out_of_range& error) {
                    std::cout << "(error) ERR value is not an integer or out of range" << std::endl;
                }
            }
        }

        // APPEND
        if (command.getOperation() == 6) {
            std::vector<Data> matchData = dataBase->find(command.getTarget());

            for (Data item : matchData) {
                std::string newValue = item.getValue() + command.getValue();

                dataBase->update(command.getTarget(), newValue);
                std::cout << "(integer) " << newValue.length() << std::endl;
            }
        }
    } catch (const std::invalid_argument& error) {
        std::cout << error.what() << std::endl;
    }
};
