//
// Created by piotr on 06/04/2023.
//

#ifndef RF_CPP_INFORMATIONUTILS_H
#define RF_CPP_INFORMATIONUTILS_H

#endif //RF_CPP_INFORMATIONUTILS_H

#include <vector>
#include <map>
#include <cmath>
#include <numeric>

template <typename T>
double entropy(const std::vector<T>& data) {
    std::map<T, double> proportions;

    // Counting occurences
    for (T num : data) {
        if (proportions.contains(num)) {
            proportions[num]++;
        }
        else {
            proportions[num] = 1;
        }
    }

    // Dividing # of occurences / length of the array, which results in proportions
    auto it = proportions.begin();

    std::vector<double> entropies;

    while(it != proportions.end()) {
        // proportion calculation
        it->second /= (double) data.size();
        // calculating entropies
        entropies.push_back(it->second * std::log2(it->second));
        it++;
    }

    // sum of these values is the entropy of given data
    return -std::accumulate(entropies.begin(), entropies.end(), 0.0);
}