#include "integer.h"

Integer::Integer() : value_{} {
}
Integer::Integer(int value) : value_(value) {
}

std::string Integer::ToString() const {
    return std::to_string(value_);
}

Value& Integer::Add(const Value& other) {
    const Integer& other_integer = dynamic_cast<const Integer&>(other);
    value_ += other_integer.value_;
    return *this;
}

int Integer::GetValue() const {
    return value_;
}
