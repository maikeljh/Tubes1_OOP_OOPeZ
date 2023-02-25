#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>
#include "../../inventoryHolder.hpp"
#include "../DeckCard/deckCard.hpp"

using namespace std;

class Player: public InventoryHolder {
    private:
        int id;
        string nickname;
        long long int point;
        DeckCard mainDeck;
    
    public:
        Player();
        Player& operator=(const Player&);
};

#endif