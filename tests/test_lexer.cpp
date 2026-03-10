#include <catch2/catch_test_macros.hpp>

#include "lexer.h"

TEST_CASE("TokenizePrint", "[Lexer][Tokenize]") {
    std::string line = "PRINT a";
    auto tokens = Tokenize(line);
    REQUIRE(tokens.size() == 2);
    REQUIRE(tokens[0] == "PRINT");
    REQUIRE(tokens[1] == "a");
}

TEST_CASE("TokenizeSet", "[Lexer][Tokenize]") {
    std::string line = "SET a 1";
    auto tokens = Tokenize(line);
    REQUIRE(tokens.size() == 3);
    REQUIRE(tokens[0] == "SET");
    REQUIRE(tokens[1] == "a");
    REQUIRE(tokens[2] == "1");
}

TEST_CASE("TokenizeList", "[Lexer][Tokenize]") {
    std::string line = "ADD b [1 2 3]";
    auto tokens = Tokenize(line);
    REQUIRE(tokens.size() == 3);
    REQUIRE(tokens[0] == "ADD");
    REQUIRE(tokens[1] == "b");
    REQUIRE(tokens[2] == "[1 2 3]");
}