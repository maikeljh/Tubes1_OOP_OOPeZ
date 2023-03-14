#include <iostream>
#include "../command.hpp"
#include "../../Game/unoGame.hpp"

#ifndef _HELP_UNO_
#define _HELP_UNO_
using namespace std;

class HelpUno : public Command<UnoGame> {
    public:
        HelpUno();
        void executeAction(UnoGame&);
};


#endif