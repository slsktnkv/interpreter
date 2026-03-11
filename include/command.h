#pragma once

#include <string>

#include "value.h"

struct Command {
    enum class Type {
        Set,
        Add,
        Print,
    };
    Type type;
    std::string var;
    Value* operand;
};
