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
#include <numeric>

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

    double mean() {
        //! mean method should only be callable for numeric columns
        if (std::is_same<T, std::string>::value || std::is_same<T, bool>::value)
            throw std::runtime_error("Cannot call mean() for non-numeric columns!");

        if (std::is_same<T, long>::value) {
            std::vector<double> double_cells(cells_.begin(), cells_.end());
            return std::accumulate(double_cells.begin(), double_cells.end(), 0.0) / (double) double_cells.size();
        }

        //! IMPORTANT NOTE: The last argument of std::accumulate also specifies the return type!
        return std::accumulate(cells_.begin(), cells_.end(), 0.0) / (double) cells_.size();
    }

//    double median() {
//
//    }

    bool operator == (const Column &col) {
        for (int i = 0; i < cells_.size(); i++) {
            if (cells_[i] != col.data()[i])
                return false;
        }

        return true;
    }
};