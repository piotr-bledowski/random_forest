//
// Created by piotr on 14/04/2023.
//

#ifndef RF_CPP_NUMERICCOLUMN_H
#define RF_CPP_NUMERICCOLUMN_H

#endif //RF_CPP_NUMERICCOLUMN_H

#include "column.h"

class FloatNumericColumn : public Column<double> {
public:
    FloatNumericColumn(const std::vector<double>& col_data);

    double mean();

    double median();
};

class IntNumericColumn : public Column<long> {
public:
    IntNumericColumn(const std::vector<long>& col_data);

    double mean();

    double median();
};