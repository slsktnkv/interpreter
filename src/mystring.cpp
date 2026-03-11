#include "mystring.h"
#include "value.h"

MyString::MyString() : data_{} {
}

MyString::MyString(std::string str) : data_(std::move(str)) {
}

std::string MyString::ToString() const {
    return data_;
}

Value& MyString::Add(const Value& other) {
    const auto& other_string = dynamic_cast<const MyString&>(other);
    data_ += other_string.data_;
    return *this;
}
