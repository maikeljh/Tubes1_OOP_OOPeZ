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

class Player: public InventoryHolder {
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
        Player(DeckCard<Card> &DC, string nickname);
        Player& operator=(const Player&);
        Player& Player::operator+(const Card& add);
        Player& Player::operator-();
        bool Player::operator>(const Player& other);
        bool Player::operator<(const Player& other);
        bool Player::operator==(const Player& other);
        ~Player();
        void useAbilityCard();
        bool checkValidAbilityCard(string ability);
        void addAbilityCard(const AbilityCard& AC);
        void addPoint(long long int);
        Card getCard(int index);
        void push(const PlayerCard& PC);
        PlayerCard pop();
        void printCard();
        string getNickname();
        Combination getCombo();
        long long int getPoint();
        
};

#endif