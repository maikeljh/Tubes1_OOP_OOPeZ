#ifndef QUARTER_HPP
#define QUARTER_HPP

#include <iostream>
#include "../command.hpp"
#include "next.hpp"
#include "../../Game/game.hpp"

using namespace std;

class Quarter: public Command {
    public:
        Quarter(); // ID = 6
        void executeAction(Game& Game);
};

#endif