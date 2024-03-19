#pragma once
#include <iostream>
#include <string>

class Wasp : public Enemy {
private:
public:
    //constructors:
	Wasp(int _hp = 1, int _xp = 1, int _gold = 1, int _dmg = 0);

	//other methods:
	void attack() override;
};

Wasp::Wasp(int _hp, int _xp, int _gold, int _dmg) : Enemy(_hp, _xp, _gold, _dmg) {
	sprite = R"(
    _  _
   | )/ )
\\ |//,' __
(")(_)-"()))=-
   (\\
)";
    name = "Giant Wasp";
}

void Wasp::attack() {
    std::cout<<this->name<<" stung "<<Player::getInstance().getName()<<" for "<<dmg<<" damage!\n";
    Player::getInstance() -= dmg;
}


