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

    // Choix joueur soit relancer d�s (donc s�lection d�s � garder) soit s�lection figure � jouer
    bool valid = false;
    int choose = 0;
    int cptReroll = 0;
    do {
        std::cout<<std::endl;
        std::cout << " = = = = = = = = = = = " << this->name << "'s turn = = = = = = = = = = = ";
        std::cout<<std::endl;
        figureManagement->print(diceSet->getDices());
        std::cout<<std::endl;
        diceSet->print();
        std::cout << "\n1.Reroll your dices or 2.select a figure : (enter 1 or 2)";
        std::cin >> choose;
        switch (choose)
        {
        case 1:
            // Verrouillage et relance des d�s
            diceSet->lockDices();
            ++cptReroll;
            if (cptReroll == 3) std::cout << "You can no longer reroll. You have to choose a figure to play. ";
            else break;
            

        case 2:
            diceSet->resetDices(); // D�verrouillage de tous les d�s

            // Choix figure
            std::cout << "Enter index of the figure you want play :";
            std::cin >> choose;

            if (figureManagement->canPlayFigure(choose)) {
                // save
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
