#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>
#include "../Inventory/children/Player/player.hpp"
#include "../Inventory/children/DeckCard/deckCard.hpp"
#include "../Value/Card/tableCard.hpp"

using namespace std;

class Game {
    protected:
        vector<Player> players;
        const int nPlayers = 7;
        bool isClockWise;
        int playerTurn;
        TableCard table;
        int lastIdxTurn;

    public:
        Game(int max);
        Game(const Game& other);
        ~Game();
        virtual void startGame() = 0;
        virtual int chooseWinner() = 0;
        void setIsClockWise(bool isClockWise);
        void setPlayerTurn(int playerTurn);
        bool getIsClockWise();
        int getPlayerTurn();
        Player& getPlayer();
        virtual bool isEndGame() = 0;
        int getLastIdxTurn();
        void setLastIdxTurn(int last);
        int getNPlayers();
};

#endif