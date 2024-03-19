#pragma once
#include <iostream>
#include <vector>
#include <ctime>
#include <windows.h>

class Location {
private:
    std::string name;
    std::string scene;
    std::string adj1;
    std::string adj2;
    std::string adjA[11] = {"grand", "ancient", "small", "huge", "colossal", "mighty", "crooked", "tiny", "boundless", "forsaken", "very old"};
    std::string adjB[11] = {"crimson", "green", "red", "black", "bleak", "dark", "dim", "somber", "faded", "pale", "ghastly"};
    std::string name2;

public:
    //constructors:
    Location(std::string _name = " ") {name = _name;}
    ~Location() {}

    //getters and setters:
    void setScene(std::string _scene) {scene = _scene;}
    void setData();
    std::string getName() {return name;}

    //overloads and friends:
    friend std::ostream& operator<<(std::ostream& out, const Location& loc);
};

std::ostream& operator<<(std::ostream& out, const Location& loc) {
    out << loc.scene << std::endl;
    int desc = rand()%3;
    if(desc == 0) out<<"You reach "<<loc.name2<<", a "<<loc.adj1<<" and "<<loc.adj2<<" "<<loc.name<<"."<<std::endl;
    else if(desc == 1) out<<"You approach the "<<loc.adj1<<" and "<<loc.adj2<<" "<<loc.name<<" of "<<loc.name2<<"."<<std::endl;
    else out<<"Ahead of you is the "<<loc.name<<" of "<<loc.name2<<". It is "<<loc.adj1<<" and "<<loc.adj2<<"."<<std::endl;
    return out;
}

std::string makeName();

void Location::setData() {
    adj1 = adjA[rand()%11];
    adj2 = adjB[rand()%11];
    name2 = makeName();
}

std::string makeName() {
    std::string locName = "";
    int len = 4+rand()%7;
    char v[5] = {'a', 'e', 'i', 'o', 'u'};
    char c[16] = {'b', 'c', 'd', 'f', 'g', 'h', 'j', 'l', 'm', 'n', 'p', 'r', 's', 't', 'v', 'z'};
    int v_or_c = rand()%2;
    for(int i=0; i<=len; i++) {
        if(v_or_c >= 1 && v_or_c <3) {
            locName += c[rand()%16];
            v_or_c += 1+rand()%2;
        } else {
            locName += v[rand()%5];
            v_or_c = 1;
        }
    }
    locName[0]  = toupper(locName[0]);
    return locName;
}
