//
// Created by piotr on 26.03.23.
//
#include "catch.hpp"
#include "../dataFrame.h"

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

    REQUIRE(names == dataFrame.getColumn<std::string>("names"));
}

TEST_CASE("DataFrame.getAllColumns returns correct value", "[getColumn]") {
    
}