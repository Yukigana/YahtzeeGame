#pragma once
#include <vector>
#include <string>

class Figure
{

	std::string name;
	bool activated;
	bool played;


public :
	Figure(std::string n) : name(n), activated(true), played(false) {};
	Figure(std::string n, const bool& a) : name(n), activated(a), played(false) {};

	void playFigure() { played = true; };
	void unlock() { activated = true; };

	virtual int getScore(const int* diceValues)const = 0;
	bool getPlayed()const { return played; };
	bool getActivated()const { return activated; };
	std::string getName()const { return name; };

};


template<int value>
class Classic : public Figure {
private :
	const int classicValue;

public :
	Classic(std::string n) : Figure(n), classicValue(value) {}
	Classic(std::string n, const bool& activated): Figure(n, activated), classicValue(value) {}

	int getScore(const int* diceValues)const override {
		return diceValues[value - 1] * value;
	}
};



class Brelan : public Figure {
public :
	Brelan(std::string n);
	Brelan(std::string n, const bool& activated);

	int getScore(const int* diceValues)const override {
		int score = 0;

		for (int i = 0; i < 6; ++i) {
			// Si le joueur poss�de plus de trois fois la m�me valeur alors elle est consid�r� comme un brelan et le score est calcul�
			if (diceValues[i] >= 3) score = 3 * (i + 1);
		}
		return score;
	};
};

class Square : public Figure {
public :
	Square(std::string n);
	Square(std::string n, const bool& activated);

	int getScore(const int* diceValues)const override {
		int score = 0;

		for (int i = 0; i < 6; ++i) {
			if(diceValues[i] >= 4) score = 4 * (i + 1);
		}

		return score;
	}
};

class Full : public Figure {
public :
	Full(std::string n);
	Full(std::string n, const bool& activated);

	int getScore(const int* diceValues)const override {
		int score = 0;
		bool two = false, tree = false;
		for (int i = 0; i < 6; ++i) {
			if (diceValues[i] == 2) two = true;
			else if (diceValues[i] == 3) tree = true;
		}
		if (two || tree) score = 25;
		return score;
	}
};

class SmallStraight : public Figure {
public :
	SmallStraight(std::string n);
	SmallStraight(std::string n, const bool& activated);

	int getScore(const int* diceValues)const override {
		int score = 0;
		bool straight = false;
		int cpt = 0;

		for (int i = 0; i < 6; ++i) {
			if (diceValues[i] == 0) {
				if (straight) {
					if (cpt >= 4) break;
					else {
						straight = false;
						cpt = 0;
					}
				}
			}
			else if (diceValues[i] > 0) {
				straight = true;
				++cpt;
			}
		}
		if (cpt >= 4) score = 30;

		return score;
	}
};

class LargeStraight : public Figure {
public :
	LargeStraight(std::string n);
	LargeStraight(std::string n, const bool& activated);

	int getScore(const int* diceValues)const override {
		int score = 0;
		bool straight = true;
		for (int i = 1; i < 5; ++i) {
			if (diceValues[i] == 0) straight = false;
		}
		if ((diceValues[0] == 1 || diceValues[5] == 1) && straight) score = 40;

		return score;
	}
};

class Yahtzee : public Figure {
public :
	Yahtzee(std::string n);
	Yahtzee(std::string n, const bool& activated);

	int getScore(const int* diceValues)const override {
		int score = 0;
		for (int i = 0; i < 6; ++i) {
			if (diceValues[i] == 5) {
				score = 50;
				break;
			}
		}
		return score;
	}
};

class Chance : public Figure {
public :
	Chance(std::string n);
	Chance(std::string n, const bool& activated);

	int getScore(const int* diceValues)const override {
		int score = 0;
		for (int i = 0; i < 6; ++i) {
			score += diceValues[i] * (i + 1);
		}
		return score;
	}
};

