#include <sstream>

#include <catch2/catch_test_macros.hpp>

#include "interpreter.h"

TEST_CASE("SetAndPrint", "[Interpreter][Set]") {
    std::string actual;
    std::ostringstream output(actual);
    Interpreter interpreter(output);
    interpreter.Evaluate("SET a 1");
    interpreter.Evaluate("PRINT a");
    REQUIRE(output.str() == "1\n");
}

TEST_CASE("SetAndAdd", "[Interpreter][Add]") {
    std::string actual;
    std::ostringstream output(actual);
    Interpreter interpreter(output);
    interpreter.Evaluate("SET a 1");
    interpreter.Evaluate("ADD a 2");
    interpreter.Evaluate("PRINT a");
    REQUIRE(output.str() == "3\n");
}

/*
TEST_CASE("LinkedAdd", "[Interpreter][Add][Link]") {
    std::string actual;
    std::ostringstream output(actual);
    Interpreter interpreter(output);
    interpreter.Evaluate("SET a 1");
    interpreter.Evaluate("SET b a");
    interpreter.Evaluate("ADD a 2");
    interpreter.Evaluate("PRINT a");
    interpreter.Evaluate("PRINT b");
    interpreter.Evaluate("ADD b 3");
    interpreter.Evaluate("PRINT a");
    interpreter.Evaluate("PRINT b");
    REQUIRE(output.str() == "3\n3\n6\n6\n");
}
*/
