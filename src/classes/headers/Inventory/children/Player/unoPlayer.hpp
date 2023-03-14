#ifndef UNO_PLAYER_HPP
#define UNO_PLAYER_HPP

#include <iostream>
#include <vector>
#include "../../inventoryHolder.hpp"
#include "./player.hpp"
#include "../DeckCard/deckCard.hpp"
#include "../../../Value/Card/children/unoCard.hpp"
#include "../../../Value/Combination/combination.hpp"

using namespace std;

class UnoPlayer: public Player<UnoCard>{
    public:
        UnoPlayer();
        UnoPlayer(DeckCard<UnoCard> &DC, string nickname);
        UnoPlayer& operator+(const UnoCard& add);
        UnoPlayer& operator-(const UnoCard& add);
        UnoPlayer& operator--();
        ~UnoPlayer();
        UnoCard getCard(int index);
        void printCard();
        void push(const UnoCard& PC);
        UnoCard pop();
};

#endif