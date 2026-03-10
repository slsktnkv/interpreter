#pragma once

#include "value.h"

class Integer : public Value {
public:
    Integer();
    explicit Integer(int value);
    std::string ToString() const override;
    Value& Add(const Value& other) override;
    int GetValue() const;

private:
    int value_;
};
