#ifndef INVENTORY_HOLDER_HPP
#define INVENTORY_HOLDER_HPP

#include <iostream>
using namespace std;

template <class T>
class InventoryHolder {
    public:
        InventoryHolder();
        virtual T pop();
        virtual void push (const T&);
};
#endif