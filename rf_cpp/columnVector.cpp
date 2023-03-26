//
// Created by piotr on 25.03.23.
//
#include "columnVector.h"

ColumnVector::ColumnVector() {

}

template<typename T>
void ColumnVector::addColumn(Column<T> column) {
    columns_.push_back(column);
}