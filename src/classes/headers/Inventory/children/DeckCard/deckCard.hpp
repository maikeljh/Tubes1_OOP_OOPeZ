#ifndef DECK_CARD_HPP
#define DECK_CARD_HPP

#include <iostream>
#include <vector>
#include "../../inventoryHolder.hpp"
#include "../../../Value/Card/card.hpp"
#include "../../../Value/Card/abilityCard.hpp"

using namespace std;

template <class T>
class DeckCard: public InventoryHolder{
    private:
        vector<T> deck;
        int neff;
        int size;
    
    public:
        DeckCard();
        DeckCard(int neff, int size);
        DeckCard(const DeckCard& other);
        ~DeckCard();
        T pop();
        void push(const T& Card);
        int getNeff();
        int getSize();
        void printCard();
};

#endif