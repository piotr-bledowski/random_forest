//
// Created by piotr on 20.03.23.
//
#include "dataFrame.h"
#include "../rapidcsv.h"

DataFrame::DataFrame(const std::vector<std::string>& row_labels, const std::vector<std::string>& column_names, const std::vector<column_t>& columns) {
    row_labels_ = row_labels;
    for (int i = 0; i < column_names.size(); i++) {
        columns_[column_names[i]] = columns[i];
    }
}

DataFrame DataFrame::sub(const std::vector<size_t>& row_indeces, const std::vector<std::string>& columns) {
    std::vector<std::string> new_row_labels;
    std::vector<column_t> new_columns;

    for (size_t i : row_indeces) {
        new_row_labels.push_back(row_labels_[i]);
    }

    for (const std::string& column_name : columns) {
        new_columns.push_back(getColumn(column_name));
    }

    return DataFrame(new_row_labels, columns, new_columns);
}

//std::vector<column_t> DataFrame::getColumns(std::vector<std::string> column_names) const {
//    std::vector<column_t> columns;
//    for (column_t col : columns_) {
//        if (isInVector(getColumnVariantLabel(col), column_names)) {
//            columns.push_back(col);
//        }
//    }
//
//    return columns;
//}


