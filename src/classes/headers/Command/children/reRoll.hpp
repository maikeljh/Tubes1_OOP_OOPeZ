#ifndef RE_ROLL_HPP
#define RE_ROLL_HPP

#include <iostream>
#include "../command.hpp"
#include "next.hpp"
#include "../../Game/candyGame.hpp"

using namespace std;

class ReRoll: public Command<CandyGame> {
    public:
        /* Ctor */
        ReRoll();

        /* Method */
        void executeAction(CandyGame&); // Re-roll the current player cards with new cards from deck
};

#endif