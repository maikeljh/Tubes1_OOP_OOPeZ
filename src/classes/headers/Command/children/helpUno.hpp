#include <iostream>
#include "../command.hpp"
#include "../../Game/game.hpp"

#ifndef _HELP_UNO_
#define _HELP_UNO_
using namespace std;

class HelpUno : public Command {
    public:
        HelpUno();
        void executeActionUNO(UnoGame&);
};


#endif