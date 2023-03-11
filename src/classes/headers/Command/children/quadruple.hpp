#ifndef QUADRUPLE_HPP
#define QUADRUPLE_HPP

#include <iostream>
#include "../command.hpp"
#include "../commandParser.hpp"
#include "next.hpp"
#include "../../Game/game.hpp"

using namespace std;

class Quadruple: public Command {
    public:
        Quadruple(); // ID = 4
        void executeAction(CandyGame& Game);
};

#endif