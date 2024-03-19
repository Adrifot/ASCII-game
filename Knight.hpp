#pragma once
#include <iostream>

class Knight : public Enemy {
public:
    Knight(int _hp = 1, int _xp = 1, int _gold = 1, int _dmg = 0);
	void attack();
};

Knight::Knight(int _hp, int _xp, int _gold, int _dmg) : Enemy(_hp, _xp, _gold, _dmg) {
	sprite = R"(
      .-.
    __|=|__
   (_/`-`\_)
   //\___/\\
   <>/   \<>
    \|_._|/
     <_I_>
      |||
     /_|_\
)";
    name = "Evil Knight";
}

void Knight::attack() {
    std::cout<<this->name<<" hit "<<Player::getInstance().getName()<<" for "<<dmg<<" damage!\n";
    Player::getInstance() -= dmg;
}
