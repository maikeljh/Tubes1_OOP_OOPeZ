#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>
#include "../Inventory/children/Player/player.hpp"
#include "../Inventory/children/DeckCard/deckCard.hpp"
#include "../Value/Card/tableCard.hpp"

using namespace std;

class Game {
    protected:
        const int nPlayers = 7;
        bool isClockWise;
        int playerTurn;
        int firstIdxTurn;
        int lastIdxTurn;
        bool isReverse;
        bool valid;

    public:
        Game();
        Game(const Game& other);
        ~Game();
        virtual void startGame() = 0;
        virtual int chooseWinner() = 0;
        void setIsClockWise(bool isClockWise);
        void setPlayerTurn(int playerTurn);
        bool getIsClockWise();
        int getPlayerTurn();
        virtual bool isEndGame() = 0;
        int getFirstIdxTurn();
        void setFirstIdxTurn(int first);
        int getLastIdxTurn();
        void setLastIdxTurn(int last);
        int getNPlayers();
        bool getIsReverse();
        void setIsReverse(bool isReverse);
        bool getValid();
        void setValid(bool);
};

#endif