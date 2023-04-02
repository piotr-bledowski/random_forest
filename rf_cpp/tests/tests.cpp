//
// Created by piotr on 26.03.23.
//
#include "catch.hpp"
#include "../dataFrame.h"

// DataFrame test cases

TEST_CASE("DataFrame.getAllColumns returns correct value", "[getAllColumns]") {
    std::vector<std::string> names = {"John", "Jane", "Josh"};
    column names_column = Column<std::string>("Name", names);
    std::vector<long> ages = {34, 35, 20};
    column age_column = Column<long>("Age", ages);
    std::vector<double> some_floats = {4.5, 5.0, 3.5};
    column some_floats_column = Column<double>("Some_float", some_floats);

    std::vector<std::string> row_labels = {"1", "2", "3"};
    std::vector<column> columns = {names_column, age_column, some_floats_column};

    DataFrame dataFrame = DataFrame(row_labels, columns);

    REQUIRE(columns == dataFrame.getAllColumns());
}

TEST_CASE("DataFrame.getAllColumns returns correct value", "[getColumn]") {
    
}