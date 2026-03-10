#pragma once

#include <string>

class Value {
public:
    virtual std::string ToString() const = 0;
    virtual Value& Add(const Value& other) = 0;
    virtual ~Value() = default;
};
