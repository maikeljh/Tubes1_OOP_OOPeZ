#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>
#include "../Inventory/children/Player/player.hpp"
#include "../Inventory/children/DeckCard/deckCard.hpp"
#include "../Inventory/children/TableCard/tableCard.hpp"

using namespace std;

class Game {
    protected:
        const int nPlayers = 7;
        bool valid;
        int playerTurn;

    public:
        /* ctor, dtor */
        Game();
        Game(const Game& other);
        ~Game();

        /* getter */
        int getNPlayers();
        bool getValid();
        int getPlayerTurn();

        /* setter */
        void setPlayerTurn(int);
        void setValid(bool);

        /* functions */
        virtual void startGame() = 0;
        virtual int chooseWinner() = 0;
        virtual bool isEndGame() = 0;
        
};

#endif