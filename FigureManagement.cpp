#include <iostream>
#include <ctime>
#include "FigureManagement.h"
#include "Save.h"

FigureManagement::FigureManagement(Difficulty d, const int l) {
	difficulty = d;
    figures = nullptr;

	cpt = 0;
	score = 0;
	lock = l;
}

void FigureManagement::print()const {
    for (int i = 0; i < 13; ++i) {
        std::cout << i << " : " << (figures[i]->getActivated() ? "(playable)" : "(unplayable)") << figures[i]->getName() << std::endl;
    }
}

void FigureManagement::print(const int* dices)const {
    for (int i = 0; i < 13; ++i) {
        std::cout << i << " : " << (figures[i]->getActivated() ? "(playable)" : "(unplayable)") << figures[i]->getName() << " : " << figures[i]->getScore(dices) << (figures[i]->getPlayed() ? "(played)" : "") << std::endl;
    }
}

void FigureManagement::playFigure(const int* dices, const int& nbFigure){
	score += figures[nbFigure]->getScore(dices); // Ajout du score de la figure joue au score global
	figures[nbFigure]->playFigure(); // Verrouillage de la figure joue

    ++cpt;

	unlockFigure(); // Deblocage des figures suivantes (en fonction de la difficulte)
}

bool FigureManagement::canPlayFigure(const int& nbFigure)const {
    return (nbFigure >= 0 && nbFigure <= 12) && figures[nbFigure]->getActivated() && !figures[nbFigure]->getPlayed();
}





EasyFigure::EasyFigure(): FigureManagement(Difficulty::Easy, 12) {
    Figure** figuresEasy = new Figure*[13];

    figuresEasy[0] = new Classic<1>("One");
    figuresEasy[1] = new Classic<2>("Two");
    figuresEasy[2] = new Classic<3>("Three");
    figuresEasy[3] = new Classic<4>("Four");
    figuresEasy[4] = new Classic<5>("Five");
    figuresEasy[5] = new Classic<6>("Six");

    figuresEasy[6] = new Brelan("Brelan");
    figuresEasy[7] = new Square("Square");
    figuresEasy[8] = new Full("Full");
    figuresEasy[9] = new SmallStraight("Small straight");
    figuresEasy[10] = new LargeStraight("Large straight");
    figuresEasy[11] = new Yahtzee("Yahtzee");
    figuresEasy[12] = new Chance("Chance");

    this->figures = figuresEasy;
}

MediumFigure::MediumFigure() : FigureManagement(Difficulty::Medium, 6) {
    Figure** figuresEasy = new Figure * [13];

    figuresEasy[0] = new Classic<1>("One");
    figuresEasy[1] = new Classic<2>("Two");
    figuresEasy[2] = new Classic<3>("Three");
    figuresEasy[3] = new Classic<4>("Four");
    figuresEasy[4] = new Classic<5>("Five");
    figuresEasy[5] = new Classic<6>("Six");

    figuresEasy[6] = new Brelan("Brelan", false);
    figuresEasy[7] = new Square("Square", false);
    figuresEasy[8] = new Full("Full", false);
    figuresEasy[9] = new SmallStraight("Small straight", false);
    figuresEasy[10] = new LargeStraight("Large straight", false);
    figuresEasy[11] = new Yahtzee("Yahtzee",false);
    figuresEasy[12] = new Chance("Chance", false);

    this->figures = figuresEasy;
}

HardFigure::HardFigure() : FigureManagement(Difficulty::Hard, 1) {
    Figure** figuresEasy = new Figure * [13];

    figuresEasy[0] = new Classic<1>("One");
    figuresEasy[1] = new Classic<2>("Two", false);
    figuresEasy[2] = new Classic<3>("Three", false);
    figuresEasy[3] = new Classic<4>("Four", false);
    figuresEasy[4] = new Classic<5>("Five", false);
    figuresEasy[5] = new Classic<6>("Six", false);

    figuresEasy[6] = new Brelan("Brelan", false);
    figuresEasy[7] = new Square("Square", false);
    figuresEasy[8] = new Full("Full", false);
    figuresEasy[9] = new SmallStraight("Small straight", false);
    figuresEasy[10] = new LargeStraight("Large straight", false);
    figuresEasy[11] = new Yahtzee("Yahtzee", false);
    figuresEasy[12] = new Chance("Chance", false);

    this->figures = figuresEasy;
}

