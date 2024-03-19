#pragma once
#include <exception>
#include <memory>
#include <string>

class WrongInput : public std::exception {
private:
    char errval;
    std::unique_ptr<char[]> errorMsg;

public:
    WrongInput() : errorMsg(nullptr) {}
    WrongInput(char val) : errval(val) {
        errorMsg = std::make_unique<char[]>(50);
        snprintf(errorMsg.get(), 50, "ERROR: wrong user input. %c is not a valid input in this context.\n", errval);
    }

    const char* what() const noexcept override {
        return errorMsg.get();
    }
};

