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

TEST_CASE("DataFrame.containsColumn returns correct value", "[containsColumn]") {
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

    REQUIRE(dataFrame.containsColumn("name") == true);
    REQUIRE(dataFrame.containsColumn("age") == true);
    REQUIRE(dataFrame.containsColumn("some_float") == true);
    REQUIRE(dataFrame.containsColumn("some_non-existent_column") == false);
}

// Column test cases

TEST_CASE("Column.mean() returns correct value for integers", "[Column.mean()]") {
    std::vector<long> nums = {10, 15, 12, 13, 9, 16};
    double mean = 12.5;
    Column<long> nums_column = Column<long>(nums);

    REQUIRE(std::abs(mean - nums_column.mean()) < std::numeric_limits<double>::epsilon());
}

TEST_CASE("Column.mean() returns correct value for floats", "[Column.mean()]") {
    std::vector<double> nums = {4.4, 6.66, 8.888, 2.0};
    double mean = 5.487;
    Column<double> nums_column = Column<double>(nums);

    REQUIRE(std::abs(mean - nums_column.mean()) < std::numeric_limits<double>::epsilon());
}

//TEST_CASE("DataFrame.getAllColumns returns correct value", "[getAllColumns]") {
//
//}