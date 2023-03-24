//
// Created by piotr on 20.03.23.
//

#ifndef RF_CPP_DATAFRAME_H
#define RF_CPP_DATAFRAME_H

#endif //RF_CPP_DATAFRAME_H

#include "rapidcsv.h"
#include <vector>

class dataFrame {
private:
    rapidcsv::Document doc_;

public:
    dataFrame(std::string doc_name);

    template <typename T> std::vector<std::vector<T>> get_columns(std::vector<std::string> column_names);


};