#ifndef PLUS2_HPP
#define PLUS2_HPP

#include "../command.hpp"
#include "../../Game/unoGame.hpp"
#include "skip.hpp"
using namespace std;

class Plus2 : public Command<UnoGame>{
    public:
        Plus2();
        void executeAction(UnoGame&);
};

#endif