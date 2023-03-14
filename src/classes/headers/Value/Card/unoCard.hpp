#ifndef UNO_CARD_HPP
#define UNO_CARD_HPP

#include "card.hpp"
#include "abilityCard.hpp"
#include <iostream>
using namespace std;

class UnoCard : public Card, public AbilityCard {
    private:
        bool isNumber;

    public:
        /* ctor */
        UnoCard();
        UnoCard(int number, string color, string type);

        /* operators */
        UnoCard& operator= (const UnoCard&);
        bool operator== (const UnoCard&);

        /* getter */
        bool getIsNumber();

        /* other functions */
        void printDetail();
};

#endif