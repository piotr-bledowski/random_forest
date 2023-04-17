//
// Created by piotr on 14/04/2023.
//

#ifndef RF_CPP_DECISIONTREE_H
#define RF_CPP_DECISIONTREE_H

#endif //RF_CPP_DECISIONTREE_H

#include <vector>
#include "../dataFrame/dataFrame.h"
#include "../utils/informationUtils.h"
#include "../utils/expressions.h"

class DecisionTree {
private:
    DataFrame data_;
public:
    // Returns a pair of lists of indices (first - left, second - right)
    template <typename T>
    std::pair<std::vector<size_t>, std::vector<size_t>> createSplit(std::string feature, T threshold) {
        std::vector<size_t> left_indices = std::get<T>(data_.getColumn(feature))->indicesWhere(&less_equal, threshold);
        std::vector<size_t> right_indices = std::get<T>(data_.getColumn(feature))->indicesWhere(&greater_than, threshold);
        return std::pair<std::vector<size_t>, std::vector<size_t>>(left_indices, right_indices);
    }
};