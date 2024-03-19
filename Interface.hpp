#pragma once
#include <iostream>
#include <ctime>
#include <memory>

#include "WrongInput.hpp"
#include "InvIndexError.hpp"
#include "ErrNoMoney.hpp"

#define FORMULA (1 + rand() % (Player::getInstance().getXP() / 10 + 1) + Player::getInstance().getXP() / 5), \
                 ((rand() % (Player::getInstance().getXP() / 10 + 1) / 2) + (Player::getInstance().getXP() / 5) / 2 + 3), \
                 (rand() % (Player::getInstance().getXP() / 10 + 1) + Player::getInstance().getXP() / 5 + 3), \
                 (rand() % (Player::getInstance().getXP() / 20 + 1) + Player::getInstance().getXP() / 13)
#define CHECK_$$$ if(Player::getInstance().getGold() < price) throw ErrNoMoney()


class Interface {
private:
    Enemy* currEnemy;
    Location* currLoc;
    int loop; int ind;
    Location all_locations[5] = {Location("Forest"), Location("Forest Hut"), Location("Beach"), Location("Castle"), Location("Mountain")};
    //constructors:
    Interface();
    ~Interface(){}
public:
    static Interface& getInstance() {
        static Interface* currInterface = new Interface();
        return *currInterface;
    }
    template <typename T = int>
    void showLocationIndex() {
        if(sizeof(T) == 1) std::cout<<"(Location "<<(T)(loop + 97)<<")\n";
        else std::cout<<"(Location "<<(T)loop<<")\n";
    }
    void run();
    void battle();
};

