#ifndef DOUBLE_HPP
#define DOUBLE_HPP

#include <iostream>
#include "../command.hpp"
#include "next.hpp"
#include "../../Game/candyGame.hpp"

using namespace std;

class Double: public Command<CandyGame> {
    public:
        Double();
        void executeAction(CandyGame&);
};

#endif