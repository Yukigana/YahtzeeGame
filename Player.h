#ifndef PLAYER_H
#define PLAYER_H

#include <string>

class Player{
    std::string name;
    public:
    Player(std::string name);
    void f();
    std::string getName(){return name;}

};

#endif // PLAYER_H