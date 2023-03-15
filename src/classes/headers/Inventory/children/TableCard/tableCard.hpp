#ifndef TABLE_CARD_HPP
#define TABLE_CARD_HPP

#include <iostream>
#include <vector>
#include "../../../Value/Card/card.hpp"
#include "../DeckCard/deckCard.hpp"

using namespace std;

template <class T>
class TableCard : public InventoryHolder<T> {
    private:
        int neff;
        vector<T> listOfCards;
        const int max;

    public:
        /* Ctor */
        TableCard(int max);
        TableCard(const TableCard& other);
        
        /* Getter */
        vector<T>& getTableCard();
        int getNeff();
        T& getTop();

        /* Other methods */
        void push(const T& C);
        void clearTable();
        void printCard();
        T pop();
};

template class TableCard<Card>;
template class TableCard<UnoCard>;

#endif