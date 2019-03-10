#ifndef TRISPARSEMAT_H
#define TRISPARSEMAT_H

#include <bits/stdc++.h>
using namespace std;

template<class T>
class Triple {
    int col;
    int row;
    T value;
    Triple<T>& operator= (Triple<T>& x) {
        row = x.row;
        col = x.col;
        value = x.value;
    }
};

template<class T>
class TripleSparseMat {
protected:
    
};

#endif 