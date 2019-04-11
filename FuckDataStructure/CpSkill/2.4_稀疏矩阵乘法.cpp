/*
3 3
1 1 1
2 2 2
2 3 4
3 1 -4
0 0 0
3 3
1 3 -2
2 3 -5
3 1 8
3 2 -6
0 0 0
*/

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
protected:
    SMatNode<T>* head;
public:
    CrossSparseMat(int row, int col);

    void input();
    void output();

    void Insert(int row, int col, T value);
    void Insert(SMatNode<T>*);

    void Add(CrossSparseMat<T>&);
    SMatNode<T>* GetHead();
};

template<class T>
void Multiple(CrossSparseMat<T>& a, CrossSparseMat<T>& b, CrossSparseMat<T>& product) {
    // SMatNode<T>* a_head = a.GetHead();
    // SMatNode<T>* b_head = b.GetHead();

    // SMatNode<T>* a_row_iter = a_head->row_next;
    // SMatNode<T>* b_col_iter = b_head->col_next;
    // while (1) {
    //     if (a_row_iter == a_head) {
    //         break;
    //     }
    //     while (1) {
    //         if (b_col_iter == b_head) {
                
    //         }
    //     }
    // }

    SMatNode<T>* a_head = a.GetHead();
    SMatNode<T>* b_head = b.GetHead();
    int product_row = product.GetHead()->row;
    int product_col = product.GetHead()->col;


    int multi_times = a_head->col;
    T sum;

    SMatNode<T>* row_ptr;
    SMatNode<T>* col_ptr;
    for (int i=0; i<product_row; i++) {
        a_head = a_head->row_next;
        // cout<<"a head"<<a_head->col_next->value<<endl;
        for (int j=0; j<product_col; j++) {
            b_head = b_head->col_next;
            // cout<<"b head "<<b_head->row_next->value<<endl
            //     <<"at col "<<j+1<<endl<<endl;
            // then multiple
            sum = 0;
            col_ptr = a_head->col_next;
            row_ptr = b_head->row_next;
            while (1) {
                if (col_ptr == a_head || row_ptr == b_head) {
                    break;
                }
                // cout<<"value"<<row_ptr->value<<endl;
                // cout<<col_ptr->col<<' '<<row_ptr->row<<endl;
                if (col_ptr->col > row_ptr->row) {
                    // cout<<col_ptr->col<<' '<<row_ptr->row<<'>'<<endl;
                    row_ptr = row_ptr->row_next;
                }
                else if (col_ptr->col < row_ptr->row) {
                    // cout<<col_ptr->col<<' '<<row_ptr->row<<'<'<<endl;
                    col_ptr = col_ptr->col_next;
                }
                else {
                    // cout<<col_ptr->col<<' '<<row_ptr->row<<'='<<endl;
                    sum += col_ptr->value * row_ptr->value;
                    row_ptr = row_ptr->row_next;
                    col_ptr = col_ptr->col_next;
                }
            }
            if (sum != 0) {
                product.Insert(i+1, j+1, sum);
            }
        }
        b_head = b_head->col_next;
    }
}


int main(int argc, char const *argv[]) {
    int row1, col1;
    int row2, col2;

    cin>>row1>>col1;
    CrossSparseMat<int> m1(row1, col1);
    m1.input();

    cin>>row2>>col2;
    CrossSparseMat<int> m2(row2, col2);
    m2.input();

    CrossSparseMat<int> product(row1, col2);

    Multiple<int>(m1, m2, product);
    product.output();
    return 0;
}



template<class T>
CrossSparseMat<T>::CrossSparseMat(int row, int col) {
    head = new SMatNode<T>();
    head->is_head = true;
    head->row = row;
    head->col = col;
    head->value = 0;

    // !!!!!!!!!!!!!!!
    head->row_next = head;
    head->col_next = head;

    SMatNode<T>* t_ptr = head;
    SMatNode<T>* new_node;
    for (int i=0; i<row; i++) {
        new_node = new SMatNode<T>();
        new_node->is_head = true;
        new_node->col_next = new_node;

        new_node->row = i+1;
        new_node->col = 0;

        new_node->row_next = t_ptr->row_next;
        t_ptr->row_next = new_node;

        t_ptr = t_ptr->row_next;
    }

    t_ptr = head;
    for (int i=0; i<col; i++) {
        new_node = new SMatNode<T>();
        new_node->is_head = true;
        new_node->row_next = new_node;

        new_node->col = i+1;
        new_node->row = 0;

        new_node->col_next = t_ptr->col_next;
        t_ptr->col_next = new_node;

        t_ptr = t_ptr->col_next;
    }

}

template<class T>
void CrossSparseMat<T>::input() {
    T t_r, t_c, t_v;

    while (1) {
        cin>>t_r>>t_c>>t_v;
        if (t_r==0 && t_c==0 && t_v==0) {
            return;
        }
        else {
            this->Insert(t_r, t_c, t_v);
        }
    }
}

template<class T>
void CrossSparseMat<T>::output() {

    SMatNode<T>* t_ptr = head->row_next;
    while (t_ptr != head) {
        SMatNode<T>* t_row_head = t_ptr;
        t_ptr = t_ptr->col_next;
        while (t_ptr != t_row_head) {
            cout<<t_ptr->row<<' '<<t_ptr->col<<' '<<t_ptr->value<<endl;
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
    head->value += 1;
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