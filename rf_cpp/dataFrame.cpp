//
// Created by piotr on 20.03.23.
//
#include "dataFrame.h"
#include "rapidcsv.h"
#include "column.h"

dataFrame::dataFrame(std::string doc_name) {
    doc_ = rapidcsv::Document(doc_name, rapidcsv::LabelParams(0, 0));
}

template <typename T> std::vector<std::vector<T>> dataFrame::get_columns(std::vector<std::string> column_names) {
    std::vector<std::vector<T>> columns;
    for (std::string name : column_names) {
        columns.push_back(doc_.GetColumn<T>(name));
    }

    return columns;
}

