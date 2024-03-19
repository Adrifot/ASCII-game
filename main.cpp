#include <iostream>
#include <ctime>
#include <chrono>
#include "Player.hpp"
#include "Item.hpp"
#include "Enemy.hpp"
#include "Wasp.hpp"
#include "Location.hpp"
#include "Potion.hpp"
#include "Bomb.hpp"
#include "Snake.hpp"
#include "Knight.hpp"
#include "Interface.hpp"
#define MAIN Interface::getInstance()

int main()
{
    srand(std::chrono::high_resolution_clock::now().time_since_epoch().count());
    try {MAIN.run();}
    catch(const WrongInput& err){std::cout<<err.what();}
    catch(const InvIndexError& err) {std::cout<<err.what();}
    catch(const ErrNoMoney& err) {std::cout<<err.what();}

    return 0;
}
