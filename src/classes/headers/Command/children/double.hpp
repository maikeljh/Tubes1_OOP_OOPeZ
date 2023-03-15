#ifndef DOUBLE_HPP
#define DOUBLE_HPP

#include <iostream>
#include "../command.hpp"
#include "next.hpp"
#include "../../Game/candyGame.hpp"

using namespace std;

class Double: public Command<CandyGame> {
    public:
        /* Ctor */
        Double();

        /* Method */
        void executeAction(CandyGame&); // Execute double point
};

#endif