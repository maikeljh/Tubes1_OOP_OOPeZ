#ifndef CANDY_GAME_HPP
#define CANDY_GAME_HPP

#include <iostream>
#include "game.hpp"
#include "../Inventory/children/DeckCard/deckCard.hpp"
#include "../Inventory/children/Player/candyPlayer.hpp"

using namespace std;

class CandyGame : public Game {
    private:
        int round; /* Determine the current round */
        long long int point; /* Determine the current game point */
        vector<CandyPlayer> players; /* List of players */
        DeckCard<Card> deck; /* Deck Card */
        DeckCard<AbilityCard> deckAbility; /* Deck Ability Card */
        TableCard<Card> table; /* Table Card */
        int phase; /* Determine the current phase */
        const long long int maxPoint = (long long) 1 << 32; /* Determine the maximum point to win the game */

    public:
        /* ctor */
        CandyGame();
        CandyGame(const CandyGame& other);

        /* getter */
        int getRound();
        long long int getPoint();
        vector<CandyPlayer>& getPlayers();
        CandyPlayer& getPlayer(int idx);
        DeckCard<Card>& getDeckCard();
        DeckCard<AbilityCard>& getAbilityDeckCard();
        TableCard<Card>& getTableCard();
        int getPhase();
        long long int getMaxPoint();

        /* setter */
        void setRound(int round);
        void setPoint(long long int point);
        void setPhase(int);

        /* other methods */
        void startGame();
        int chooseWinner();
        int chooseRoundWinner();
        bool isEndGame();
};

#endif