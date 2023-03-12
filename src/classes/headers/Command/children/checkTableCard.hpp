#ifndef CHECK_TABLE_CARD_HPP
#define CHECK_TABLE_CARD_HPP

#include <iostream>
#include "../command.hpp"
#include "../../Game/game.hpp"

using namespace std;

class CheckTableCard: public Command {
    public:
        CheckTableCard();
        void executeAction(CandyGame& Game);
};

#endif