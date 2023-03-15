#ifndef UNO_REVERSE_HPP
#define UNO_REVERSE_HPP

#include "../command.hpp"
#include "../../Game/unoGame.hpp"
#include <algorithm>
using namespace std;

class UnoReverse: public Command<UnoGame>{
    public:
        UnoReverse();
        void executeAction(UnoGame&);
};

#endif