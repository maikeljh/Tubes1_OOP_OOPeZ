#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>
#include <vector>
#include "../../inventoryHolder.hpp"
#include "../DeckCard/deckCard.hpp"
#include "../../../Value/Card/abilityCard.hpp"
#include "../../../Value/Combination/combination.hpp"

using namespace std;

class Player: public InventoryHolder {
    private:
        int id;
        string nickname;
        long long int point;
        vector<Card> mainDeck;
        AbilityCard ability;
        static int playersCreated;
        Combination kombo;
    
    public:
        Player();
        Player(DeckCard<Card> &DC, string nickname);
        Player& operator=(const Player&);
        ~Player();
        void useAbilityCard();
        bool checkValidAbilityCard(string ability);
        void addAbilityCard(const AbilityCard& AC);
        Card getCard(int index);
        void push(const Card& PC);
        Card pop();
        void printPlayerCard();
        string getNickname();
        Combination getCombo();
        long long int getPoint();
};

#endif