#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>
#include "../Inventory/children/Player/player.hpp"
#include "../Inventory/children/DeckCard/deckCard.hpp"
#include "../Value/Card/tableCard.hpp"

using namespace std;

class Game {
    private:
        int round;
        vector<Player> players;
        const int nPlayers = 7;
        long long int point;
        DeckCard<Card> deck;
        bool isClockWise;
        int playerTurn;
        TableCard table;
        const long long int maxPoint = (long long) 1 << 32;
        int lastIdxTurn;

    public:
        Game();
        Game(const Game& other);
        ~Game();
        void startGame();
        int chooseWinner();
        void setRound(int round);
        void setPoint(long long int point);
        void setIsClockWise(bool isClockWise);
        void setPlayerTurn(int playerTurn);
        int getRound();
        long long int getPoint();
        DeckCard<Card>& getDeckCard();
        bool getIsClockWise();
        int getPlayerTurn();
        Player getPlayer();
        bool isEndGame();
        int getLastIdxTurn();
        void setLastIdxTurn(int last);
};

#endif