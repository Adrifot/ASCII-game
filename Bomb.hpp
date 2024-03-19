#pragma once
#include <iostream>

class Bomb : public Item {
private:
    int dmg_deal;
public:
    //constructors:
    Bomb(int p, int l) : Item(p, l) {dmg_deal = l*3;}

    //other methods:
    void use(Enemy* victim) override {*victim -= dmg_deal; std::cout<<"The bomb damaged "<<victim->getName()<<" for "<<dmg_deal<<" damage!\n";}
    std::string getDescription() const override {
        return "Bomb, LVL " + std::to_string(lvl) + "\nDeals " + std::to_string(dmg_deal) + " damage.\n";
    }

    //friends and overloads:
    friend std::ostream& operator<<(std::ostream& out, const Bomb& bmb);
};

std::ostream& operator<<(std::ostream& out, const Bomb& bmb) {
    out<<"Bomb, LVL "<<bmb.lvl<<std::endl;
    out<<"Deals "<<bmb.dmg_deal<<" damage.\n";
    return out;
}
