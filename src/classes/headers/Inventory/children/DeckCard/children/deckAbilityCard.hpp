#ifndef DECK_ABILITY_CARD_HPP
#define DECK_ABILITY_CARD_HPP

#include <iostream>
#include "../deckCard.hpp"

using namespace std;

class DeckAbilityCard: public DeckCard {
    private:
        const int max = 7;
    
    public:
        DeckAbilityCard();
};

#endif