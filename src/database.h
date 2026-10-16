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

            for (Data item : this->data) {
                if(item.getTarget().find(target) != std::string::npos) {
                    filteredItems.push_back(item);
                }
            }

            return filteredItems;
        }

        void add(Data item) {
            this->data.push_back(item);
        }

        int remove(std::string target) {
            std::vector<Data> newData;
            int amountRemovedItems = 0;

            for (Data item : this->data) {
                if(item.getTarget() != target) {
                    newData.push_back(item);
                } else {
                    amountRemovedItems++;
                }
            }

            this->data = newData;

            return amountRemovedItems;
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
