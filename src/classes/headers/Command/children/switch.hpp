#ifndef SWITCH_HPP
#define SWITCH_HPP

#include <iostream>
#include "../command.hpp"
#include "../../Game/game.hpp"

using namespace std;

class Switch: public Command {
    public:
        Switch(); // ID = 9
        void executeAction(Game& Game);
};

#endif