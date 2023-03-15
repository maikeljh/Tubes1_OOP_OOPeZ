#ifndef CHECK_CARD_HPP
#define CHECK_CARD_HPP

#include <iostream>
#include "../command.hpp"
#include "../../Game/game.hpp"

using namespace std;

class CheckCard: public Command<CandyGame> {
    public:
        /* Ctor */
        CheckCard();

        /* Method */
        void executeAction(CandyGame& Game); // Print available player cards
};

#endif