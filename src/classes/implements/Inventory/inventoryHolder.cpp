#include "../../headers/Inventory/inventoryHolder.hpp"
#include <iostream>

using namespace std;

template <class T>
InventoryHolder<T>::InventoryHolder(){}

template <class T>
void InventoryHolder<T>::printCard(){
}

template <class T>
void InventoryHolder<T>::push(const T&){}

template <class T>
T InventoryHolder<T>::pop(){}