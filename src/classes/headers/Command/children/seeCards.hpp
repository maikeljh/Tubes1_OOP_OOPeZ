#ifndef SEE_CARDS_HPP
#define SEE_CARDS_HPP

#include <iostream>
#include "../command.hpp"
#include "../../Game/unoGame.hpp"

using namespace std;

class SeeCards: public Command<UnoGame> {
    public:
        SeeCards();
        void executeAction(UnoGame&);
};

#endif