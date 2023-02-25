#ifndef DECK_CARD_HPP
#define DECK_CARD_HPP

#include <iostream>
#include "../../inventoryHolder.hpp"
#include "../../../Card/card.hpp"

using namespace std;

class DeckCard: public InventoryHolder {
    protected:
        Card *deck;
        int neff;
        const int size = 52;
    
    public:
        DeckCard();
        DeckCard(int neff);
        DeckCard(const DeckCard& other);
        ~DeckCard();
};

#endif