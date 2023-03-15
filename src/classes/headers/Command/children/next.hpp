#ifndef NEXT_HPP
#define NEXT_HPP

#include <iostream>
#include "../command.hpp"
#include "../../Game/candyGame.hpp"

using namespace std;

class Next: public Command<CandyGame> {
    public:
        /* Ctor */
        Next();

        /* Method */
        void executeAction(CandyGame& Game); // Pass the turn to next player
};

#endif