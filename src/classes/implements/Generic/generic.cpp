#include <iostream>
#include <vector>
using namespace std;

template <class T>
T maxValue(vector<T>& x){
    T m = x[0];
    for (T i : x){
        if (i > m){
            m = i;
        }
    }
    return m;
}

template <class T>
int findIndexMaxValue(vector<T>& x){
    T maximum = x[0];
    int idx = 0;
    for(int i = 1; i < x.size(); i++){
        if(x[i] > maximum){
            maximum = x[i];
            idx = i;
        }
    }
    
    return idx;
}