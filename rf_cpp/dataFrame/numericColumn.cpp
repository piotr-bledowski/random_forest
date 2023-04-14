//
// Created by piotr on 14/04/2023.
//

#include "numericColumn.h"

FloatNumericColumn::FloatNumericColumn(const std::vector<double>& col_data) : Column<double>(col_data) {
    cells_ = col_data;
    sorted_cells_ = cells_;
    std::sort(sorted_cells_.begin(), sorted_cells_.end());
}

double FloatNumericColumn::mean() {
    //! IMPORTANT NOTE: The last argument of std::accumulate also specifies the return type!
    return std::accumulate(cells_.begin(), cells_.end(), 0.0) / (double) cells_.size();
}

double FloatNumericColumn::median() {
    if (sorted_cells_.size() % 2 == 0)
    return (double) (sorted_cells_[sorted_cells_.size() / 2 - 1] + sorted_cells_[sorted_cells_.size() / 2]) / 2.0;
    return sorted_cells_[sorted_cells_.size() / 2];
}

double FloatNumericColumn::sum() {
    return std::accumulate(cells_.begin(), cells_.end(), 0.0);
}


IntNumericColumn::IntNumericColumn(const std::vector<long>& col_data) : Column<long>(col_data) {
    cells_ = col_data;
    sorted_cells_ = cells_;
    std::sort(sorted_cells_.begin(), sorted_cells_.end());
}

double IntNumericColumn::mean() {
    //! IMPORTANT NOTE: The last argument of std::accumulate also specifies the return type!
    return std::accumulate(cells_.begin(), cells_.end(), 0.0) / (double) cells_.size();
}

double IntNumericColumn::median() {
    if (sorted_cells_.size() % 2 == 0)
        return (double) (sorted_cells_[sorted_cells_.size() / 2 - 1] + sorted_cells_[sorted_cells_.size() / 2]) / 2.0;
    return sorted_cells_[sorted_cells_.size() / 2];
}

long IntNumericColumn::sum() {
    return std::accumulate(cells_.begin(), cells_.end(), 0);
}