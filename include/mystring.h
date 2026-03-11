#pragma once

#include <string>

#include "value.h"

class MyString : public Value {
public:
    MyString();
    explicit MyString(std::string str);
    std::string ToString() const override;
    Value& Add(const Value& other) override;
private:
    std::string data_;
};