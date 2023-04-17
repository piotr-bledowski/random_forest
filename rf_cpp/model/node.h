//
// Created by piotr on 17/04/2023.
//

#ifndef RF_CPP_NODE_H
#define RF_CPP_NODE_H

#endif //RF_CPP_NODE_H

#include <string>

template <typename T>
class Node {
private:
    std::string feature_;
    T* threshold_;
    Node* left_;
    Node* right_;
    T* value_;
public:
    Node(const std::string& feat, T* thresh, Node* l, Node* r, T* val = nullptr) {
        feature_ = feat;
        threshold_ = thresh;
        left_ = l;
        right_ = r;
        value_ = val;
    }

    std::string feature() {
        return feature_;
    }

    T threshold() {
        return *threshold_;
    }

    Node* left() {
        return left_;
    }

    Node* right() {
        return right_;
    }

    T value() {
        return *value_;
    }

    bool isLeaf() {
        return value_ != nullptr;
    }
};