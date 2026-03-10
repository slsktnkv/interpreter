#include <iostream>
#include <stdexcept>
#include <string>

#include "include/interpreter.h"

int main() {
    std::cout << "Simple interpreter v0" << std::endl;
    std::cout << "> ";
    std::cout.flush();
    std::string line;
    Interpreter interpreter(std::cout);
    while (std::getline(std::cin, line)) {
        try {
            interpreter.Evaluate(line);
        } catch (const std::invalid_argument& e) {
            std::cout << "Error: " << e.what() << std::endl;
        }
        std::cout << "> ";
        std::cout.flush();
    }
}
