#ifndef CROSS_SPARSE_MAT_H
#define CROSS_SPARSE_MAT_H

#include <iostream>
using namespace std;

template<class T>
struct LinkNode {
    int row, col;
    T value;
    LinkNode<T>* row_next;
    LinkNode<T>* col_next;
    LinkNode() {
        row_next = NULL;
        col_next = NULL;
    }
};


template<class T>
class CrossSparseMat {
protected:
    int row;
    int col;
    LinkNode<T>* head;
    int value_nums;
public:
    CrossSparseMat();
    ~CrossSparseMat();

    void input(int value_nums);
    void output();
    
    void Insert(LinkNode<T>* node);
};

template<class T>
CrossSparseMat<T>::CrossSparseMat() {
    head = new LinkNode();
    value_nums = 0;
}

template<class T>


#endif