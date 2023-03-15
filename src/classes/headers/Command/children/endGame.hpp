#ifndef END_GAME_HPP
#define END_GAME_HPP

#include <iostream>
#include "../command.hpp"
#include "../../Game/game.hpp"

using namespace std;

class EndGame: public Command<CandyGame> {
    public:
        /* Ctor */
        EndGame();

        /* Methods */
        void executeAction(CandyGame& Game); // Execute print leaderboard
        void printWinner(CandyGame& Game); // Print winner
};

#endif