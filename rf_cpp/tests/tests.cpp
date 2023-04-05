//
// Created by piotr on 26.03.23.
//
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "../dataFrame.h"
#include <limits> // standard-defined value of epsilon for float comparisons

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

TEST_CASE("Column.median() returns correct value for integers and odd length", "[Column.median()]") {
    std::vector<long> nums = {345, 23, 76, 6, 9, 96, 123, 666, 777};
    double median = 96.0;
    Column<long> nums_column = Column<long>(nums);

    REQUIRE(median == nums_column.median());
}

TEST_CASE("Column.median() returns correct value for floats and even length", "[Column.median()]") {
    std::vector<double> nums = {65.34, 45.4, 76.15, 6.6, 9999.99324, 96.43, 123.123, 777.0};
    double median = 86.29;
    Column<double> nums_column = Column<double>(nums);

    REQUIRE(std::abs(median - nums_column.median()) < std::numeric_limits<double>::epsilon());
}

TEST_CASE("Column.min() and Column.max() return correct value for integers", "[Column.min(), Column.max()]") {
    std::vector<long> nums = {5, 2, 567, 345, 34, 76, 234, 65, 94, 27, 34578, 835, 74923467};
    long min_val = 2;
    long max_val = 74923467;
    Column<long> nums_column = Column<long>(nums);

    REQUIRE(min_val == nums_column.min());
    REQUIRE(max_val == nums_column.max());
}

TEST_CASE("Column.min() and Column.max() return correct value for floats", "[Column.min(), Column.max()]") {
    std::vector<double> nums = {5.6, 2.3, 9.21, 7.2};
    double min_val = 2.3;
    double max_val = 9.21;
    Column<double> nums_column = Column<double>(nums);

    REQUIRE(std::abs(min_val - nums_column.min()) < std::numeric_limits<double>::epsilon());
    REQUIRE(std::abs(max_val - nums_column.max()) < std::numeric_limits<double>::epsilon());
}

TEST_CASE("Column.min() and Column.max() return correct value for strings", "[Column.min(), Column.max()]") {
    std::vector<std::string> names = {"Patrycja", "Adam", "Bartłomiej", "Zofia", "Czesław"};
    std::string min_val = "Adam";
    std::string max_val = "Zofia";
    Column<std::string> names_column = Column<std::string>(names);

    REQUIRE(min_val == names_column.min());
    REQUIRE(max_val == names_column.max());
}

TEST_CASE("Column.getRows() returns correct value", "[Column.getRows()]") {
    std::vector<long> nums = {5, 3, 6, 7, 4, 6, 8, 3, 5, 7};
    std::vector<size_t> indeces = {2, 4, 9};
    std::vector<long> expected_nums = {6, 4, 7};
    Column<long> nums_column = Column<long>(nums);

    REQUIRE(expected_nums == nums_column.getRows(indeces).data());
}

