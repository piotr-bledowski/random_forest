//
// Created by piotr on 14/04/2023.
//

#ifndef RF_CPP_DECISIONTREE_H
#define RF_CPP_DECISIONTREE_H

#endif //RF_CPP_DECISIONTREE_H

#include <vector>
#include "../dataFrame/dataFrame.h"
#include "../utils/informationUtils.h"

class DecisionTree {
private:
    DataFrame data_;
public:
    // Returns a pair of lists of indeces (first - left, second - right)
    std::pair<std::vector<size_t>, std::vector<size_t>> createSplit() {

    }
};