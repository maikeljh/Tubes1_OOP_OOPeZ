#ifndef ABILITY_CARD_HPP
#define ABILITY_CARD_HPP

#include <iostream>
using namespace std;

class AbilityCard {
    private:
        int owner;
        string type;
    
    public:
        AbilityCard();
        AbilityCard(int owner, string type);
        AbilityCard(const AbilityCard& other);
        ~AbilityCard();
};

#endif