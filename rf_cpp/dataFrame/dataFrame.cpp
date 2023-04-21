//
// Created by piotr on 20.03.23.
//
#include "dataFrame.h"
#include "../rapidcsv.h"

DataFrame::DataFrame(const std::vector<std::string>& row_labels, const std::vector<std::string>& column_names, const std::vector<column_t>& columns, std::vector<std::type_index> types) {
    row_labels_ = row_labels;
    for (int i = 0; i < column_names.size(); i++) {
        columns_[column_names[i]] = columns[i];
        // For some weird reason [] notation does not work with std::type_index
        types_.insert(make_pair(column_names[i], types[i]));
    }
}

DataFrame DataFrame::sub(const std::vector<size_t>& row_indices, const std::vector<std::string>& columns) {
    std::vector<std::string> new_row_labels;
    std::vector<column_t> new_columns;
    std::vector<std::type_index> new_types;

    for (size_t i : row_indices) {
        new_row_labels.push_back(row_labels_[i]);
    }

    for (const std::string& column_name : columns) {
        new_columns.push_back(getColumn(column_name));
        new_types.push_back(getType(column_name));
    }

    return DataFrame(new_row_labels, columns, new_columns, new_types);
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


