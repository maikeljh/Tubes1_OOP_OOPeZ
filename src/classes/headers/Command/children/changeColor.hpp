#ifndef CHANGE_COLOR_HPP
#define CHANGE_COLOR_HPP

#include "../command.hpp"
#include "../../Game/unoGame.hpp"
#include "../../Exception/exception.h"

class ChangeColor: public Command<UnoGame> {
    public:
        ChangeColor();
        void executeAction(UnoGame&);
};

#endif