//
// Created by piotr on 22.03.23.
//
#include "column.h"
#include <vector>
#include <string>

template <typename T>
Column<T>::Column(std::vector<T> col_data) {
    cells_ = col_data;

}

template <typename T>
bool Column<T>::operator == (const Column &col) {
    for (int i = 0; i < cells_.size(); i++) {
        if (cells_[i] != col.getCells()[i])
            return false;
    }

    return true;
}