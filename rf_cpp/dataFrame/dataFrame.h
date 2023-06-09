//
// Created by piotr on 20.03.23.
//

#ifndef RF_CPP_DATAFRAME_H
#define RF_CPP_DATAFRAME_H

#endif //RF_CPP_DATAFRAME_H

#include "../rapidcsv.h"
#include <vector>
#include "column.h"
#include <variant>
#include <unordered_map>
#include <typeindex>

// using std::variant here to ensure flexibility (basically the columns vector may store Columns of multiple data types)
using column_t = std::variant<Column<double>*, Column<long>*, Column<std::string>*, Column<bool>*>;

class DataFrame {
private:
    std::vector<std::string> row_labels_;
    std::map<std::string, std::type_index> types_;
    std::map<std::string, column_t> columns_;
public:
    DataFrame(const std::vector<std::string>& row_labels, const std::vector<std::string>& column_labels, const std::vector<column_t>& columns, std::vector<std::type_index> types);

    std::vector<column_t> getAllColumns() const {
        std::vector<column_t> r;

        auto it = columns_.begin();

        while (it != columns_.end()) {
            r.push_back(it->second);
            it++;
        }

        return r;
    }

    //std::unordered_map<std::string, column_t> getColumns(const std::vector<std::string>& column_names) const;

    std::type_index getType(const std::string& column_name) {
        auto it = types_.find(column_name);

        //! if column_name not in keys
        if (it == types_.end())
            throw std::runtime_error("Column not in dataFrame!");

        return it->second;
    }

    column_t getColumn(const std::string& column_name) {
        auto it = columns_.find(column_name);

        //! if column_name not in keys
        if (it == columns_.end())
            throw std::runtime_error("Column not in dataFrame!");

        return it->second;
    }

//    std::vector<size_t> indices_where(bool (*expression_func_ptr)(long x, long y));
//
//    std::vector<size_t> indices_where(bool (*expression_func_ptr)(double x, double y));

    DataFrame sub(const std::vector<size_t>& row_indices, const std::vector<std::string>& columns);

    DataFrame sub(const std::vector<std::string>& row_labels, const std::vector<std::string>& columns);

    std::vector<std::string> getRowLabels() {
        return row_labels_;
    }

    std::vector<std::string> getColumnLabels() {
        std::vector<std::string> column_names;

        auto it = columns_.begin();

        while (it != columns_.end()) {
            column_names.push_back(it->first);
            it++;
        }

        return column_names;
    }

    bool containsColumn(const std::string& col) {
        return columns_.contains(col);
    }
};