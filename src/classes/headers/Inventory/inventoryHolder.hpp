#ifndef INVENTORY_HOLDER_HPP
#define INVENTORY_HOLDER_HPP
#include "../Value/Card/abilityCard.hpp"
#include "../Value/Card/children/unoCard.hpp"
#include "../Value/Card/card.hpp"
#include <iostream>
using namespace std;

/* Abstract Base Class */
template <class T>
class InventoryHolder {
    public:
        /* Pure Virtual Methods */
        virtual void printCard() = 0;
        virtual void push(const T&) = 0;
        virtual T pop() = 0;
};

template class InventoryHolder<Card>;
template class InventoryHolder<AbilityCard>;
template class InventoryHolder<UnoCard>;

#endif