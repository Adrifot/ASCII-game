#pragma once
#include <exception>

class ErrNoMoney : public std::exception {
public:
    const char* what() const noexcept override {return "ERROR: You don't have enough money for that.\n";}
};

