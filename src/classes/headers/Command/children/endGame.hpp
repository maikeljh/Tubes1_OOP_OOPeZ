#ifndef END_GAME_HPP
#define END_GAME_HPP

#include <iostream>
#include "../command.hpp"
#include "../../Game/game.hpp"

using namespace std;

class EndGame: public Command {
    public:
        EndGame(); // ID = 11
        void printLeaderboard(const Game& Game);
        void printWinner(const Game& Game);
};

#endif