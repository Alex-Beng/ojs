#include <iostream>
using namespace std;

template<class T>
struct SMatNode {
    bool is_head;
    int row, col;
    T value;
    SMatNode<T>* row_next;
    SMatNode<T>* col_next;
    SMatNode() {
        is_head = false;
        row_next = NULL;
        col_next = NULL;
    }
};


template<class T>
class CrossSparseMat {
public:
    SMatNode<T>* head;
public:
    CrossSparseMat(int row, int col, int value_num);

    void input(int value_nums);
    void output();

    void Insert(int row, int col, T value);
    void Insert(SMatNode<T>*);

    void Add(CrossSparseMat<T>&);

    SMatNode<T>* GetHead();
};

int main(int argc, char const *argv[]) {
    int m, n;
    int t1, t2;
    cin>>m>>n>>t1>>t2;
    CrossSparseMat<int> m1(m, n, t1);
    CrossSparseMat<int> m2(m, n, t2);

    m1.input(t1);
    m2.input(t2);

    // cout<<endl;
    // m1.output();
    // cout<<endl;
    // m2.output();
    // cout<<endl;

    m1.Add(m2);
    m1.output();

    return 0;
}



template<class T>
CrossSparseMat<T>::CrossSparseMat(int row, int col, int value_num) {
    head = new SMatNode<T>();
    head->is_head = true;
    head->row = row;
    head->col = col;
    head->value = value_num;

    // !!!!!!!!!!!!!!!
    head->row_next = head;
    head->col_next = head;

    SMatNode<T>* t_ptr = head;
    SMatNode<T>* new_node;
    for (int i=0; i<row; i++) {
        new_node = new SMatNode<T>();
        new_node->is_head = true;
        new_node->col_next = new_node;

        new_node->row_next = t_ptr->row_next;
        t_ptr->row_next = new_node;

        t_ptr = t_ptr->row_next;
    }

    t_ptr = head;
    for (int i=0; i<col; i++) {
        new_node = new SMatNode<T>();
        new_node->is_head = true;
        new_node->row_next = new_node;

        new_node->col_next = t_ptr->col_next;
        t_ptr->col_next = new_node;

        t_ptr = t_ptr->col_next;
    }

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
    int counter = 0;
    SMatNode<T>* t_ptr = head->row_next;
    while (t_ptr != head) {
        SMatNode<T>* t_row_head = t_ptr;
        t_ptr = t_ptr->col_next;
        while (t_ptr != t_row_head) {
            cout<<t_ptr->row<<' '<<t_ptr->col<<' '<<t_ptr->value;
            counter++;
            if (counter != head->value-1) {
                cout<<endl;
            }
            t_ptr = t_ptr->col_next;
        }

        t_ptr = t_ptr->row_next;
    }
}

template<class T>
void CrossSparseMat<T>::Insert(int row, int col, T value) {
    SMatNode<T>* t_row_head;
    SMatNode<T>* t_col_head;

    SMatNode<T>* t_ptr = head;

    // find the row firstly
    for (int i=0; i<row; i++) {
        // cout<<0<<endl;
        t_ptr = t_ptr->row_next;
    }
    t_row_head = t_ptr;

    // find the col secondly
    while (t_ptr->col_next != t_row_head && t_ptr->col_next->col < col) {
        // cout<<1<<endl;
        t_ptr = t_ptr->col_next;
    }
    if (t_ptr->col_next != t_row_head && t_ptr->col_next->col == col) {
        // cout<<2<<endl;
        t_ptr->col_next->value += value;
        return ;
    }


    // else mean that the row-col value doesn't exist
    // need to find the node before new-node's row
    SMatNode<T>* tt_ptr = head;
    for (int i=0; i<col; i++) {
        // cout<<3<<endl;
        tt_ptr = tt_ptr->col_next;
    }
    t_col_head = tt_ptr;

    while (tt_ptr->row_next != t_col_head && tt_ptr->row_next->row < row) {
        // cout<<4<<endl;
        tt_ptr = tt_ptr->row_next;
    }

    // then the t_ptr is the pointer, which is before the position that need inserted.
    SMatNode<T>* new_node = new SMatNode<T>();
    new_node->row = row;
    new_node->col = col;
    new_node->value = value;

    new_node->row_next = tt_ptr->row_next;
    tt_ptr->row_next = new_node;

    new_node->col_next = t_ptr->col_next;
    t_ptr->col_next = new_node;

    return ;
}

template<class T>
void CrossSparseMat<T>::Insert(SMatNode<T>* t) {
    this->Insert(t->row, t->col, t->value);
}

template<class T>
SMatNode<T>* CrossSparseMat<T>::GetHead() {
    return head;
}

template<class T>
void CrossSparseMat<T>::Add(CrossSparseMat<T>& csm) {
    SMatNode<T>* t_head = csm.GetHead();
    SMatNode<T>* t_ptr = t_head->row_next;

    head->value += t_head->value;

    while (t_ptr != t_head) {
        SMatNode<T>* t_row_head = t_ptr;
        t_ptr = t_ptr->col_next;
        while (t_ptr != t_row_head) {
            // cout<<t_ptr->row<<' '<<t_ptr->col<<' '<<t_ptr->value<<endl;           
            this->Insert(t_ptr);
            t_ptr = t_ptr->col_next;
        }

        t_ptr = t_ptr->row_next;
    }
}