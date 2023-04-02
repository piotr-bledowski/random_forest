cmake_minimum_required(VERSION 3.24)
project(rf_cpp)

set(CMAKE_CXX_STANDARD 20)

add_executable(rf_cpp main.cpp rapidcsv.h dataFrame.h dataFrame.cpp column.h column.cpp utils/vectorUtils.h utils/vectorUtils.cpp tests/catch.hpp tests/tests.cpp columnWrapper.h columnWrapper.cpp)
