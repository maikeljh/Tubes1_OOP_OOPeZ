#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>
#include "../Inventory/children/Player/player.hpp"
#include "../Inventory/children/DeckCard/deckCard.hpp"
#include "../Inventory/children/TableCard/tableCard.hpp"

using namespace std;

class Game {
    protected:
        const int nPlayers = 7; /* Determine how many players should be created in this game */
        bool valid; /* Valid if the current player finished his/her turn */
        int playerTurn; /* Determine which current player should be doing action(s) */

    public:
        /* ctor */
        Game();

        /* getter */
        int getNPlayers();
        bool getValid();
        int getPlayerTurn();

        /* setter */
        void setPlayerTurn(int);
        void setValid(bool);

        /* pure virtual methods */
        virtual void startGame() = 0;
        virtual int chooseWinner() = 0;
        virtual bool isEndGame() = 0;
        
};

#endif