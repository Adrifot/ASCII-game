#pragma once
#include <iostream>

class Potion : public Item {
private:
    int HP_heal;
public:
    //constructors:
    Potion(int p, int l) : Item(p, l) {HP_heal = l*3;}

    //other methods:
    void use(Enemy* victim) override {Player::getInstance() += HP_heal; std::cout<<Player::getInstance().getName()<<" healed for "<<HP_heal<<" HP!"<<std::endl;}
    std::string getDescription() const override {
        return "Potion, LVL " + std::to_string(lvl) + "\nHeals " + std::to_string(HP_heal) + " HP\n";
    }

    //friends and overloads:
    friend std::ostream& operator<<(std::ostream& out, const Potion& pot);
};

std::ostream& operator<<(std::ostream& out, const Potion& pot) {
    out<<"Potion, LVL "<<pot.lvl<<std::endl;
    out<<"Heals "<<pot.HP_heal<<" HP\n";

    return out;
}
