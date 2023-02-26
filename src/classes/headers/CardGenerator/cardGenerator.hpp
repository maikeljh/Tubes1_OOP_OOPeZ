#ifndef CARD_GENERATOR_HPP
#define CARD_GENERATOR_HPP

#include "../Inventory/children/DeckCard/deckCard.hpp"
#include "../Inventory/children/DeckCard/deckAbilityCard.hpp"
#include <iostream>
using namespace std;

class CardGenerator {
    public:
        CardGenerator();
        DeckCard readFile(string pathfile);
        DeckCard randomizeCard();
        DeckAbilityCard generateAbilityDeck();
};

#endif