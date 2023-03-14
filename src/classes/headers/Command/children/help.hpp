#include <iostream>
#include "../command.hpp"
#include "../../Game/candyGame.hpp"
using namespace std;

#ifndef _HELP_
#define _HELP_

class Help: public Command<CandyGame> {
    public:
        Help(); 
        void executeAction(CandyGame& Game);
};


#endif