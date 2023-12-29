#ifndef ROLL_H
#define ROLL_H

class DiceSet{
    public:
    int dices[5];
    bool locks[5];

};

class Roll{
    Roll();
    public:
    static DiceSet rollDices();
    static DiceSet rollDices(DiceSet set);
};

#endif // ROLL_H