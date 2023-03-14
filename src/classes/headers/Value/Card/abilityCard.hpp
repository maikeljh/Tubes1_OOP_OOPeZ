#ifndef ABILITY_CARD_HPP
#define ABILITY_CARD_HPP

#include <iostream>
using namespace std;

class AbilityCard {
    protected:
        string type;
        bool useable;
    
    public:
        /* ctor */
        AbilityCard();
        AbilityCard(string type);
        AbilityCard(const AbilityCard& other);
        
        /* getter */
        string getType();
        bool getUseable();

        /* setter */
        void setType(string type);
        void setUseable(bool);
};

#endif