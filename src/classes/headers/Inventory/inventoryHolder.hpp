#ifndef INVENTORY_HOLDER_HPP
#define INVENTORY_HOLDER_HPP
#include "../Value/Card/abilityCard.hpp"
#include "../Value/Card/card.hpp"
#include <iostream>
using namespace std;

template <class T>
class InventoryHolder {
    /* 
    protected:
        vector<Card> tampungan_kartu buat deck+player. Tapi deck ability blm
        Ability card:
        vecotr<T> tampungan_kartu (+template <class T>)
    */ 
    public:
        InventoryHolder();
        virtual void printCard() = 0;
        virtual void push(const T&) = 0;
        virtual T pop() = 0;
};
template class InventoryHolder<Card>;
template class InventoryHolder<AbilityCard>;
#endif