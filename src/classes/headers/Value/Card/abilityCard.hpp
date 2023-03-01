#ifndef ABILITY_CARD_HPP
#define ABILITY_CARD_HPP

#include <iostream>
using namespace std;

class AbilityCard {
    private:
        int owner;
        string type;
        bool useable;
    
    public:
        AbilityCard();
        AbilityCard(string type);
        AbilityCard(int owner, string type);
        AbilityCard(const AbilityCard& other);
        void setOwner(int id);
        int getOwner();
        string getType();
        bool getUseable();
        void setUseable();
};

#endif