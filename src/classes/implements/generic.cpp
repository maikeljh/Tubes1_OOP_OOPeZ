#include <iostream>
#include <vector>
using namespace std;

template <class T>
T maxValue(const vector<T>& x){
    T m = x[0];
    for (T i : x){
        if (i > m){ // ini i > m atau i.value() > m.value()
            m = i;
        }
    }
    return m;
}