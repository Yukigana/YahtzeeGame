#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include "FigureManagement.h"
#include "Roll.h"

class Player{
private :
    std::string name;

    FigureManagement* figureManagement;
    DiceSet* diceSet;

    friend class SaveYams;

public:
    Player(std::string name, const int& difficulty);
    ~Player();
    
    void playTurn()const;
    
    std::string getName()const {return name;}
    int getScore()const { return figureManagement->getScore(); };
};

#endif // PLAYER_H