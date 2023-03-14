#ifndef CHECK_CARD_HPP
#define CHECK_CARD_HPP

#include <iostream>
#include "../command.hpp"
#include "../../Game/game.hpp"

using namespace std;

class CheckCard: public Command<CandyGame> {
    public:
        CheckCard();
        void executeAction(CandyGame& Game);
};

#endif