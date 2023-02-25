#ifndef HALF_HPP
#define HALF_HPP

#include <iostream>
#include "../command.hpp"
#include "../../Game/game.hpp"

using namespace std;

class Half: public Command {
    public:
        Half(); // ID = 5
        void halfPrice(Game& Game);
};

#endif