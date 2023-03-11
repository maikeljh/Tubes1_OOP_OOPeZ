#ifndef HALF_HPP
#define HALF_HPP

#include <iostream>
#include "../command.hpp"
#include "next.hpp"
#include "../../Game/candyGame.hpp"

using namespace std;

class Half: public Command {
    public:
        Half(); // ID = 5
        void executeAction(CandyGame&);
};

#endif