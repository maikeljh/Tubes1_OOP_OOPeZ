#ifndef QUADRUPLE_HPP
#define QUADRUPLE_HPP

#include <iostream>
#include "../command.hpp"
#include "../commandParser.hpp"
#include "next.hpp"
#include "../../Game/game.hpp"

using namespace std;

class Quadruple: public Command<CandyGame> {
    public:
        /* Ctor */
        Quadruple();

        /* Method */
        void executeAction(CandyGame& Game); // Quadruple the current game point
};

#endif