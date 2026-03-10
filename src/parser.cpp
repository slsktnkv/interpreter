#include "parser.h"

#include <charconv>
#include <stdexcept>

Command MakeCommand(const std::vector<std::string_view>& tokens) {
    if (tokens.size() == 2) {
        if (tokens[0] == "PRINT") {
            return Command{.type = Command::Type::Print, .var = std::string(tokens[1]), .operand = {}};
        }
    }
    if (tokens.size() == 3) {
        if (tokens[0] == "SET") {
            return Command{
                .type = Command::Type::Set, .var = std::string(tokens[1]), .operand = MakeInteger(tokens[2])};
        }
        if (tokens[0] == "ADD") {
            return Command{
                .type = Command::Type::Add, .var = std::string(tokens[1]), .operand = MakeInteger(tokens[2])};
        }
    }
    throw std::invalid_argument("Invalid syntax");
}

Integer MakeInteger(std::string_view operand) {
    int result{};
    auto [ptr, ec] = std::from_chars(operand.data(), operand.data() + operand.size(), result);
    if (ec != std::errc()) {
        throw std::invalid_argument("Invalid integer");
    }
    return Integer(result);
}