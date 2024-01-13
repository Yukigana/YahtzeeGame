#include "Figure.h"

Brelan::Brelan(std::string n) : Figure(n) {}
Brelan::Brelan(std::string n, const bool& activated): Figure(n, activated) {}
Brelan::~Brelan() {}

Square::Square(std::string n) : Figure(n) {}
Square::Square(std::string n, const bool& activated): Figure(n, activated) {}
Square::~Square(){}

Full::Full(std::string n) : Figure(n) {}
Full::Full(std::string n, const bool& activated): Figure(n, activated) {}
Full::~Full(){}

SmallStraight::SmallStraight(std::string n) : Figure(n) {}
SmallStraight::SmallStraight(std::string n, const bool& activated): Figure(n, activated) {}
SmallStraight::~SmallStraight(){}

LargeStraight::LargeStraight(std::string n) : Figure(n) {}
LargeStraight::LargeStraight(std::string n, const bool& activated): Figure(n, activated) {}
LargeStraight::~LargeStraight(){}

Yahtzee::Yahtzee(std::string n) : Figure(n) {}
Yahtzee::Yahtzee(std::string n, const bool& activated): Figure(n, activated) {}
Yahtzee::~Yahtzee(){}

Chance::Chance(std::string n) : Figure(n) {}
Chance::Chance(std::string n, const bool& activated): Figure(n, activated) {}
Chance::~Chance(){}