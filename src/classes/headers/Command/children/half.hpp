#ifndef HALF_HPP
#define HALF_HPP

#include <iostream>
#include "../command.hpp"
#include "next.hpp"
#include "../../Game/candyGame.hpp"

using namespace std;

class Half: public Command<CandyGame> {
    public:
        /* Ctor */
        Half();

        /* Method */
        void executeAction(CandyGame&); // Execute half point
};

#endif