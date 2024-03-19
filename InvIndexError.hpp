#pragma once
#include <exception>
#include <string>

class InvIndexError : public std::exception {
private:
    int index;
public:
        InvIndexError() {}
        InvIndexError(int _index) : index(_index) {}
        const char* what() const noexcept override {
            static std::string errorMsg = "ERROR: no item with index ";
            errorMsg += std::to_string(index);
            errorMsg += " exists in your inventory.\n";
            return errorMsg.c_str();
        }
};



