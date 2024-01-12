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
	Difficulty difficulty; // Indice de difficult�

	int score; // Score des figures jou�
	friend class SaveYams;

protected :
	Figure** figures; // Liste des figures dans l'ordre � jouer

	int cpt; // Permet de savoir quel figures d�bloquer
	int lock; // Limite des figures jouables

public :
	FigureManagement(Difficulty d, const int l);

	void print()const; // Affiche les figures jouables
	void print(const int* dices)const; // Affiche les figures jouables avec leur score correspondant aux d�s indiqu�s

	void playFigure(const int* dices, const int& nbFigure); // Joue la figure choisi par le joueur avec les d�s du joueur

	bool canPlayFigure(const int& nbFigure)const;
	
	virtual void unlockFigure()const = 0;

	int getCpt()const { return cpt; };
	int getScore()const { return score; };

	std::string getOrder();
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
	HardcoreFigure(std::string s);

	void unlockFigure()const override {
		figures[cpt]->unlock();
	}
};