#ifndef QUADRUPLE_HPP
#define QUADRUPLE_HPP

#include <iostream>
#include "../command.hpp"
#include "../../Game/game.hpp"

using namespace std;

class Quadruple: public Command {
    public:
        Quadruple(); // ID = 4
        void useAbilty(Game& Game);
};

#endif