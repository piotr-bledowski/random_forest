//
// Created by piotr on 20.03.23.
//
#include "dataFrame.h"
#include "rapidcsv.h"
#include "utils/vectorUtils.h"

DataFrame::DataFrame(std::vector<std::string> row_labels, std::vector<std::string> column_names, std::vector<column_t> columns) {
    row_labels_ = row_labels;
    for (int i = 0; i < column_names.size(); i++) {
        columns_[column_names[i]] = columns[i];
    }
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


