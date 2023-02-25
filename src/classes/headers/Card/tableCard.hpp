#ifndef TABLE_CARD_HPP
#define TABLE_CARD_HPP

#include <iostream>
#include "card.hpp"
#include "../Inventory/children/DeckCard/deckCard.hpp"

using namespace std;

class TableCard {
    private:
        int neff;
        DeckCard listOfCards;
        const int max = 5;

    public:
        TableCard();
        TableCard(const TableCard& other);
        ~TableCard();
};

#endif