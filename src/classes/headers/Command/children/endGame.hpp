#ifndef END_GAME_HPP
#define END_GAME_HPP

#include <iostream>
#include "../command.hpp"
#include "../../Game/game.hpp"

using namespace std;

class EndGame: public Command<CandyGame> {
    public:
        EndGame();
        void executeAction(CandyGame& Game);
        void printWinner(CandyGame& Game);
};

#endif