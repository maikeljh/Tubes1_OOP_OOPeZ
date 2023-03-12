#ifndef PLUS4_HPP
#define PLUS4_HPP

#include "../command.hpp"
#include "../../Game/game.hpp"
using namespace std;

class Plus4 : public Command{
    Plus4();
    void executeActionUNO(UnoGame&);
};

#endif