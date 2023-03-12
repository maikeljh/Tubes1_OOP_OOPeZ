#ifndef TABLE_CARD_HPP
#define TABLE_CARD_HPP

#include <iostream>
#include <vector>
#include "card.hpp"
#include "../../Inventory/children/DeckCard/deckCard.hpp"

using namespace std;

template <class T>
class TableCard {
    private:
        int neff;
        vector<T> listOfCards;
        const int max;

    public:
        TableCard(int max);
        TableCard(const TableCard& other);
        ~TableCard();
        void addCard(const T& C);
        vector<T>& getTableCard();
        void clearTable();
        void printTable();
        int getNeff();
};

template class TableCard<Card>;
template class TableCard<UnoCard>;

#endif