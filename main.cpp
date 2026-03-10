#include <iostream>
#include <string>

#include "include/interpreter.h"

int main() {
    std::cout << "Simple interpreter v0" << std::endl;
    std::cout << "> ";
    std::string line;
    Interpreter interpreter(std::cout);
    while (std::getline(std::cin, line)) {
        interpreter.Evaluate(line);
        std::cout << "> ";
    }
}
