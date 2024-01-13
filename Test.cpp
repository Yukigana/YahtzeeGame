#include <iostream>

#include "Test.h"
#include"Figure.h"

void Test::testFigures()const {

	Classic<1> one("One");
	Classic<4> four("Four");

	Brelan brelan("Brelan");
	Square square("Square");
	Full full("Full");
	SmallStraight smallStraight("SmallStraight");
	LargeStraight largeStraight("LargeStraight");
	Yahtzee yahtzee("Yahtzee");
	Chance chance("Chance");

	int diceValues1[] = { 1, 1, 1, 1, 1, 0};
	int diceValues2[] = { 1, 1, 1, 1, 0, 1};
	int diceValues3[] = { 0, 3, 0, 2, 0, 0};
	int diceValues4[] = { 5, 0, 0, 0, 0, 0};

    std::cout << "Classic 1 Score: " << one.getScore(diceValues1) << " (Expected: 1)" << std::endl;
    std::cout << "Classic 2 Score: " << four.getScore(diceValues1) << " (Expected: 4)" << std::endl;
    std::cout << "Brelan Score: " << brelan.getScore(diceValues1) << " (Expected: 0 or some calculated value)" << std::endl;
    std::cout << "Square Score: " << square.getScore(diceValues1) << " (Expected: 0 or some calculated value)" << std::endl;
    std::cout << "Full Score: " << full.getScore(diceValues1) << " (Expected: 25 or 0)" << std::endl;
    std::cout << "Small Straight Score: " << smallStraight.getScore(diceValues1) << " (Expected: 30 or 0)" << std::endl;
    std::cout << "Large Straight Score: " << largeStraight.getScore(diceValues1) << " (Expected: 40 or 0)" << std::endl;
    std::cout << "Yahtzee Score: " << yahtzee.getScore(diceValues1) << " (Expected: 0 or 50)" << std::endl;
    std::cout << "Chance Score: " << chance.getScore(diceValues1) << " (Expected: Sum of all dice values)" << std::endl;


    std::cout << "Classic 1 Score: " << one.getScore(diceValues2) << " (Expected: 1)" << std::endl;
    std::cout << "Classic 2 Score: " << four.getScore(diceValues2) << " (Expected: 4)" << std::endl;
    std::cout << "Brelan Score: " << brelan.getScore(diceValues2) << " (Expected: 0 or some calculated value)" << std::endl;
    std::cout << "Square Score: " << square.getScore(diceValues2) << " (Expected: 0 or some calculated value)" << std::endl;
    std::cout << "Full Score: " << full.getScore(diceValues2) << " (Expected: 25 or 0)" << std::endl;
    std::cout << "Small Straight Score: " << smallStraight.getScore(diceValues2) << " (Expected: 30 or 0)" << std::endl;
    std::cout << "Large Straight Score: " << largeStraight.getScore(diceValues2) << " (Expected: 40 or 0)" << std::endl;
    std::cout << "Yahtzee Score: " << yahtzee.getScore(diceValues2) << " (Expected: 0 or 50)" << std::endl;
    std::cout << "Chance Score: " << chance.getScore(diceValues2) << " (Expected: Sum of all dice values)" << std::endl;


    std::cout << "Classic 1 Score: " << one.getScore(diceValues3) << " (Expected: 1)" << std::endl;
    std::cout << "Classic 2 Score: " << four.getScore(diceValues3) << " (Expected: 4)" << std::endl;
    std::cout << "Brelan Score: " << brelan.getScore(diceValues3) << " (Expected: 0 or some calculated value)" << std::endl;
    std::cout << "Square Score: " << square.getScore(diceValues3) << " (Expected: 0 or some calculated value)" << std::endl;
    std::cout << "Full Score: " << full.getScore(diceValues3) << " (Expected: 25 or 0)" << std::endl;
    std::cout << "Small Straight Score: " << smallStraight.getScore(diceValues3) << " (Expected: 30 or 0)" << std::endl;
    std::cout << "Large Straight Score: " << largeStraight.getScore(diceValues3) << " (Expected: 40 or 0)" << std::endl;
    std::cout << "Yahtzee Score: " << yahtzee.getScore(diceValues3) << " (Expected: 0 or 50)" << std::endl;
    std::cout << "Chance Score: " << chance.getScore(diceValues3) << " (Expected: Sum of all dice values)" << std::endl;


    std::cout << "Classic 1 Score: " << one.getScore(diceValues4) << " (Expected: 1)" << std::endl;
    std::cout << "Classic 2 Score: " << four.getScore(diceValues4) << " (Expected: 4)" << std::endl;
    std::cout << "Brelan Score: " << brelan.getScore(diceValues4) << " (Expected: 0 or some calculated value)" << std::endl;
    std::cout << "Square Score: " << square.getScore(diceValues4) << " (Expected: 0 or some calculated value)" << std::endl;
    std::cout << "Full Score: " << full.getScore(diceValues4) << " (Expected: 25 or 0)" << std::endl;
    std::cout << "Small Straight Score: " << smallStraight.getScore(diceValues4) << " (Expected: 30 or 0)" << std::endl;
    std::cout << "Large Straight Score: " << largeStraight.getScore(diceValues4) << " (Expected: 40 or 0)" << std::endl;
    std::cout << "Yahtzee Score: " << yahtzee.getScore(diceValues4) << " (Expected: 0 or 50)" << std::endl;
    std::cout << "Chance Score: " << chance.getScore(diceValues4) << " (Expected: Sum of all dice values)" << std::endl;
    
    delete[](diceValues1);
    delete[](diceValues2);
    delete[](diceValues3);
    delete[](diceValues4);
}