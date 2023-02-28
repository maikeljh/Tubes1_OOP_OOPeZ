#ifndef DECK_ABILITY_CARD_HPP
#define DECK_ABILITY_CARD_HPP

#include <iostream>
#include <vector>
#include "../../../Card/abilityCard.hpp"
#include "../../inventoryHolder.hpp"

using namespace std;

class DeckAbilityCard: public InventoryHolder {
    private:
        vector<AbilityCard> deck;
        int neff;
        const int size = 7;

    public:
        DeckAbilityCard();
        DeckAbilityCard(int neff);
        DeckAbilityCard(const DeckAbilityCard& other);
        ~DeckAbilityCard();
        AbilityCard pop();
        void push(const AbilityCard& Card);
        int getNeff();
        int getSize();
        void printDeckCard();
};

#endif