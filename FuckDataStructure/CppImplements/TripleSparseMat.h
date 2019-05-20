#ifndef TRISPARSEMAT_H
#define TRISPARSEMAT_H

#include <bits/stdc++.h>
using namespace std;

template<class T>
struct Triple {
    int col;
    int row;
    T value;
    Triple() {
        col = -1;
        row = -1;
        value = -233;
    }
    Triple(int c, int r, T v) {
        col = c;
        row = r;
        value = v;
    }
};

template<class T>
bool for_sort(Triple<T>a, Triple<T>b) {
    if (a.row != b.row) {
        return a.row > b.row;
    }
    else {
        return a.col < b.col;
    }
}

template<class T>
class TripleSparseMat {
protected:
    Triple<T>* data;
    int max_size;
    int col;
    int row;
    int value_nums;
public:
    TripleSparseMat(int size=233);
    ~TripleSparseMat();

    void input();
    void output();
    void t();         // 转置
    void Insert(int row, int col, T value);
};

template<typename T>
TripleSparseMat<T>::TripleSparseMat(int size) {
    if (size > 0) {
        max_size = size;
        value_nums = -1;
        data = new Triple<T> [max_size];
    }
}

template<class T>
TripleSparseMat<T>::~TripleSparseMat() {
    delete[] data;
}

template<class T>
void TripleSparseMat<T>::input() {
    cin>>row>>col;

    int t_r, t_c, t_v;
    while (cin>>t_r>>t_c>>t_v && (t_r||t_c||t_c)) {
        data[++value_nums].row = t_r;
        data[value_nums].col = t_c;
        data[value_nums].value = t_v;
    }
}

template<class T>
void TripleSparseMat<T>::output() {
    for (int i=0; i<=value_nums; i++) {
        cout<<data[i].row<<' '
            <<data[i].col<<' '
            <<data[i].value<<endl;
    }
}

template<class T>
void TripleSparseMat<T>::t() {
    for (int i=0; i<=value_nums; i++) {
        data[i].col += data[i].row;
        data[i].row = data[i].col-data[i].row;
        data[i].col = data[i].col-data[i].row;
    }
    sort(data, data+value_nums, for_sort<T>);
}


template<class T>
void TripleSparseMat<T>::Insert(int row, int col, T value) {
    int left = 0;
    int right = value_nums;
    int middle; 
    while (left <= right) {
        middle = (left+right)/2;
        if (data[middle].row != row) {
            if (data[middle].row > row) {
                right = middle-1;
            }
            else {
                left = middle+1;
            }
        }
        else {
            if (data[middle].col != col) {
                if (data[middle].col > col) {
                    right = middle-1;
                }
                else {
                    left = middle+1;
                }
            }
            else {
                data[middle].value += value;
                return ;
            }
        }
    }
    for (int i=value_nums; i>=middle; i--) {
        data[i+1].row = data[i].row;
        data[i+1].col = data[i].col;
        data[i+1].value = data[i].value;
    }
    value_nums++;
    data[middle].row = row;
    data[middle].col = col;
    data[middle].value = value; 
    // cout<<data[middle].row<<' '<<data[middle].col<<endl;
}

#endif 