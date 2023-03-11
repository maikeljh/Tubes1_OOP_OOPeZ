#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>
#include <vector>
#include "../../inventoryHolder.hpp"
#include "../DeckCard/deckCard.hpp"
#include "../../../Value/Card/abilityCard.hpp"
#include "../../../Value/Combination/combination.hpp"

using namespace std;

class Player: public InventoryHolder<Card>{
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
        Player& operator+(const Card& add);
        Player& operator-();
        bool operator>(const Player& other);
        bool operator<(const Player& other);
        bool operator==(const Player& other);
        ~Player();
        void useAbilityCard();
        bool checkValidAbilityCard(string ability);
        void addAbilityCard(const AbilityCard& AC);
        void addPoint(long long int);
        Card getCard(int index);
        void push(const Card& PC);
        Card pop();
        void printCard();
        string getNickname();
        Combination& getCombo();
        long long int getPoint();
        vector<Card>& getDeckPlayer();
        AbilityCard& getAbilityCard();
};

#endif