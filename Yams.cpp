#include "Yams.h"
#include "Save.h"

Yams::Yams() : finished(false), ITcurrentPlayer(players.begin()){
    
}
Yams::~Yams(){
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

    std::string load = "";
    std::cout << "Do you want to load last game ? (Y to load)\nYour game is automatically saved\n-> ";
    std::cin >> load;

    bool failedToLoad = true;
    if(load == "Y"){
        int turnNumber = 0;
        players = SaveYams::load(&turnNumber);
        if(!players.empty()){
            failedToLoad = false;
            int numberPlayer = players.size();
            int balance = turnNumber % numberPlayer;

            int i = 0;
            for (Player p : players) {
                if(i>= balance) p.playTurn();
                i++;
            }
            for (int i = (turnNumber+balance)/numberPlayer; i < 13; ++i) {
                for (Player p : players) p.playTurn();
            }
        }//FIN IF EMPTY
        else{
            std::cout << "\nFailed to load file. Launching raw game.\n";
        }

    }else if(failedToLoad){
        setPlayers();
        ITcurrentPlayer = players.begin();
    
        for (int i = 0; i < 13; ++i) {
            for (Player p : players) {
                p.playTurn();
            }
        }
    }
    std::string winnerName = "";
    int winnerScore = 0;

    for (Player p : players) {
        if (winnerScore < p.getScore()) {
            winnerScore = p.getScore();
            winnerName = p.getName();
        }
    }
    
    std::cout << "The winner is " << winnerName << ", with " << winnerScore << " points !" << std::endl;
    /*
    int turnNb = players.size();
    for(int i = 0 ; i < turnNb ; i++){
        playTurn();
        ++ITcurrentPlayer;
    }*/
    
}

void Yams::setPlayers(){
    std::string pName = ""; int difficulty = 0; std::cout << "here";
    bool stop = false;
    while(stop != true){
        std::cout << "\nEnter player's name (\"stop\" to stop adding players) : ";
        std::cin >> pName;

        if (pName != "stop") {
            bool valid = false;
            do {
                std::cout << "Enter player's difficulty 1.Easy 2.Medium 3.Hard 4.Hardcore (enter difficulty's index): ";
                std::cin >> difficulty;
                if (difficulty > 0 && difficulty <= 4) valid = true;
                else std::cout << "Index isn't valid." << std::endl;
            } while (!valid);

            Player p(pName, difficulty);
            SaveYams::savePlayer(p, difficulty);

            players.push_back(p);
        }
        else stop = true;
    }
    
}


