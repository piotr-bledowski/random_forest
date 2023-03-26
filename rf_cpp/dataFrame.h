//
// Created by piotr on 20.03.23.
//

#ifndef RF_CPP_DATAFRAME_H
#define RF_CPP_DATAFRAME_H

#endif //RF_CPP_DATAFRAME_H

#include "rapidcsv.h"
#include <vector>
#include "column.h"
#include <variant>

// using std::variant here to ensure flexibility (basically the columns vector may store Columns of multiple data types)
using column = std::variant<Column<long>, Column<double>, Column<std::string>, Column<bool>>;

class DataFrame {
private:
    std::vector<std::string> row_labels_;
    std::vector<column> columns_;

public:
    DataFrame(std::string doc_name);

    template <typename T> std::vector<std::vector<T>> getColumns(std::vector<std::string> column_names);

    std::vector<column> getAllColumns() const {
        return columns_;
    }

    std::vector<column> getColumns(std::vector<std::string> column_names) const;

    template <typename T>
    Column<T> getColumn(std::string column_name) const;
};