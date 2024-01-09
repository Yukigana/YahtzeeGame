#ifndef YAMS_H
#define YAMS_H

#include <list>
#include <iterator>
#include <iostream>

#include "Player.h"
#include "Roll.h"
#include "Figure.h"

class Yams{
    std::list<Player> players;
    std::list<Player>::iterator ITcurrentPlayer;
    
    std::list<Figure*> figures;

    bool finished;

    void setPlayers();

public:
    Yams();
    //~Yams();
    
    void launchGame();
};

#endif // YAMS_H