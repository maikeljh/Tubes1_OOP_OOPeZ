#ifndef SWAP_CARD_HPP
#define SWAP_CARD_HPP

#include <iostream>
#include "../command.hpp"
#include "../../Game/game.hpp"
#include "next.hpp"

using namespace std;

class SwapCard: public Command {
    public:
        SwapCard(); // ID = 8
        void executeAction(CandyGame& Game);
};

#endif