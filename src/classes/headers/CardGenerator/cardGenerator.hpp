#ifndef CARD_GENERATOR_HPP
#define CARD_GENERATOR_HPP

#include "../Inventory/children/DeckCard/deckCard.hpp"
#include "../Exception/exception.h"
#include <iostream>
using namespace std;

class CardGenerator {
    public:
        CardGenerator();
        DeckCard<Card> readFile(string pathfile);
        DeckCard<Card> randomizeCard();
        DeckCard<AbilityCard> generateAbilityDeck();
        DeckCard<UnoCard> readUnoFile(string pathfile);
        DeckCard<UnoCard> randomizeUnoCard();
};

#endif