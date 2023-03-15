#include <iostream>
#include "../command.hpp"
#include "../../Game/candyGame.hpp"
using namespace std;

#ifndef _HELP_
#define _HELP_

class Help: public Command<CandyGame> {
    public:
        /* Ctor */
        Help();

        /* Method */
        void executeAction(CandyGame& Game); // Print all available commands to use
};


#endif