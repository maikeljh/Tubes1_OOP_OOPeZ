#ifndef DECK_CARD_HPP
#define DECK_CARD_HPP

#include <iostream>
#include <vector>
#include "../../inventoryHolder.hpp"
#include "../../../Value/Card/card.hpp"
#include "../../../Value/Card/children/unoCard.hpp"
#include "../../../Value/Card/abilityCard.hpp"

using namespace std;

template <class T>
class DeckCard: public InventoryHolder<T>{
    private:
        vector<T> deck;
        int neff;
        int size;
    
    public:
        /* Ctor */
        DeckCard();
        DeckCard(int neff, int size);

        /* Operator overloading */
        DeckCard& operator=(const DeckCard& dc);
        DeckCard& operator+(const T& add);
        DeckCard& operator-(const T& min);
        DeckCard& operator--();

        /* Getter */
        int getNeff();
        int getSize();
        T& getCard(int i);

        /* Setter */
        void setCard(const T &card, int i);

        /* Other methods */
        T pop();
        void push(const T& Card);
        void printCard();
};

#endif