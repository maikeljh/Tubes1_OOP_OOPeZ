#ifndef REVERSE_HPP
#define REVERSE_HPP

#include <iostream>
#include "../command.hpp"
#include "../../Game/candyGame.hpp"
#include "next.hpp"

using namespace std;

class Reverse: public Command<CandyGame> {
    public:
        Reverse();
        void executeAction(CandyGame& Game);
};

#endif