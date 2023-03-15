#ifndef SWAP_CARD_HPP
#define SWAP_CARD_HPP

#include <iostream>
#include "../command.hpp"
#include "../../Game/game.hpp"
#include "next.hpp"

using namespace std;

class SwapCard: public Command<CandyGame> {
    public:
        /* Ctor */
        SwapCard();

        /* Method */
        void executeAction(CandyGame& Game); // Swap other player's cards with another player's cards
};

#endif