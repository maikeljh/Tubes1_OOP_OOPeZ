#ifndef DRAW_HPP
#define DRAW_HPP

#include <iostream>
#include "../command.hpp"
#include "../../Game/game.hpp"
#include "../../../headers/Inventory/children/Player/unoPlayer.hpp"

using namespace std;

class Draw: public Command {
    public:
        Draw();
        void executeActionUNO(UnoGame&);
};

#endif 