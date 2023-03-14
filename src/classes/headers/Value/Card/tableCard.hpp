#ifndef TABLE_CARD_HPP
#define TABLE_CARD_HPP

#include <iostream>
#include <vector>
#include "card.hpp"
#include "../../Inventory/children/DeckCard/deckCard.hpp"

using namespace std;

template <class T>
class TableCard : public InventoryHolder<T> {
    private:
        int neff;
        vector<T> listOfCards;
        const int max;

    public:
        TableCard(int max);
        TableCard(const TableCard& other);
        ~TableCard();
        void push(const T& C);
        vector<T>& getTableCard();
        void clearTable();
        void printCard();
        int getNeff();
        T& getTop();
        T pop();
};

template class TableCard<Card>;
template class TableCard<UnoCard>;

#endif