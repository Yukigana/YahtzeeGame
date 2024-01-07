#include <iostream>

#include "Player.h"

Player::Player(std::string name, const int& difficulty): name(name), figureManagement(nullptr), diceSet(new DiceSet()) {
    switch (difficulty)
    {
    case 2:
        figureManagement = new MediumFigure();
        break;

    case 3:
        figureManagement = new HardFigure();
        break;

    case 4:
        figureManagement = new HardcoreFigure();
        break;

    default:
        figureManagement = new EasyFigure();
        break;
    }
}

void Player::playTurn()const {
    
    Roll::rollDices(diceSet);

    // Choix joueur soit relancer dés (donc sélection dés à garder) soit sélection figure à jouer
    bool valid = false;
    int choose = 0;
    int cptReroll = 0;
    do {
        figureManagement->print(diceSet->getDices());
        diceSet->print();
        std::cout << "1.Reroll your dices or 2.select a figure : (enter 1 or 2)";
        std::cin >> choose;
        switch (choose)
        {
        case 1:
            // Verrouillage et relance des dés
            diceSet->lockDices();
            ++cptReroll;
            if (cptReroll == 3) std::cout << "You can no longer reroll. You have to choose a figure to play. ";
            else break;
            

        case 2:
            diceSet->resetDices(); // Déverrouillage de tous les dés

            // Choix figure
            std::cout << "Enter index of the figure you want play :";
            std::cin >> choose;

            if (figureManagement->canPlayFigure(choose)) {
                figureManagement->playFigure(diceSet->getDices(), choose);
                valid = true;
            }
            else std::cout << "Invalid index !" << std::endl;
            break;

        default:
            std::cout << "Invalid command ! Please retry." << std::endl;
            break;
        }
    } while (!valid);
}
