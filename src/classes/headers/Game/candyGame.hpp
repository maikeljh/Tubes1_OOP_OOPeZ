#ifndef CANDY_GAME_HPP
#define CANDY_GAME_HPP

#include <iostream>
#include "game.hpp"
#include "../Inventory/children/DeckCard/deckCard.hpp"
#include "../Inventory/children/Player/candyPlayer.hpp"

using namespace std;

class CandyGame : public Game {
    private:
        int round;
        long long int point;
        vector<CandyPlayer> players;
        DeckCard<Card> deck;
        DeckCard<AbilityCard> deckAbility;
        TableCard<Card> table;
        int phase;
        const long long int maxPoint = (long long) 1 << 32;

    public:
        /* ctor, dtor */
        CandyGame();
        CandyGame(const CandyGame& other);
        ~CandyGame();

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

        /* other functions */
        void startGame();
        int chooseWinner();
        int chooseRoundWinner();
        bool isEndGame();
};

#endif