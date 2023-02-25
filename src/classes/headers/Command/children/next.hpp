#ifndef NEXT_HPP
#define NEXT_HPP

#include <iostream>
#include "../command.hpp"
#include "../../Game/game.hpp"

using namespace std;

class Next: public Command {
    public:
        Next(); // ID = 1
        void skipTurn(Game& Game);
};

#endif