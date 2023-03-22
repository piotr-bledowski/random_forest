//
// Created by piotr on 20.03.23.
//
#include "dataFrame.h"
#include "rapidcsv.h"

dataFrame::dataFrame(std::string doc_name) {
    doc_ = rapidcsv::Document(doc_name, rapidcsv::LabelParams(0, 0));
}

template <typename T> std::vector<std::vector<T>> get_columns(std::vector<std::string> column_names) {

}