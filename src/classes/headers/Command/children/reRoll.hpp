#ifndef RE_ROLL_HPP
#define RE_ROLL_HPP

#include <iostream>
#include "../command.hpp"
#include "next.hpp"
#include "../../Game/candyGame.hpp"

using namespace std;

class ReRoll: public Command<CandyGame> {
    public:
        ReRoll();
        void executeAction(CandyGame&);
};

#endif