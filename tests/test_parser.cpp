#include <catch2/catch_test_macros.hpp>

#include "lexer.h"
#include "parser.h"

TEST_CASE("ParsePrint", "[Parser][Print]") {
    std::string line = "PRINT a";
    auto tokens = Tokenize(line);
    auto command = MakeCommand(tokens);
    REQUIRE(command.type == Command::Type::Print);
    REQUIRE(command.var == "a");
}

TEST_CASE("ParseSet", "[Parser][Set]") {
    std::string line = "SET b 1";
    auto tokens = Tokenize(line);
    auto command = MakeCommand(tokens);
    REQUIRE(command.type == Command::Type::Set);
    REQUIRE(command.var == "b");
    REQUIRE(command.operand.GetValue() == 1);
}

TEST_CASE("ParseAdd", "[Parser][Add]") {
    std::string line = "ADD c 2";
    auto tokens = Tokenize(line);
    auto command = MakeCommand(tokens);
    REQUIRE(command.type == Command::Type::Add);
    REQUIRE(command.var == "c");
    REQUIRE(command.operand.GetValue() == 2);
}