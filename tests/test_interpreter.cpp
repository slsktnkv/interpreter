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
TEST_CASE("Strings", "[Interpreter][Add][String]") {
    std::string actual;
    std::ostringstream output(actual);
    Interpreter interpreter(output);
    interpreter.Evaluate("SET b a");
    interpreter.Evaluate("ADD b a");
    interpreter.Evaluate("PRINT b");
    REQUIRE(output.str() == "aa\n");
}

TEST_CASE("StringsMixed", "[Interpreter][Add][String]") {
    std::string actual;
    std::ostringstream output(actual);
    Interpreter interpreter(output);
    interpreter.Evaluate("SET i 0");
    interpreter.Evaluate("SET s a");
    interpreter.Evaluate("ADD i 1");
    interpreter.Evaluate("ADD s 1");
    interpreter.Evaluate("PRINT i");
    interpreter.Evaluate("PRINT s");
    REQUIRE(output.str() == "1\na1\n");
}

TEST_CASE("ListsAppend", "[Interpreter][Add][List]") {
    std::string actual;
    std::ostringstream output(actual);
    Interpreter interpreter(output);
    interpreter.Evaluate("SET l [1 2 3]");
    interpreter.Evaluate("ADD l 4");
    interpreter.Evaluate("PRINT l");
    REQUIRE(output.str() == "[1 2 3 4]\n");
}

TEST_CASE("ListsConcat", "[Interpreter][Add][List]") {
    std::string actual;
    std::ostringstream output(actual);
    Interpreter interpreter(output);
    interpreter.Evaluate("SET l [1 2 3]");
    interpreter.Evaluate("ADD l [4 5 6]");
    interpreter.Evaluate("PRINT l");
    REQUIRE(output.str() == "[1 2 3 4 5 6]\n");
}
*/
