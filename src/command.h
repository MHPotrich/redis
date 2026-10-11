#ifndef COMMAND_H
#define COMMAND_H

#include <iostream>
#include <string>

enum operations {
    get,
    set,
    del,
    exists
};

class Command {
    private:
        int operation = -1;
        std::string targetName;
        int targetId = -1;
        std::string targetValue;

        void setOperation(std::string rawOperation) {
            if (rawOperation == "GET") {
                this->operation = operations::get;
            }

            if (rawOperation == "SET") {
                this->operation = operations::set;
            }

            if (rawOperation == "DEL") {
                this->operation = operations::del;
            }

            if (rawOperation == "EXISTS") {
                this->operation = operations::exists;
            }

            if (this->operation == -1) {
                throw std::runtime_error("-ERR unknown command '" + rawOperation + "'\r\n");
            }
        }

        void setTarget(std::string rawValue) {
            int delimeterIndex = rawValue.find(":");

            if (delimeterIndex != std::string::npos) {
                this->targetName = rawValue.substr(0, delimeterIndex - 1);
                this->targetId = std::stoi(rawValue.substr(delimeterIndex + 1, rawValue.length()));
            } else {
                this->targetName = rawValue;
            }
        }

        void setValue(std::string rawValue) {
            this->targetValue = rawValue;
        }

    public:
        Command(std::string rawInput) {
            int start = 0;
            int paramCounter = 0;

            for(int i = 0; i <= rawInput.length(); i++) {
                if (rawInput[i] == ' ') {
                    if (paramCounter == 0) {
                        this->setOperation(rawInput.substr(start, i - 1));
                        paramCounter++;
                    }

                    if (paramCounter == 1) {
                        this->setTarget(rawInput.substr(start, i - 1));
                        paramCounter++;
                    }

                    if (paramCounter == 2) {
                        this->setValue(rawInput.substr(start, i - 1));
                        paramCounter++;
                    }

                    start = i;
                }
            }
        }

        int getOperation() {
            return this->operation;
        }

        std::string getTargetName() {
            return this->targetName;
        }

        int getTargetId() {
            return this->targetId;
        }

        std::string getValue() {
            return this->targetValue;
        }
};

#endif // COMMAND_H
