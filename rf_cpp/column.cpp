//
// Created by piotr on 22.03.23.
//
#include "column.h"
#include <vector>
#include <string>

template <typename T>
Column<T>::Column(std::string col_label, std::vector<T> col_data) {
    label_ = col_label;
    cells_ = col_data;
}

