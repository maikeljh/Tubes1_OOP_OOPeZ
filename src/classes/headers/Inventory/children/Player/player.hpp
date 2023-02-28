#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>
#include <vector>
#include "../../inventoryHolder.hpp"
#include "../DeckCard/deckCard.hpp"
#include "../../../Card/abilityCard.hpp"
#include "../../../Card/children/playerCard.hpp"
#include "../../../Combination/combination.hpp"

using namespace std;

class Player: public InventoryHolder<PlayerCard> {
    private:
        int id;
        string nickname;
        long long int point;
        vector<PlayerCard> mainDeck;
        AbilityCard ability;
        static int playersCreated;
        Combination kombo;
    
    public:
        Player();
        Player(DeckCard& DC, string nickname);
        Player& operator=(const Player&);
        ~Player();
        void useAbilityCard();
        bool checkValidAbilityCard(string ability);
        void addAbilityCard(const AbilityCard& AC);
        Card getCard(int index);
        void push(const PlayerCard& PC);
        PlayerCard pop();
        void printPlayerCard();
        string getNickname();
        Combination getCombo();
        long long int getPoint();
};

#endif