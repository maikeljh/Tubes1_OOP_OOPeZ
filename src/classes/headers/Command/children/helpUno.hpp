#include <iostream>
#include "../command.hpp"
#include "../../Game/unoGame.hpp"

#ifndef _HELP_UNO_
#define _HELP_UNO_
using namespace std;

class HelpUno : public Command<UnoGame> {
    public:
        /* Ctor */
        HelpUno();

        /* Method */
        void executeAction(UnoGame&); // Print all available commands to use in UnoGame
};


#endif