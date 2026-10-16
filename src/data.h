#ifndef DATA_H
#define DATA_H

#include <string>

class Data {
    private:
        std::string target;
        std::string value;

    public:
        Data(std::string target, std::string value) {
            this->target = target;
            this->value = value;
        }

        std::string getTarget() {
            return this->target;
        }

        std::string getValue() {
            return this->value;
        }

        void setValue(std::string value) {
            this->value = value;
        }
};

#endif // DATA_H
