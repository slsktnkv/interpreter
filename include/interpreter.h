#pragma once

#include <ostream>
#include <string>
#include <map>

#include "integer.h"

class Interpreter {
public:
    explicit Interpreter(std::ostream& output);
    void Evaluate(const std::string& line);

private:
    std::ostream& output_;
    std::map<std::string, Integer> namespace_;
};
