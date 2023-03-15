#ifndef SWITCH_HPP
#define SWITCH_HPP

#include <iostream>
#include "../command.hpp"
#include "../../Game/game.hpp"
#include "next.hpp"

using namespace std;

class Switch: public Command<CandyGame> {
    public:
        /* Ctor */
        Switch();

        /* Method */
        void executeAction(CandyGame& Game); // Switch the current player's cards with another player's cards
};

#endif