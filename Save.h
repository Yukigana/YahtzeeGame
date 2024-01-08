#ifndef SAVE_H
#define SAVE_H

#include <list>
#include "Player.h"

class SaveYams{
private :
    int nbPlayer;

public:
    static void initSave(std::list<Player> players, int difficulty);
    // sauv ordre des figures à faire en hardcore
    static void Save(const int* dices, const int& nbFigure);
    static std::list<Player> Load();
};

#endif // SAVE_H