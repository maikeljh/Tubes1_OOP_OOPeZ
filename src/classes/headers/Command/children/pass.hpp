#ifndef PASS_HPP
#define PASS_HPP

#include <iostream>
#include "../command.hpp"
#include "../../Game/unoGame.hpp"

using namespace std;
class Pass : public Command<UnoGame> {
    public:
        /* Ctor */
        Pass();

        /* Method */
        void executeAction(UnoGame&); // Pass the current player turn
};
#endif