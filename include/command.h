#pragma once

#include <string>

#include "integer.h"

struct Command {
    enum class Type {
        Set,
        Add,
        Print,
    };
    Type type;
    std::string var;
    Integer operand;
};
