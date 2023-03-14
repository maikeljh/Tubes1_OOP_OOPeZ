#ifndef CANDY_PLAYER_HPP
#define CANDY_PLAYER_HPP

#include <iostream>
#include <vector>
#include "../../inventoryHolder.hpp"
#include "./player.hpp"
#include "../DeckCard/deckCard.hpp"
#include "../../../Value/Card/abilityCard.hpp"
#include "../../../Value/Combination/combination.hpp"

using namespace std;

class CandyPlayer: public Player<Card>{
    private:
        long long int point;
        AbilityCard ability;
        Combination kombo;
    
    public:
        CandyPlayer();
        CandyPlayer(DeckCard<Card> &DC, string nickname);
        CandyPlayer& operator+(const Card& add);
        CandyPlayer& operator--();
        bool operator>(const CandyPlayer& other);
        bool operator<(const CandyPlayer& other);
        bool operator==(const CandyPlayer& other);
        ~CandyPlayer();
        void useAbilityCard();
        bool checkValidAbilityCard(string ability);
        void addAbilityCard(const AbilityCard& AC);
        void addPoint(long long int);
        Card getCard(int index);
        void push(const Card& PC);
        Card pop();
        void printCard();
        Combination& getCombo();
        long long int getPoint();
        AbilityCard& getAbilityCard();
};

#endif