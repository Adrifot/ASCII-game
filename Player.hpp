#pragma once
#include <iostream>
#include <vector>
#include "Item.hpp"
#include "WrongInput.hpp"

class Player {
private:
    int hp;
    int xp;
    int gold;
    std::string name;
    std::string sprite = R"(
 O
/|\
/ \
)";
    std::vector<Item*> inventory;

    //constructors:
    Player();
    ~Player(){}
public:
    //getters and setters:
    std::string getName() {return name;}
    int getHP() {return hp;}
    int getXP() {return xp;}
    int getGold() {return gold;}
    void setGold(int _gold) {gold = _gold;}
    static Player& getInstance() {
        static Player* currPlayer = new Player();
        return *currPlayer;
    }

    //other methods:
    void use(int pos, Enemy* victim) {inventory.at(pos-1)->use(victim); delete inventory[pos-1]; inventory.erase(inventory.begin() + pos-1);}
    void openInventory();
    void attack(Enemy* victim);
    void addToInventory(Item* it) {inventory.push_back(it);}
    bool checkInvIndex(int index) {return index >= 0 && index < inventory.size();}

    //overloads and friends:
    Player& operator-= (int damage) {this->hp -= damage; return *this;}
    Player& operator+= (int healHP) {this->hp += healHP; return *this;}
    Player& operator+ (int XPgain) {this->xp += XPgain; return *this;}
    friend std::ostream& operator<<(std::ostream& out, const Player& user);
};

Player::Player() {
    std::cout<<"Your name, player: ";
    std::cin>>name;
    hp = 10;
    xp = 0;
    gold = 0;
}

void Player::openInventory() {
    std::cout<<"Your stats: "<<hp<<"HP, "<<xp<<"XP, "<<gold<<" gold coins.\n";
    std::cout<<"In your inventory, you have:\n";
    if(inventory.empty()) {
        std::cout<<"Nothing :("<<std::endl;
        return;
    }
    int j = 1;
    for(Item* item : inventory) {
        std::cout<<"["<<j<<"]: ";
        std::cout<<item->getDescription()<<std::endl;
        j++;
    }
}

void Player::attack(Enemy* victim) {
    int dmg = xp/10 * 2 + rand()%(xp/10 + 1) + 1;
    *victim -= dmg;
    std::cout<<name<<" attacked "<<victim->getName()<<" for "<<dmg<<" damage!\n";
}

std::ostream& operator<<(std::ostream& out, const Player& user) {
    out<<user.name<<std::endl;
    out << "HP: ";
    for(int i=0; i<user.hp; i++) out<<"/";
    out<<std::endl;
    out << user.sprite << std::endl;
    return out;
}

