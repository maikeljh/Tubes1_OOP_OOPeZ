#ifndef VALUE_HPP
#define VALUE_HPP

#include <iostream>
using namespace std;

class Value {
    public:
        Value();
        virtual double value() = 0;
};

#endif
