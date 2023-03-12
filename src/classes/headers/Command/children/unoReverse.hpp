#ifndef UNO_REVERSE_HPP
#define UNO_REVERSE_HPP

#include "../command.hpp"
#include "../../Game/game.hpp"
#include <algorithm>
using namespace std;

class UnoReverse: public Command{
    UnoReverse();
    void executeActionUNO(UnoGame&);
};

#endif