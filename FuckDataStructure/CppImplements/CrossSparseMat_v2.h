#ifndef CROSS_SPARSE_MAT_H
#define CROSS_SPARSE_MAT_H

#include <iostream>
using namespace std;

template<class T>
struct SMatNode {
    int row, col;
    T value;
    SMatNode<T>* row_next;
    SMatNode<T>* col_next;
    SMatNode() {
        row = 0;
        col = 0;
        row_next = NULL;
        col_next = NULL;
    }
};


template<class T>
class CrossSparseMat {
public:
    SMatNode<T>* row_heads;
    SMatNode<T>* col_heads;
    int rows;
    int cols;
    int value_nums;
public:
    CrossSparseMat(int row, int col);

    void input(int value_nums);
    void output();

    void Insert(int row, int col, T value);
    void Insert(SMatNode<T>*);

    void Add(CrossSparseMat<T>&);

};


template<class T>
CrossSparseMat<T>::CrossSparseMat(int row, int col) {
    this->rows = row;
    this->cols = col;
    value_nums = 0;
    row_heads = new SMatNode<T>[rows];
    col_heads = new SMatNode<T>[cols];

}

template<class T>
void CrossSparseMat<T>::input(int value_nums) {
    T t_r, t_c, t_v;
    for (int i = 0; i<value_nums; i++) {
        cin>>t_r>>t_c>>t_v;
        this->Insert(t_r, t_c, t_v);
    }
}

template<class T>
void CrossSparseMat<T>::output() {
    for (int i=0; i<rows; i++) {
        SMatNode<T>* t_ptr = &row_heads[i];
        
        t_ptr = t_ptr->row_next;
        while (t_ptr) {
            printf("%d %d ", t_ptr->row, t_ptr->col);
            cout<<t_ptr->value<<endl;
            t_ptr = t_ptr->row_next;
        }
    }
}

template<class T>
void CrossSparseMat<T>::Insert(int row, int col, T value) {
    // find in row where to insert
    SMatNode<T>* t_ptr = &row_heads[row];
    while (t_ptr && t_ptr->col < col) {
        if (t_ptr->row_next) { 
            if (t_ptr->row_next->col > col) {
                break;
            }
            else if (t_ptr->row_next->col == col) {
                t_ptr->row_next->value += value;
                return ;
            }
            else {
                t_ptr = t_ptr->row_next;
            }
        }
        else {
            break;
        }
    }
    // cout<<"i col"<<t_ptr->col<<endl;
    this->value_nums += 1;
    SMatNode<T>* insert_node = new SMatNode<T>;
    insert_node->col = col;
    insert_node->row = row;
    insert_node->value = value;

    // insert in row link-list
    insert_node->row_next = t_ptr->row_next;
    t_ptr->row_next = insert_node;

    // find in col where to insert
    t_ptr = &col_heads[col];
    while (t_ptr && t_ptr->row < row) {
        if (t_ptr->col_next) { 
            if (t_ptr->col_next->row > row) {
                break;
            }
            else {
                t_ptr = t_ptr->col_next;
            }
        }
        else {
            break;
        }
    }
    // cout<<"i row"<<t_ptr->row<<endl;
    // insert in col link-list
    insert_node->col_next = t_ptr->col_next;
    t_ptr->col_next = insert_node;
    // cout<<'y';
    // this->output();
    // cout<<'e'<<endl;
}

template<class T>
void CrossSparseMat<T>::Insert(SMatNode<T>* t) {
    this->Insert(t->row, t->col, t->value);
}


template<class T>
void CrossSparseMat<T>::Add(CrossSparseMat<T>& csm) {
    for (int i=0; i<csm.rows; i++) {
        SMatNode<T>* t_ptr = &csm.row_heads[i];
        
        t_ptr = t_ptr->row_next;
        while (t_ptr) {
            // printf("%d %d ", t_ptr->row, t_ptr->col);
            cout<<t_ptr->row<<' '<<t_ptr->col<<' '<<t_ptr->value<<endl;
            this->Insert(t_ptr);
            t_ptr = t_ptr->row_next;
        }
    }
}

#endif
