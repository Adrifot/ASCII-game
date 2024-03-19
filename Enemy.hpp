#pragma once
#include <iostream>
#include <string>
#include "Player.hpp"

class Enemy {
protected:
	std::string name;
	int hp;
	int xp;
	int gold;
	int dmg;
	std::string sprite = " ";
public:
    //constructors:
	Enemy() {std::cout << "New enemy!\n";}
	Enemy(int _hp, int _xp, int _gold, int _dmg) { hp = _hp; xp = _xp; gold = _gold; dmg = _dmg;}
	virtual ~Enemy(){};

	//getters & setters:
	std::string getSprite() const {return sprite;}
	int getHP() const {return hp;}
	std::string getName() const {return name;}
	int getXP() const {return xp;}
	int getGold() const {return gold;}

	//other methods:
	virtual void attack() = 0;

    //overloads and friends:
	Enemy& operator-= (int damage) {this->hp -= damage; return *this;}
    friend std::ostream& operator<<(std::ostream& out, const Enemy& enm);
};

std::ostream& operator<<(std::ostream& out, const Enemy& enm) {
    out<<enm.name<<std::endl;
    out << "HP: ";
    for(int i=0; i<enm.hp; i++) out<<"~";
    out<<std::endl;
    out << enm.sprite << std::endl;
    return out;
}