HardcoreFigure::HardcoreFigure() : FigureManagement(Difficulty::Hardcore, 1) {
    Figure** figuresHardcore = new Figure * [13];

    figuresHardcore[0] = new Classic<1>("One");
    figuresHardcore[1] = new Classic<2>("Two", false);
    figuresHardcore[2] = new Classic<3>("Three", false);
    figuresHardcore[3] = new Classic<4>("Four", false);
    figuresHardcore[4] = new Classic<5>("Five", false);
    figuresHardcore[5] = new Classic<6>("Six", false);

    figuresHardcore[6] = new Brelan("Brelan", false);
    figuresHardcore[7] = new Square("Square", false);
    figuresHardcore[8] = new Full("Full", false);
    figuresHardcore[9] = new SmallStraight("Small straight", false);
    figuresHardcore[10] = new LargeStraight("Large straight", false);
    figuresHardcore[11] = new Yahtzee("Yahtzee", false);
    figuresHardcore[12] = new Chance("Chance", false);


    //M�lange des figures
    std::srand(std::time(nullptr));
    Figure* a = nullptr;
    int index = 0;
    for (int i = 0; i < 12; ++i) {
        index = 1 + i + std::rand() / ((RAND_MAX + 1u) / (12 - i));
        a = figuresHardcore[index];
        figuresHardcore[index] = figuresHardcore[i];
        figuresHardcore[i] = a;
    }

    figuresHardcore[0]->unlock();

    this->figures = figuresHardcore;
}

std::string FigureManagement::getOrder(){
    std::string s = "";
    std::string figName = "";
    for(int i = 0 ; i < 13 ; i++){
        figName = figures[i]->getName();
        // on aurait du faire un type enum dans Figure
        // comme on en a pas, on a une usine à gaz
        if(figName == "One") s += "1;";
        else if(figName == "Two") s += "2;";
        else if(figName == "Three") s += "3;";
        else if(figName == "Four") s += "4;";
        else if(figName == "Five") s += "5;";
        else if(figName == "Six") s += "6;";
        else if(figName == "Brelan") s += "7;";
        else if(figName == "Squarre") s += "8;";
        else if(figName == "Full") s += "9;";
        else if(figName == "Small straight") s += "10;";
        else if(figName == "Large straight") s += "11;";
        else if(figName == "Yahtzee") s += "12;";
        else /*if(figName == "Chance")*/ s += "13;";
    }
    return s;
}

HardcoreFigure::HardcoreFigure(std::string s) : FigureManagement(Difficulty::Hardcore, 1) {
    Figure** figuresHardcore = new Figure * [13];

    figuresHardcore[0] = new Classic<1>("One");
    figuresHardcore[1] = new Classic<2>("Two", false);
    figuresHardcore[2] = new Classic<3>("Three", false);
    figuresHardcore[3] = new Classic<4>("Four", false);
    figuresHardcore[4] = new Classic<5>("Five", false);
    figuresHardcore[5] = new Classic<6>("Six", false);

    figuresHardcore[6] = new Brelan("Brelan", false);
    figuresHardcore[7] = new Square("Square", false);
    figuresHardcore[8] = new Full("Full", false);
    figuresHardcore[9] = new SmallStraight("Small straight", false);
    figuresHardcore[10] = new LargeStraight("Large straight", false);
    figuresHardcore[11] = new Yahtzee("Yahtzee", false);
    figuresHardcore[12] = new Chance("Chance", false);

    std::vector<std::string> v = SaveYams::split(s, ";");
    int i = 0;
    Figure** figuresHardcoreOrdered = new Figure * [13];
    for (std::string ms : v){
        int n = stoi(ms);
        figuresHardcoreOrdered[i] = figuresHardcore[n];
        i++;
    }

}

