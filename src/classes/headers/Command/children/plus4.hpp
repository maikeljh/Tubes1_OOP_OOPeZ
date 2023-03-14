#ifndef PLUS4_HPP
#define PLUS4_HPP

#include "../command.hpp"
#include "../../Game/game.hpp"
#include "skip.hpp"
using namespace std;

class Plus4 : public Command<UnoGame>{
    public:
        Plus4();
        void executeAction(UnoGame&);
};

#endif