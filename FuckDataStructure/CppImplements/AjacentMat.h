#ifndef AJACENT_MAT_H
#define AJACENT_MAT_Hs

#include <iostream>
using namespace std;

template<class T>
class AjacentMat {
protected:
    T* data;
    int n;
public:
    AjacentMat(){}
    ~AjacentMat(){delete [] data;}
    void input();
    T getValue(int row, int col);
    void setValue(int row, int col, T value);
    T getNodeNum(){return n;}
};

template<class T>
void AjacentMat<T>::input() {
    cin>>n;
    if (n <= 0) {
        return;
    }
    data = new T[n*n];
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin>>data[i*n+j];
        }
    }
}

template<class T>
T AjacentMat<T>::getValue(int row, int col) {
    return data[row*n+col];
}

template<class T>
void AjacentMat<T>::setValue(int row, int col, T value) {
    data[row*n+col] = value;
}

#endif