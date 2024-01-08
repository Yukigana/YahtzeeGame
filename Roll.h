#ifndef ROLL_H
#define ROLL_H

class DiceSet{
private :
    int* dices;
    bool* locks;

public:
    DiceSet();
    ~DiceSet();

    void print()const;

    void lockDices();
    void resetDices();

    void setDice(const int& nbDice, const int& value);

    int* getDices()const;
    bool getLock(const int& nbDice)const { return locks[nbDice]; };
};

class Roll{
    Roll();
    public:

    static void rollDices(DiceSet* set);
};

#endif // ROLL_H