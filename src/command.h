#ifndef COMMAND_H
#define COMMAND_H

#include <cstddef>
#include <iostream>
#include <string>

enum operations {
    get,
    set,
    del,
    exists,
    incr,
    decr,
    append
};

class Command {
    private:
        int operation = -1;
        std::string target;
        std::string value;

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

            if (rawOperation == "INCR") {
                this->operation = operations::incr;
            }

            if (rawOperation == "DECR") {
                this->operation = operations::decr;
            }

            if (rawOperation == "APPEND") {
                this->operation = operations::append;
            }

            if (this->operation == -1) {
                throw std::invalid_argument("-ERR unknown command '" + rawOperation + "'");
            }
        }

        void setTarget(std::string target) {
            this->target = target;
        }

        void setValue(std::string value) {
            this->value = value;
        }

    public:
        Command(std::string rawInput) {
            int start = 0;
            int paramCounter = 1;

            for(int i = 0; i <= rawInput.length(); i++) {
                if (rawInput[i] == ' ' || i == rawInput.length()) {
                    if (paramCounter == 1) {
                        this->setOperation(rawInput.substr(start, i - start));
                    }

                    if (paramCounter == 2) {
                        this->setTarget(rawInput.substr(start + 1, i - (start + 1)));
                    }

                    if (paramCounter == 3) {
                        this->setValue(rawInput.substr(start + 1, i - start));
                    }

                    start = i;
                    paramCounter++;
                }
            }

            size_t startString = rawInput.find_first_of('"');
            size_t endString = rawInput.find_last_of('"');

            if (startString != std::string::npos && endString != std::string::npos) {
                startString = startString + 1;
                this->setValue(rawInput.substr(startString, endString - startString));
            }
        }

        int getOperation() {
            return this->operation;
        }

        std::string getTarget() {
            return this->target;
        }

        std::string getValue() {
            return this->value;
        }
};

#endif // COMMAND_H
