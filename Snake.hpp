#pragma once
#include <iostream>

class Snake : public Enemy {
private:
public:
    //constructors:
    Snake(int _hp = 1, int _xp = 1, int _gold = 1, int _dmg = 0);

    //other methods:
    void attack();
};

Snake::Snake(int _hp, int _xp, int _gold, int _dmg) : Enemy(_hp, _xp, _gold, _dmg) {
	sprite = R"(
  ____
 /\ / \
>---  /
  \  /
   \ \
    \ \_________
     \__________:=-)";
     name = "Giant Snake";
}

void Snake::attack() {
    std::cout<<this->name<<" bit "<<Player::getInstance().getName()<<" for "<<dmg<<" damage!\n";
    Player::getInstance() -= dmg;
}
