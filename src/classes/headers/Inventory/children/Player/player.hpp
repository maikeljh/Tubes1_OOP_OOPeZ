#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>
#include "../../inventoryHolder.hpp"
#include "../DeckCard/deckCard.hpp"
#include "../../../Card/abilityCard.hpp"
#include "../../../Card/Card.hpp"

using namespace std;

class Player: public InventoryHolder {
    private:
        const int id;
        string nickname;
        long long int point;
        Card *mainDeck;
        AbilityCard ability;
        static int playersCreated;
    
    public:
        Player();
        Player& operator=(const Player&);
        void useAbilityCard();
        bool checkValidAbilityCard(string ability);
        void addAbilityCard(const AbilityCard& AC);
        Card getCard(int index);
        void setNickname(string name);
};

#endif