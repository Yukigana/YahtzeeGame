#include <iostream>
#include <cstdlib>
#include <ctime>

#include "roll.h"

DiceSet::DiceSet() : dices(new int[5]), locks(new bool[5]) {
    for (int i = 0; i < 5; ++i) {
        dices[i] = 0;
        locks[i] = false;
    }
};

DiceSet::~DiceSet() {
    delete[](dices);
    delete[](locks);
}

void DiceSet::print()const {
    std::cout << "\tDices : ";
    for (int i = 0; i < 5; ++i) {
        std::cout << "[" << dices[i] << "] ";
    }
    std::cout << std::endl;
}

void DiceSet::lockDices() {
    // Choix entre verrouiller ou d�verrouiller d�
    int choose = 0;
    bool valid = false;
    do {
        std::cout << "Dices : " << std::endl;
        for (int i = 0; i < 5; ++i) {
            std::cout << i << ":" << " [" << dices[i] << "] " << (locks[i] ? "(lock)" : "") << std::endl;
        }
        std::cout << std::endl;
        std::cout << "1.Lock dice or 2.Unlock dice or 3.Reroll? (enter number) : ";
        std::cin >> choose;
        switch (choose)
        {
        case 1:
            std::cout << "Enter the number of dice to lock" << std::endl;
            std::cin >> choose;
            if (choose < 5 && choose >= 0) locks[choose] = true;
            else std::cout << "Invalid index !" << std::endl;
            break;

        case 2:
            std::cout << "Enter the number of dice to unlock" << std::endl;
            std::cin >> choose;
            if (choose < 5 && choose >= 0) locks[choose] = false;
            else std::cout << "Invalid index !" << std::endl;
            break;

        case 3:
            Roll::rollDices(this);
            valid = true;
            break;

        default:
            std::cout << "Invalid command ! Please retry." << std::endl;
            break;
        }
    } while (!valid);
}

void DiceSet::resetDices() {
    for (int i = 0; i < 5; ++i) {
        locks[i] = false;
    }
}

void DiceSet::setDice(const int& nbDice, const int& value) {
    dices[nbDice] = value;
}

int* DiceSet::getDices()const {
    int* d = new int[6];
    for (int i = 0; i < 6; ++i) {
        d[i] = 0;
    }

    for (int i = 0; i < 5; ++i) {
        d[dices[i] - 1]++;
    }

    return d;
}






Roll::Roll(){
    
}

void Roll::rollDices(DiceSet* set){
    std::srand(std::time(nullptr));

    for (int i = 0; i < 5; ++i) {
        if(!set->getLock(i))
            set->setDice(i, 1 + std::rand() / ((RAND_MAX + 1u) / 6));
    }
}

