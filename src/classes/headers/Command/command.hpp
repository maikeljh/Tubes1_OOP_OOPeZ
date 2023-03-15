#ifndef COMMAND_HPP
#define COMMAND_HPP

#include <iostream>
#include "../Game/candyGame.hpp"
#include "../Inventory/children/DeckCard/deckCard.hpp"
#include "../Exception/exception.h"

using namespace std;

/* Abstract Base Class Command */
template <class T>
class Command { 
    public:
        /* Pure virtual method */        
        virtual void executeAction(T&) = 0; // Execute action/command/ability
};

#endif