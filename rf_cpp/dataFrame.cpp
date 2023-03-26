//
// Created by piotr on 20.03.23.
//
#include "dataFrame.h"
#include "rapidcsv.h"
#include "column.h"
#include "utils/vectorUtils.h"

DataFrame::DataFrame(std::vector<std::string> row_labels, std::vector<column> columns) {
    row_labels_ = row_labels;
    columns_ = columns;
}


std::vector<column> DataFrame::getColumns(std::vector<std::string> column_names) const {
    std::vector<column> columns;
    for (column col : columns_) {
        if (isInVector(getColumnVariantLabel(col), column_names)) {
            columns.push_back(col);
        }
    }

    return columns;
}

template <typename T>
Column<T> DataFrame::getColumn(std::string column_name) const {
    for (column col : columns_) {
        if (getColumnVariantLabel(col) == column_name)
            return col;
    }

    return NULL;
}

