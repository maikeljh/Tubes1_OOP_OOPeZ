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
        long long int point; /* Determine the player's point */
        AbilityCard ability; /* Player's ability card */
        Combination kombo; /* Player's combo */
    
    public:
        /* Ctor */
        CandyPlayer();
        CandyPlayer(DeckCard<Card> &DC, string nickname);

        /* Operator overloading */
        CandyPlayer& operator+(const Card& add);
        CandyPlayer& operator+(long long int point);
        CandyPlayer& operator-(const Card& add);
        CandyPlayer& operator--();
        bool operator>(const CandyPlayer& other);
        bool operator<(const CandyPlayer& other);
        bool operator==(const CandyPlayer& other);

        /* Getter */
        Combination& getCombo();
        long long int getPoint();
        AbilityCard& getAbilityCard();

        /* Other methods */
        void useAbilityCard();
        bool checkValidAbilityCard(string ability);
        void addAbilityCard(const AbilityCard& AC);
        void printCard();
};

#endif