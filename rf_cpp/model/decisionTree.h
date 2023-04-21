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
#include "node.h"
#include <any>

using split_indices = std::pair<std::vector<size_t>, std::vector<size_t>>;

class DecisionTree {
private:
    DataFrame data_;
    size_t max_depth_;
    size_t min_samples_split_;
public:
    DecisionTree(DataFrame data, size_t max_depth = 100, size_t min_samples_split = 2) : data_(data) {
        max_depth_ = max_depth;
        min_samples_split_ = min_samples_split;
    }

    // Recursion depth limit. Also, tree is supposed to stop building when it reaches a set consisting of only 1 class
    bool isFinished(size_t depth, size_t n_samples, size_t n_classes) {
        if (depth >= max_depth_ || n_samples < min_samples_split_ || n_classes == 1)
            return false;
        return true;
    }

    // Returns a pair of lists of indices (first - left, second - right)
    template <typename T>
    split_indices createSplit(std::string feature, T threshold) {
        std::vector<size_t> left_indices = std::get<Column<T>*>(data_.getColumn(feature))->indicesWhere(&less_equal, threshold);
        std::vector<size_t> right_indices = std::get<Column<T>*>(data_.getColumn(feature))->indicesWhere(&greater_than, threshold);
        return split_indices(left_indices, right_indices);
    }

    // Returns a pair of feature and threshold
    template <typename target_T>
    std::pair<std::string, std::any> bestSplit(const std::vector<std::string>& features, const std::string& target) {
        double max_gain = -1.0;
        std::string best_feature = "";
        double best_threshold = 0.0;

        for (std::string feature : features) {
            column_t column = data_.getColumn(feature);
            std::type_index type = data_.getType(feature);

            if (type == typeid(long)) {
                std::vector<long> thresholds = std::get<Column<long>*>(column)->data();

                for (long threshold : thresholds) {
                    double gain = informationGain<long, target_T>(feature, target, threshold);

                    if (gain > max_gain) {
                        max_gain = gain;
                        best_feature = feature;
                        best_threshold = threshold;
                    }
                }
            }
            else if (type == typeid(double)) {
                std::vector<double> thresholds = std::get<Column<double>*>(column)->data();

                for (double threshold : thresholds) {
                    double gain = informationGain<double, target_T>(feature, target, threshold);

                    if (gain > max_gain) {
                        max_gain = gain;
                        best_feature = feature;
                        best_threshold = threshold;
                    }
                }
            }
            else {
                throw std::runtime_error("The extrement has impacted the rotating blades!");
            }
        }

        return std::make_pair(best_feature, best_threshold);
    }

    template <typename feature_T, typename target_T>
    double informationGain(std::string feature, std::string target, feature_T threshold) {
        Column<target_T>* parent = std::get<Column<target_T>*>(data_.getColumn(target));
        double parent_entropy = entropy<target_T>(parent->data());

        split_indices children = createSplit<feature_T>(feature, threshold);
        std::vector<size_t> left_indices = children.first;
        std::vector<size_t> right_indices = children.second;

        if (left_indices.empty() || right_indices.empty())
            return 0.0;

        auto n = (double) parent->data().size();
        auto left_n = (double) left_indices.size();
        auto right_n = (double) right_indices.size();

        double child_entropy = left_n / n * entropy(parent->getRows(left_indices).data()) + right_n / n * entropy(parent->getRows(right_indices).data());

        return parent_entropy - child_entropy;
    }
};