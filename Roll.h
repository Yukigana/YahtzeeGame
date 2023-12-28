#ifndef ROLL_H
#define ROLL_H

class DiceSet{
    int dices[5];
    bool locks[5];
    public:

};

class Roll{
    Roll();
    public:
    static DiceSet rollDices();
    static DiceSet rollDices(DiceSet set);
};

#endif // ROLL_H