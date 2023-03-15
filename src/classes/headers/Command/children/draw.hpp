#ifndef DRAW_HPP
#define DRAW_HPP

#include <iostream>
#include "../command.hpp"
#include "../../Game/unoGame.hpp"

using namespace std;

class Draw: public Command<UnoGame> {
    public:
        /* Ctor */
        Draw();

        /* Method */
        void executeAction(UnoGame&); // Execute draw card from UNO deck
};

#endif 