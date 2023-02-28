#ifndef TABLE_CARD_HPP
#define TABLE_CARD_HPP

#include <iostream>
#include <vector>
#include "card.hpp"
#include "./children/playerCard.hpp"
#include "../Inventory/children/DeckCard/deckCard.hpp"

using namespace std;

class TableCard {
    private:
        int neff;
        vector<PlayerCard> listOfCards;
        const int max = 5;

    public:
        TableCard();
        TableCard(const TableCard& other);
        ~TableCard();
        void addCard(const PlayerCard& C);
        void clearTable();
        void printTable();
};

#endif