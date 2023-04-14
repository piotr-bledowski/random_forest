cmake_minimum_required(VERSION 3.24)
project(rf_cpp)

set(CMAKE_CXX_STANDARD 20)

add_executable(rf_cpp main.cpp rapidcsv.h dataFrame/dataFrame.h dataFrame/dataFrame.cpp dataFrame/column.h dataFrame/column.cpp tests/catch.hpp tests/tests.cpp utils/informationUtils.h model/decisionTree.h model/decisionTree.cpp dataFrame/numericColumn.cpp dataFrame/numericColumn.h)
