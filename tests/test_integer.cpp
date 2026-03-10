#include <catch2/catch_test_macros.hpp>

#include "integer.h"

TEST_CASE("Integer", "[Integer][default]") {
    Integer a;
    REQUIRE(a.GetValue() == 0);
    REQUIRE(a.ToString() == "0");
}