#ifndef ABILITY_CARD_HPP
#define ABILITY_CARD_HPP

#include <iostream>
using namespace std;

class AbilityCard {
    private:
        string type;
        bool useable;
    
    public:
        AbilityCard();
        AbilityCard(string type);
        AbilityCard(const AbilityCard& other);
        string getType();
        void setType(string type);
        bool getUseable();
        void setUseable(bool);
};

#endif