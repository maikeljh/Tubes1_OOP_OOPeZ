#ifndef ABILITY_CARD_HPP
#define ABILITY_CARD_HPP

#include <iostream>
using namespace std;

class AbilityCard {
    protected:
        string type; // Determine the ability
        bool useable; // True if the card can be used
    
    public:
        /* ctor */
        AbilityCard();
        AbilityCard(string type);
        
        /* operator overloading */
        bool operator==(const AbilityCard&);

        /* getter */
        string getType();
        bool getUseable();

        /* setter */
        void setType(string type);
        void setUseable(bool);
};

#endif