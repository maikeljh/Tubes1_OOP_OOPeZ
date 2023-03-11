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
        int idxReverse; // indeks sebelum pemakai reverse
        bool isReverse;
        bool valid;

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
        Player& getPlayer(int idx);
        virtual bool isEndGame() = 0;
        int getLastIdxTurn();
        void setLastIdxTurn(int last);
        int getNPlayers();
        int getIdxReverse();
        void setIdxReverse(int idxReverse);
        bool getIsReverse();
        void setIsReverse(bool isReverse);
        bool getValid();
        void setValid(bool);
};

#endif