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
        bool valid;
        int playerTurn;

    public:
        Game();
        Game(const Game& other);
        ~Game();
        virtual void startGame() = 0;
        virtual int chooseWinner() = 0;
        virtual bool isEndGame() = 0;
        int getNPlayers();
        bool getValid();
        void setValid(bool);
        int getPlayerTurn();
        void setPlayerTurn(int);
};

#endif