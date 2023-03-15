#ifndef SAY_UNO_HPP
#define SAY_UNO_HPP

#include <iostream>
#include "../command.hpp"
#include "../../Game/unoGame.hpp"

using namespace std;

class SayUno : public Command<UnoGame> {
    public:
        /* Ctor */
        SayUno();

        /* Method */
        void executeAction(UnoGame&); // Say UNO
};

#endif