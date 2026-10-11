#ifndef DATA_H
#define DATA_H

#include <string>

class Data {
    private:
        std::string table;
        int id;
        std::string value;

    public:
        Data(std::string table, int id, std::string value) {
            this->table = table;
            this->id = id;
            this->value = value;
        }

        std::string getTable() {
            return this->table;
        }

        int getId() {
            return this->id;
        }

        std::string getValue() {
            return this->value;
        }

        void setValue(std::string value) {
            this->value = value;
        }
};

#endif // DATA_H
