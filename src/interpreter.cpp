#include "interpreter.h"
#include <stdexcept>
#include "lexer.h"
#include "parser.h"

Interpreter::Interpreter(std::ostream& output) : output_(output) {
}

void Interpreter::Evaluate(const std::string& line) {
    auto tokens = Tokenize(line);
    auto command = MakeCommand(tokens);
    if (command.type == Command::Type::Print) {
        if (namespace_.contains(command.var)) {
            output_ << namespace_[command.var].ToString() << std::endl;
        } else {
            throw std::invalid_argument("Unknown variable: " + command.var);
        }
    }
    if (command.type == Command::Type::Set) {
        namespace_[command.var] = command.operand;
    }
    if (command.type == Command::Type::Add) {
        if (namespace_.contains(command.var)) {
            namespace_[command.var].Add(command.operand);
        } else {
            throw std::invalid_argument("Unknown variable: " + command.var);
        }
    }
}
