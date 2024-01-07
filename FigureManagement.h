#pragma once
#include "Figure.h"

enum class Difficulty
{
	Easy,
	Medium,
	Hard,
	Hardcore
};

class FigureManagement
{
private :
	Difficulty difficulty; // Indice de difficulté

	int score; // Score des figures joué

protected :
	Figure** figures; // Liste des figures dans l'ordre à jouer

	int cpt; // Permet de savoir quel figures débloquer
	int lock; // Limite des figures jouables

public :
	FigureManagement(Difficulty d, const int l);

	void print()const; // Affiche les figures jouables
	void print(const int* dices)const; // Affiche les figures jouables avec leur score correspondant aux dés indiqués

	void playFigure(const int* dices, const int& nbFigure); // Joue la figure choisi par le joueur avec les dés du joueur

	bool canPlayFigure(const int& nbFigure)const;
	
	virtual void unlockFigure()const = 0;

	int getCpt()const { return cpt; };
	int getScore()const { return score; };
};

class EasyFigure : public FigureManagement {
private :

public :
	EasyFigure();

	void unlockFigure()const override {

	}
};

class MediumFigure : public FigureManagement {
private:

public:
	MediumFigure();

	void unlockFigure()const override {
		if (cpt == lock) {
			for (int i = lock; i < 13; ++i) {
				figures[i]->unlock();
			}
		}
	}
};

class HardFigure : public FigureManagement {
private:

public:
	HardFigure();

	void unlockFigure()const override {
		figures[cpt]->unlock();
	}
};

class HardcoreFigure : public FigureManagement {
private:

public:
	HardcoreFigure();

	void unlockFigure()const override {
		figures[cpt]->unlock();
	}
};