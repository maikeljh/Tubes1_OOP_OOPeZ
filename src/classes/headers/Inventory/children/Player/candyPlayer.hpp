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
        /* Ctor */
        CandyPlayer();
        CandyPlayer(DeckCard<Card> &DC, string nickname);

        /* Operator overloading */
        CandyPlayer& operator+(const Card& add);
        CandyPlayer& operator-(const Card& add);
        CandyPlayer& operator--();
        bool operator>(const CandyPlayer& other);
        bool operator<(const CandyPlayer& other);
        bool operator==(const CandyPlayer& other);

        /* Getter */
        Card getCard(int index);
        Combination& getCombo();
        long long int getPoint();
        AbilityCard& getAbilityCard();

        /* Other methods */
        void useAbilityCard();
        bool checkValidAbilityCard(string ability);
        void addAbilityCard(const AbilityCard& AC);
        void addPoint(long long int);
        void push(const Card& PC);
        Card pop();
        void printCard();
};

#endif