#ifndef TABLE_CARD_HPP
#define TABLE_CARD_HPP

#include <iostream>
#include <vector>
#include "card.hpp"
#include "../../Inventory/children/DeckCard/deckCard.hpp"

using namespace std;

class TableCard {
    private:
        int neff;
        vector<Card> listOfCards;
        const int max;

    public:
        TableCard(int max);
        TableCard(const TableCard& other);
        ~TableCard();
        void addCard(const Card& C);
        vector<Card>& getTableCard();
        void clearTable();
        void printTable();
};

#endif