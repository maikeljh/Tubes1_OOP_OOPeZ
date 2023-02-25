#ifndef REVERSE_HPP
#define REVERSE_HPP

#include <iostream>
#include "../command.hpp"
#include "../../Game/game.hpp"

using namespace std;

class Reverse: public Command {
    public:
        Reverse(); // ID = 7
        void reverseTurn(const Game& Game);
};

#endif