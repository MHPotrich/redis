#ifndef DATABASE_H
#define DATABASE_H

#include "data.h"
#include <iostream>
#include <ostream>
#include <vector>
#include <algorithm>

class Database {
    private:
        std::vector<Data> data;

    public:
        Database() {}

        std::vector<Data> find(std::string target) {
            std::vector<Data> filteredItems;
            bool listAll = target.find(":") != std::string::npos;

            for (Data item : this->data) {
                bool hasTableName = item.getTarget().find(target) != std::string::npos;
                bool isTarget = item.getTarget() == target;

                if(listAll ? isTarget : hasTableName) {
                    filteredItems.push_back(item);
                }
            }

            return filteredItems;
        }

        void add(Data item) {
            this->data.push_back(item);
        }

        void remove(std::string target) {
            std::vector<Data> newData;

            for (Data item : this->data) {
                if(item.getTarget() != target) {
                    newData.push_back(item);
                }
            }

            this->data = newData;
        }

        void update(std::string target, std::string value) {
            for (Data item : this->data) {
                if(item.getTarget() == target) {
                    item.setValue(value);
                }
            }
        }
};

#endif // DATABASE_HS
