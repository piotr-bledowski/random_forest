//
// Created by piotr on 25.03.23.
//

#ifndef RF_CPP_COLUMNVECTOR_H
#define RF_CPP_COLUMNVECTOR_H

#endif //RF_CPP_COLUMNVECTOR_H


#include "column.h"
#include <vector>
#include <string>
#include <variant>

// The sole purpose of this class is to keep this absolute behemoth of a variant in one place, so I don't have to rewrite it
class ColumnVector {
private:

    std::vector<std::variant<Column<int>, Column<long>, Column<float>, Column<double>, Column<std::string>, Column<bool>>> columns_;
public:
    ColumnVector();



    template <typename T>
    void addColumn(Column<T> column);
};