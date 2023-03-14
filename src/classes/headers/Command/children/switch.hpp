#ifndef SWITCH_HPP
#define SWITCH_HPP

#include <iostream>
#include "../command.hpp"
#include "../../Game/game.hpp"
#include "next.hpp"

using namespace std;

class Switch: public Command<CandyGame> {
    public:
        Switch();
        void executeAction(CandyGame& Game);
};

#endif