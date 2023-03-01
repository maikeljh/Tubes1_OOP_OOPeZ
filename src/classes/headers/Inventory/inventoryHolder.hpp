#ifndef INVENTORY_HOLDER_HPP
#define INVENTORY_HOLDER_HPP

#include <iostream>
using namespace std;

//template <class T>
class InventoryHolder {
    /* 
    protected:
        vector<Card> tampungan_kartu buat deck+player. Tapi deck ability blm
        Ability card:
        vecotr<T> tampungan_kartu (+template <class T>)
    */ 
    public:
        InventoryHolder();
        virtual void printCard();
};
#endif