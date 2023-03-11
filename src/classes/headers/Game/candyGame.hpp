#ifndef CANDY_GAME_HPP
#define CANDY_GAME_HPP

#include <iostream>
#include "game.hpp"
#include "../Inventory/children/DeckCard/deckCard.hpp"

using namespace std;

class CandyGame : public Game {
    private:
        int round;
        long long int point;
        DeckCard<Card> deck;
        DeckCard<AbilityCard> deckAbility;
        const long long int maxPoint = (long long) 1 << 32;

    public:
        CandyGame();
        CandyGame(const CandyGame& other);
        ~CandyGame();
        void startGame();
        int chooseWinner();
        void setRound(int round);
        void setPoint(long long int point);
        int getRound();
        long long int getPoint();
        DeckCard<Card>& getDeckCard();
        DeckCard<AbilityCard>& getAbilityDeckCard();
        bool isEndGame();
};

#endif