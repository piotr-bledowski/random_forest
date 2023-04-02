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
#include <map>

// using std::variant here to ensure flexibility (basically the columns vector may store Columns of multiple data types)
using column_t = std::variant<Column<long>, Column<double>, Column<std::string>, Column<bool>>;

class DataFrame {
private:
    std::vector<std::string> row_labels_;
    std::map<std::string, column_t> columns_;

public:
    DataFrame(std::vector<std::string> row_labels, std::vector<std::string> column_labels, std::vector<column_t> columns);

    std::map<std::string, column_t> getAllColumns() const {
        return columns_;
    }

    std::map<std::string, column_t> getColumns(std::vector<std::string> column_names) const;

    template <typename T>
    std::vector<T> getColumn(std::string column_name) const {
        return columns_.at(column_name);
    }
};