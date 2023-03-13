#ifndef PASS_HPP
#define PASS_HPP

#include <iostream>
#include "../command.hpp"
#include "../../Game/game.hpp"

using namespace std;
class Pass : public Command {
    public:
        Pass();
        void executeActionUNO(UnoGame&);
};
#endif