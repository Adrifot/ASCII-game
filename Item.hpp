#pragma once
#include <iostream>
#include "Enemy.hpp"

class Item {
protected:
    int price;
    int lvl;
public:
    //constructors:
    Item() {std::cout<<"New item!\n";}
    Item(int p = 0, int l = 1) {price = p; lvl = l;}
    virtual ~Item(){};

    //other methods:
    virtual void use(Enemy* victim) = 0;
    virtual std::string getDescription() const = 0;
};


