#ifndef VALUE_HPP
#define VALUE_HPP

#include <iostream>
using namespace std;

/* Abstract Base Class */
class Value {
    public:
        /* Pure Virtual Method */
        virtual double value() = 0;
};

#endif
