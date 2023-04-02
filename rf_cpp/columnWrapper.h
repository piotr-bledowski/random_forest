//
// Created by piotr on 01.04.23.
//

#ifndef RF_CPP_COLUMNWRAPPER_H
#define RF_CPP_COLUMNWRAPPER_H

#endif //RF_CPP_COLUMNWRAPPER_H

#include <variant>
#include "column.h"

using column_variant = std::variant<Column<long>, Column<double>, Column<bool>, Column<std::string>>;

// This class exists only to implement an overloaded == operator for Column variant
class ColumnWrapper {
private:
    column_variant column_;
public:
    ColumnWrapper(std::vector<column_variant> column) {
        //column_ = column;
    }
};