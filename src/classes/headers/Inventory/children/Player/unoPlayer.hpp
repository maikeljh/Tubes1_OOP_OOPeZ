#ifndef UNO_PLAYER_HPP
#define UNO_PLAYER_HPP

#include <iostream>
#include <vector>
#include "../../inventoryHolder.hpp"
#include "./player.hpp"
#include "../DeckCard/deckCard.hpp"
#include "../../../Value/Card/abilityCard.hpp"
#include "../../../Value/Combination/combination.hpp"

using namespace std;

class UnoPlayer: public Player<BaseCard>{
    private:
        
    public:
        UnoPlayer();
        UnoPlayer(DeckCard<BaseCard> &DC, string nickname);
        UnoPlayer& operator=(UnoPlayer&);
        UnoPlayer& operator+(const BaseCard& add);
        UnoPlayer& operator-();
        ~UnoPlayer();
        void printCard();
};

#endif