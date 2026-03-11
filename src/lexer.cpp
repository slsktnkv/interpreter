#include "lexer.h"

#include <stdexcept>

std::vector<std::string_view> Tokenize(const std::string& line) {
    std::vector<std::string_view> tokens;
    auto first_space = line.find(' ');
    if (first_space == std::string::npos) {
        throw std::invalid_argument("Invalid syntax");
    }
    tokens.emplace_back(line.data(), first_space);
    auto second_space = line.find(' ', first_space + 1);
    if (second_space == std::string::npos) {
        tokens.emplace_back(line.data() + first_space + 1, line.size() - first_space - 1);
    } else {
        tokens.emplace_back(line.data() + first_space + 1, second_space - first_space - 1);
        tokens.emplace_back(line.data() + second_space + 1, line.size() - second_space - 1);
    }
    return tokens;
}