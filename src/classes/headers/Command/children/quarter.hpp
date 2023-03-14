#ifndef QUARTER_HPP
#define QUARTER_HPP

#include <iostream>
#include "../command.hpp"
#include "next.hpp"
#include "../../Game/game.hpp"

using namespace std;

class Quarter: public Command<CandyGame> {
    public:
        Quarter();
        void executeAction(CandyGame& Game);
};

#endif