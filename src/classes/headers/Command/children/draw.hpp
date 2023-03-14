#ifndef DRAW_HPP
#define DRAW_HPP

#include <iostream>
#include "../command.hpp"
#include "../../Game/unoGame.hpp"

using namespace std;

class Draw: public Command<UnoGame> {
    public:
        Draw();
        void executeAction(UnoGame&);
};

#endif 