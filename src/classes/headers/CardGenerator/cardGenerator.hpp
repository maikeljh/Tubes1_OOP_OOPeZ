#ifndef CARD_GENERATOR_HPP
#define CARD_GENERATOR_HPP

#include "../Inventory/children/DeckCard/deckCard.hpp"
#include "../Exception/exception.h"
#include <iostream>
using namespace std;

class CardGenerator {
    public:
        /* Ctor */
        CardGenerator();

        /* Methods */
        DeckCard<Card> readFile(string pathfile); // Read file to generate order cards
        DeckCard<Card> randomizeCard(); // Automatically generate order cards
        DeckCard<AbilityCard> generateAbilityDeck(); // Automatically generate ability deck
        DeckCard<UnoCard> readUnoFile(string pathfile); // Read file to generate order UNO cards
        DeckCard<UnoCard> randomizeUnoCard(); // Automatically generate order UNO cards
};

#endif