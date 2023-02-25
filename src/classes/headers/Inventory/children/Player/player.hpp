#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>
#include "../../inventoryHolder.hpp"
#include "../DeckCard/deckCard.hpp"
#include "../../../Card/abilityCard.hpp"
#include "../../../Card/children/PlayerCard.hpp"

using namespace std;

class Player: public InventoryHolder {
    private:
        int id;
        string nickname;
        long long int point;
        PlayerCard *mainDeck;
        AbilityCard ability;
        static int playersCreated;
    
    public:
        Player();
        Player(DeckCard& DC, string nickname);
        Player& operator=(const Player&);
        void useAbilityCard();
        bool checkValidAbilityCard(string ability);
        void addAbilityCard(const AbilityCard& AC);
        Card getCard(int index);
};

#endif