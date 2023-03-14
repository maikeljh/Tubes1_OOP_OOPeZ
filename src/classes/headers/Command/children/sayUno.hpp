#ifndef SAY_UNO_HPP
#define SAY_UNO_HPP

#include <iostream>
#include "../command.hpp"
#include "../../Game/unoGame.hpp"

using namespace std;

class SayUno : public Command<UnoGame> {
    public:
        SayUno();
        void executeAction(UnoGame&);
};

#endif