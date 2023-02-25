#ifndef CARD_GENERATOR_HPP
#define CARD_GENERATOR_HPP

#include "../Inventory/children/DeckCard/deckCard.hpp"
#include <iostream>
using namespace std;

class CardGenerator {
    public:
        CardGenerator();
        DeckCard readFile();
        DeckCard randomizeCard();
};

#endif