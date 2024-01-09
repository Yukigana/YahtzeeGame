#ifndef SAVE_H
#define SAVE_H

#include <list>
#include <iostream>
#include <fstream>
#include "Player.h"

class SaveYams{
    SaveYams();
    ~SaveYams();
    static const std::string FILENAME;
    static bool cleaned;
    static std::ofstream file;
public:
    static void savePlayer(Player player, int difficulty);
    static void saveHardcoreOrder(FigureManagement* fm);
    // sauv ordre des figures à faire en hardcore
    static void saveFigure(const int* dices, const int& nbFigure);
    static std::list<Player> load();
};

#endif // SAVE_H