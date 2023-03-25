//
// Created by piotr on 22.03.23.
//

#ifndef RF_CPP_COLUMN_H
#define RF_CPP_COLUMN_H

#endif //RF_CPP_COLUMN_H


#include "rapidcsv.h"
#include <vector>
#include <string>


template <typename T>
class Column {
private:
    std::string label_;
    std::vector<T> cells_;
public:
    Column(std::string col_label, std::vector<T> col_data);

    std::string get_label() {
        return label_;
    }

    std::vector<T> get_cells() {
        return cells_;
    }
};