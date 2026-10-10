#ifndef COMMAND_H
#define COMMAND_H

#include <string>

class Command {
    protected:
        std::string name;

    public:
        Command(std::string name) {
            this->name = name;
        }

        std::string getName() {
            return this->name;
        }

        void setName(std::string name) {
            this->name = name;
        }
};

class CommandStr : Command {
    private:
        std::string value;

    public:
        CommandStr(std::string name, std::string value) : Command(name) {
            this->name = name;
            this->value = value;
        }

        std::string getValue() {
            return this->value;
        }

        void setValue(std::string value) {
            this->value = value;
        }
};

class CommandInt : Command {
    private:
        int value;

    public:
        CommandInt(std::string name, int value) : Command(name) {
            this->name = name;
            this->value = value;
        }

        int getValue() {
            return this->value;
        }

        void setValue(int value) {
            this->value = value;
        }
};

class CommandBool : Command {
    private:
        bool value;

    public:
        CommandBool(std::string name, bool value) : Command(name) {
            this->name = name;
            this->value = value;
        }

        bool getValue() {
            return this->value;
        }

        void setValue(bool value) {
            this->value = value;
        }
};

#endif // COMMAND_H
