#ifndef SAY_UNO_HPP
#define SAY_UNO_HPP

#include <iostream>
#include "../command.hpp"
#include "../../Game/game.hpp"
#include "../../../headers/Inventory/children/Player/unoPlayer.hpp"

using namespace std;

class SayUno : public Command {
    public:
        SayUno();
        void executeActionUNO(UnoGame&);
};

#endif