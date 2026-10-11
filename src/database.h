#ifndef DATABASE_H
#define DATABASE_H

#include "data.h"
#include <vector>
#include <algorithm>

class Database {
    private:
        std::vector<Data> data;

    public:
        Database() {}

        std::vector<Data> find(std::string table) {
            std::vector<Data> filteredItems;

            for (Data item : this->data) {
                if(item.getTable() == table) {
                    filteredItems.push_back(item);
                }
            }

            return filteredItems;
        }

        std::vector<Data> find(std::string table, int id) {
            std::vector<Data> filteredByTable = this->find(table);
            std::vector<Data> filteredItems;

            for (Data item : this->data) {
                if(item.getId() == id) {
                    filteredItems.push_back(item);
                }
            }

            return filteredItems;
        }

        void add(Data item) {
            this->data.push_back(item);
        }

        void remove(std::string table, int id) {
            std::vector<Data> newData;

            for (Data item : this->data) {
                if(item.getId() != id && item.getTable() != table) {
                    newData.push_back(item);
                }
            }

            this->data = newData;
        }

        void update(std::string table, int id, std::string value) {
            for (Data item : this->data) {
                if(item.getId() != id && item.getTable() != table) {
                    item.setValue(value);
                }
            }
        }
};

#endif // DATABASE_HS
