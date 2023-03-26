//
// Created by piotr on 25.03.23.
//

#include "vectorUtils.h"
#include <vector>
#include <variant>

template <typename T>
bool isInVector(T element, std::vector<T> v) {
    if (std::count(v.begin(), v.end(), element))
        return true;
    return false;
}

std::string getColumnVariantLabel(column col) {
    if (std::holds_alternative<Column<long>>(col))
        return std::get<Column<long>>(col).getLabel();
    if (std::holds_alternative<Column<double>>(col))
        return std::get<Column<double>>(col).getLabel();
    if (std::holds_alternative<Column<bool>>(col))
        return std::get<Column<bool>>(col).getLabel();
    return std::get<Column<std::string>>(col).getLabel();
}