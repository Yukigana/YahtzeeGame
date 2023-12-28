#include "Yams.h"

Yams::Yams() : finished(false), ITcurrentPlayer(players.begin()){
    
}

void Yams::launchGame(){
    std::cout << "| =  =  =  =  =  =  =  =  ===  YAMS  ===  =  =  =  =  =  =  =  = |\n";
    std::cout << "Welcome to the Yams' game !\n\nDo you want to display te rules before playing ? (Y to display)\n";
    std::string rules = "";
    std::cin >> rules;
    if(rules == "Y"){
        std::cout << "\t YAMS RULES.\n\n";

        std::cout << "Every turn, you roll 5 dices in order to make special combinations :\n";
        std::cout << "UPPER PART combinations = = =\n";
        std::cout << "\t- Ace : maximum of 1 (number of points = addition of the 1).\n";
        std::cout << "\t Two : maximum of 2 (number of points = addition of the 2).\n";
        std::cout << "\t- Three : maximum of 3 (number of points = addition of the 3).\n";
        std::cout << "\t- Four : maximum of 4 (number of points = addition of the 4).\n";
        std::cout << "\t- Five : maximum of 5 (number of points = addition of the 4).\n";
        std::cout << "\t- Six : maximum of 6 (number of points = addition of the 6).\n";
        std::cout << "BOTTOM HALF combinations = = =\n";
        std::cout << "\t- Three of a kind : litteraly (addition of the dices).\n";
        std::cout << "\t- Square : four of a kind (addition of the dices).\n";
        std::cout << "\t- Full : three of a kind and two of another (25pts).\n";
        std::cout << "\t- Small suit : four number following each other (25pts).\n";
        std::cout << "\t- Large suit : five number following each other (40pts).\n";
        std::cout << "\t- Yams : same five numbers (50pts).\n";
        std::cout << "\t- Chance : everything (addition of the dices).\n\n";

        std::cout << "You can roll your dices 3 time by turn, you can select the ones\nyou want to reroll.\n";
        std::cout << "Every end of turn you choose where to put you combination. If you\nput it in an unadapted case score will be 0. Choose a case is an\nobligation.\n";
        std::cout << "If you reach 63pts in the UPPER PART, you'll gain 35pts.\n";
        std::cout << "There are 13 rounds.\n\n";
    }

    setPlayers();
    ITcurrentPlayer = players.begin();

    int turnNb = players.size();
    for(int i = 0 ; i < turnNb ; i++){
        playTurn();
        ++ITcurrentPlayer;
    }
}

void Yams::setPlayers(){
    std::string pName = "";
    while(players.empty() && pName != ""){
        std::cout << "Enter player's name (nothing to stop adding players) : ";
        std::cin >> pName;

        if(pName != ""){
            Player p(pName);
            players.push_back(p);
        }
    }
    
}

void Yams::playTurn(){
    
}

void Yams::saveGame(){
    
}