Interface::Interface() {
    //std::cout<<"Show location indexes in numerical or character form? 1 - character, anything else - numerical\n";
    //std::cin>>ind;
    //system("cls");
    std::cout<< R"(
  ___   _____ _____ _____ _____       _____
 / _ \ /  ___/  __ \_   _|_   _|     |  __ \
/ /_\ \\ `--.| /  \/ | |   | |       | |  \/ __ _ _ __ ___   ___
|  _  | `--. \ |     | |   | |       | | __ / _` | '_ ` _ \ / _ \
| | | |/\__/ / \__/\_| |_ _| |_      | |_\ \ (_| | | | | | |  __/
\_| |_/\____/ \____/\___/ \___/       \____/\__,_|_| |_| |_|\___|
    )"<<std::endl;
    all_locations[0].setScene( R"(
 ^  ^  ^   ^             ^  ^      ^  ^   ^  ^
/|\/|\/|\ /|\   ^   ^   /|\/|\  ^ /|\/|\ /|\/|\
/|\/|\/|\ /|\  /|\ /|\  /|\/|\ /|\/|\/|\ /|\/|\
/|\/|\/|\ /|\  /|\ /|\  /|\/|\ /|\/|\/|\ /|\/|\
^^^ ^^^ ^^^^^ ^^^ ^^^ ^^^^^^ ^^ ^^^ ^^^^^ ^^^ ^
        )"
    );
    all_locations[1].setScene( R"(
 ^     ^   ^      ___I_      ^  ^   ^     ^   ^  ^
/|\ ^ /|\ /|\    /\-_--\ ^^ /|\/|\ /|\ ^ /|\ /|\/|\
/|\/|\/|\ /|\  ^/  \_-__\   /|\/|\ /|\/|\/|\ /|\/|\
/|\/|\/|\ /|\^^ |[]| [] | ^ /|\/|\ /|\/|\/|\ /|\/|\
^^ ^^^^ ^^ ^^^^ ^^^ ^^^^ ^^^^ ^^^ ^^^^^ ^^^^ ^^^ ^^
        )"
    );
    all_locations[2].setScene( R"(
                                         |
                                       \ _ /
                                     -= (_) =-
    .\/.                               /   \
 .\\//o\\                      ,\/.      |
 //o\\|,\/.           ,\/.  ,\//o\\
   |  |//o\           //o\  /o\\|
 ^^|^^|^~|^^^^ ~ ^^ ^   | ^^^|^^^^^|^^|^^^"""("~~~~~~~~~ ~ ~~~~~~~~~~~
  .|'' . |  '''""'"''. |`===`|''  '"" "" " (" ~~~~ ~ ~~~~~~~~  ~~ ~
     ^^   ^^^ ^ ^^^ ^^^^ ^^^ ^^ ^^ "" """( " ~~~~~~ ~~~~~  ~~~ ~
        )"
    );
    all_locations[3].setScene( R"(

                                  |>>>
                                  |
                    |>>>      _  _|_  _         |>>>
                    |        |;| |;| |;|        |
                _  _|_  _    \\.    .  /    _  _|_  _
               |;|_|;|_|;|    \\:. ,  /    |;|_|;|_|;|
               \\..      /    ||;   . |    \\.    .  /
                \\.  ,  /     ||:  .  |     \\:  .  /
                 ||:   |_   _ ||_ . _ | _   _||:   |
                 ||:  .|||_|;|_|;|_|;|_|;|_|;||:.  |
                 ||:   ||.    .     .      . ||:  .|
                 ||: . || .     . .   .  ,   ||:   |
                 ||:   ||:  ,  _______   .   ||: , |
                 ||:   || .   /+++++++\    . ||:   |
                 ||:   ||.    |+++++++| .    ||: . |
              __ ||: . ||: ,  |+++++++|.  . _||_   |
     ____--`~    '--~~__|.    |+++++__|----~    ~`---,
-~--~                   ~---__|,--~'                  ~~----_____-~
        )"
    );
    all_locations[4].setScene( R"(

    .                  .-.    .  _   *     _   .
           *          /   \     ((       _/ \       *    .
         _    .   .--'\/\_ \     `      /    \  *    ___
     *  / \_    _/ ^      \/\'__        /\/\  /\  __/   \ *
       /    \  /    .'   _/  /  \  *' /    \/  \/ .`'\_/\   .
  .   /\/\  /\/ :' __  ^/  ^/    `--./.'  ^  `-.\ _    _:\ _
     /    \/  \  _/  \-' __/.' ^ _   \_   .'\   _/ \ .  __/ \
   /\  .-   `. \/     \ / -.   _/ \ -. `_/   \ /    `._/  ^  \
  /  `-.__ ^   / .-'.--'    . /    `--./ .-'  `-.  `-. `.  -  `.
@/        `.  / /      `-.   /  .-'   / .   .'   \    \  \  .-  \%
@&8jgs@@%% @)&@&(88&@.-_=_-=_-=_-=_-=_.8@% &@&&8(8%@%8)(8@%8 8%@)%
@88:::&(&8&&8:::::%&`.~-_~~-~~_~-~_~-~~=.'@(&%::::%@8&8)::&#@8::::
        )"
    );
}

void Interface::battle() {
    system("cls");
    std::cout<<"While investigating, you encounter a "<<currEnemy->getName()<<"!\n\n";
    while(currEnemy->getHP() > 0 && Player::getInstance().getHP() > 0) {
        system("cls");
        std::cout<<Player::getInstance();
        std::cout<<"\nVS\n\n";
        std::cout<<*currEnemy;
        input:
        std::cout<<Player::getInstance().getName()<<", what will you do?\n";
        char input;
        std::cout<<"1 - attack "<<currEnemy->getName()<<std::endl;
        std::cout<<"2 - inventory \n";
        std::cin>>input;
        switch(input) {
        case '1':
            Player::getInstance().attack(currEnemy);
            std::cin.get();
            break;
        case '2':
            Player::getInstance().openInventory();
            std::cout<<"1 - use an item\n";
            std::cout<<"Any other input - back\n";
            char in;
            std::cin>>in;
            if(in == '1') {
                std::cout<<"Choose the item's index: ";
                int in2;
                std::cin>>in2;
                if(!Player::getInstance().checkInvIndex(in2-1)) throw InvIndexError(in2);
                Player::getInstance().use(in2, currEnemy);
                std::cin.get();
            }
            break;
        default:
            throw WrongInput(input);
            goto input;
        }
        currEnemy->attack();
        std::cin.get();
    }
    if(currEnemy->getHP() <= 0) {
        std::cout<<"You have won this fight and defeated the "<<currEnemy->getName()<<"!\n";
        std::cout<<"You have received "<< currEnemy->getXP()<<"XP and "<<currEnemy->getGold()<<" gold coins!\n";
        Player::getInstance() + currEnemy->getXP();
        Player::getInstance().setGold(Player::getInstance().getGold() + currEnemy->getGold());
        std::cin.get();
        int drop = rand()%2;
        if(drop == 1) {
            std::cout<<"The enemy has also dropped an item!\n";
            int drop2 = rand()%2;
            if(drop2 == 1) Player::getInstance().addToInventory(new Potion(0, rand()%(currEnemy->getXP()/4+1)+1));
            else Player::getInstance().addToInventory(new Bomb(0, rand()%(currEnemy->getXP()/4 + 1)+1));
            std::cin.get();
        } else {
            std::cout<<"After this victory, you have to move on...\n";
            std::cin.get();
        }
        delete currEnemy;
        currEnemy = nullptr;
    }
}

void Interface::run() {
    while(Player::getInstance().getHP()  > 0) {
        system("cls");
        //if(ind==1) showLocationIndex<char>();
        //else showLocationIndex();
        //loop++;
        currLoc = &all_locations[rand()%5];
        currLoc->setData();
        int choose_en;
        if(currLoc->getName() == "Beach") choose_en = -1 + rand()%4;
        else if(currLoc->getName() == "Forest Hut") choose_en = -(rand()%2 + 1);
        else choose_en = rand()%3;
        if(choose_en == 0) currEnemy = new Wasp(FORMULA);
        else if(choose_en == 1) currEnemy = new Snake(FORMULA);
        else if(choose_en == 2) currEnemy = new Knight(FORMULA);
        else currEnemy = nullptr;
        std::cout<<*currLoc;
        if(choose_en == -2) {
            bool transaction = true;
            std::cout<<"In the hut, you meet a friendly trader. He can give you a random item, for a price.\n";
            char in;
            while(transaction) {
                std::cout<<"1 - buy a low-level item (10 gold)\n";
                std::cout<<"2 - buy a medium-level item (30 gold)\n";
                std::cout<<"3 - buy a high-level item (50 gold)\n";
                std::cout<<"4 - buy a LEGENDARY item (100 gold)\n";
                std::cout<<"5 - leave and move on\n";
                std::cout<<"(You have "<<Player::getInstance().getGold()<<" gold coins)\n";
                std::cin>>in;
                int drop = rand()%2;
                int price;
                switch(in) {
                case '1':
                    price = 10;
                    CHECK_$$$;
                    Player::getInstance().setGold(Player::getInstance().getGold() - price);
                    if(drop == 1) Player::getInstance().addToInventory(new Potion(10, rand()%5 + 1));
                    else Player::getInstance().addToInventory(new Bomb(10, rand()%5 + 1));
                    std::cout<<"Transaction successful. The trader seems content. Check your inventory to see the new item's stats.\n";
                    break;
                case '2':
                    price = 30;
                    CHECK_$$$;
                    Player::getInstance().setGold(Player::getInstance().getGold() - price);
                    if(drop == 1) Player::getInstance().addToInventory(new Potion(20, rand()%10 + 5));
                    else Player::getInstance().addToInventory(new Bomb(20, rand()%10 + 5));
                    std::cout<<"Transaction successful. The trader seems happy. Check your inventory to see the new item's stats.\n";
                    break;
                case '3':
                    price = 50;
                    CHECK_$$$;
                    Player::getInstance().setGold(Player::getInstance().getGold() - price);
                    if(drop == 1) Player::getInstance().addToInventory(new Potion(30, rand()%15 + 10));
                    else Player::getInstance().addToInventory(new Bomb(30, rand()%15 + 10));
                    std::cout<<"Transaction successful. The trader is delighted. Check your inventory to see the new item's stats.\n";
                    break;
                case '4':
                    price = 100;
                    CHECK_$$$;
                    Player::getInstance().setGold(Player::getInstance().getGold() - price);
                    if(drop == 1) Player::getInstance().addToInventory(new Potion(30, rand()%15 + 10));
                    else Player::getInstance().addToInventory(new Bomb(30, rand()%15 + 10));
                    std::cout<<"Transaction successful. The trader is ecstatic. Check your inventory to see the new item's stats.\n";
                    break;
                case '5':
                    transaction = false;
                    break;
                default:
                    throw WrongInput(in);
                }
            }
        }
        else if(choose_en == -1) {
            std::cout<<"This place is peaceful. You can rest here.\n";
            std::cin.get();
            int h = rand()%5+1;
            std::cout<<"After resting, you heal "<<h<<" HP.\n";
            Player::getInstance() += h;
            std::cin.get();
        } else {
            choice2:
            std::cout<<std::endl;
            char ch;
            std::cout<<"What will you do now, "<<Player::getInstance().getName()<<"?\n";
            std::cout<<"1 - investigate "<<currLoc->getName()<<std::endl;
            std::cout<<"2 - move further\n";
            std::cout<<"3 - inventory\n";
            std::cin>>ch;
            switch(ch) {
            case '1':
                battle();
                break;
            case '2':
                std::cout<<"You move on...\n";
                std::cin.get();
                std::cin.get();
                system("cls");
                break;
            case '3':
                Player::getInstance().openInventory();
                goto choice2;
                break;
            default:
                throw WrongInput(ch);
                goto choice2;
            } //switch end
        } //else end
    } //while end
    std::cout<<R"(
   _____          __  __ ______    ______      ________ _____
  / ____|   /\   |  \/  |  ____|  / __ \ \    / /  ____|  __ \
 | |  __   /  \  | \  / | |__    | |  | \ \  / /| |__  | |__) |
 | | |_ | / /\ \ | |\/| |  __|   | |  | |\ \/ / |  __| |  _  /
 | |__| |/ ____ \| |  | | |____  | |__| | \  /  | |____| | \ \
  \_____/_/    \_\_|  |_|______|  \____/   \/   |______|_|  \_\
    )";
    std::cout<<Player::getInstance().getName()<<", you have lost!\n";
    std::cout<<"Your highscore is: "<<Player::getInstance().getXP()<<std::endl;
}
