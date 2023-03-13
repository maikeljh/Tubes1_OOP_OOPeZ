#ifndef CHANGE_COLOR_HPP
#define CHANGE_COLOR_HPP

#include "../command.hpp"
#include "../../Game/game.hpp"
#include "../../Exception/exception.h"

class ChangeColor: public Command{
public:
    ChangeColor();
    void executeActionUNO(UnoGame&);
};

#endif