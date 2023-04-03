//
// Created by piotr on 22.03.23.
//

#ifndef RF_CPP_COLUMN_H
#define RF_CPP_COLUMN_H

#endif //RF_CPP_COLUMN_H


#include "rapidcsv.h"
#include <vector>
#include <string>
#include <variant>

//using column_t = std::variant<long, double, bool, std::string>;

template <typename T>
class Column {
private:
    std::vector<T> cells_;
public:
    Column(std::vector<T> col_data) {
        cells_ = col_data;
    }

    std::vector<T> data() {
        return cells_;
    }

    bool operator == (const Column &col) {
        for (int i = 0; i < cells_.size(); i++) {
            if (cells_[i] != col.data()[i])
                return false;
        }

        return true;
    }
};