#ifndef YAMS_H
#define YAMS_H

#include <list>
#include <iterator>
#include <iostream>

#include "Player.h"
#include "Roll.h"

class Yams{
    std::list<Player> players;
    std::list<Player>::iterator ITcurrentPlayer;

    bool finished;

    void setPlayers();
    void saveGame();
    void playTurn();
public:
    Yams();
    void launchGame();
};

#endif // YAMS_H