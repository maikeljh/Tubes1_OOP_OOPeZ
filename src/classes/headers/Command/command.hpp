#ifndef COMMAND_HPP
#define COMMAND_HPP

#include <iostream>
#include "../Game/candyGame.hpp"
#include "../Inventory/children/DeckCard/deckCard.hpp"
#include "../Exception/exception.h"

using namespace std;

template <class T>
class Command { 
    public:
        /* ctor */
        Command(){}

        /* Functions */        
        virtual void executeAction(T&) = 0;
};

#endif