//
// Created by piotr on 26.03.23.
//
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "../dataFrame.h"
#include <limits> // standard-defined value of epsilon

// DataFrame test cases

TEST_CASE("DataFrame.getColumn returns correct value", "[getColumn]") {
    std::vector<std::string> names = {"John", "Jane", "Josh"};
    Column<std::string> names_column = Column<std::string>(names);
    column_t col1 = &names_column;
    std::vector<long> ages = {34, 35, 20};
    Column<long> age_column = Column<long>(ages);
    column_t col2 = &age_column;
    std::vector<double> some_floats = {4.5, 5.0, 3.5};
    Column<double> some_floats_column = Column<double>(some_floats);
    column_t col3 = &some_floats_column;

    std::vector<std::string> row_labels = {"1", "2", "3"};
    std::vector<std::string> column_labels = {"name", "age", "some_float"};
    std::vector<column_t> columns = {&names_column, &age_column, &some_floats_column};

    DataFrame dataFrame = DataFrame(row_labels, column_labels, columns);

    REQUIRE(names == dataFrame.getColumn<std::string>("name").data());
    REQUIRE(ages == dataFrame.getColumn<long>("age").data());
    REQUIRE(some_floats == dataFrame.getColumn<double>("some_float").data());
}

// Column test cases

<<<<<<< HEAD
TEST_CASE("Column.mean() returns correct value for integers", "[Column.mean()]") {
=======
TEST_CASE("Column.mean() returns correct value for integer values", "[Column.mean()]") {
>>>>>>> 27a3d7690830d3b14329382b288aa5d4ade322c5
    std::vector<long> nums = {10, 15, 12, 13, 9, 16};
    double mean = 12.5;
    Column<long> nums_column = Column<long>(nums);

    REQUIRE(std::abs(mean - nums_column.mean()) < std::numeric_limits<double>::epsilon());
}

<<<<<<< HEAD
TEST_CASE("Column.mean() returns correct value for floats", "[Column.mean()]") {
    std::vector<double> nums = {4.4, 6.66, 8.888, 2.0};
    double mean = 5.487;
    Column<double> nums_column = Column<double>(nums);
=======
TEST_CASE("Column.mean() returns correct value for float values", "[Column.mean()]") {
    std::vector<double> nums = {235.345, 15.34, 12.73, 13.0, 54234.234, 16.67, 7.777777};
    double mean = 7790.728111;
    Column<double> nums_column = Column<double>(nums);
    double col_mean = nums_column.mean();
>>>>>>> 27a3d7690830d3b14329382b288aa5d4ade322c5

    REQUIRE(std::abs(mean - nums_column.mean()) < std::numeric_limits<double>::epsilon());
}

//TEST_CASE("DataFrame.getAllColumns returns correct value", "[getAllColumns]") {
//
//}