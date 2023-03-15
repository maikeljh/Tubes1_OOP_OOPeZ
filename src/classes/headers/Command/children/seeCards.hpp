#ifndef SEE_CARDS_HPP
#define SEE_CARDS_HPP

#include <iostream>
#include "../command.hpp"
#include "../../Game/unoGame.hpp"

using namespace std;

class SeeCards: public Command<UnoGame> {
    public:
        /* Ctor */
        SeeCards();

        /* Method */
        void executeAction(UnoGame&); // See the current player's cards
};

#endif