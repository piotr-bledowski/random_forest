//
// Created by piotr on 20.03.23.
//
#include "dataFrame.h"
#include "rapidcsv.h"
#include "column.h"
#include "utils/vectorUtils.h"

DataFrame::DataFrame(std::string doc_name) {
    //doc_ = rapidcsv::Document(doc_name, rapidcsv::LabelParams(0, 0));
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

