#include <iostream>
using namespace std;

template<class T>
struct LinkNode {
    T data;
    LinkNode<T>* next;
    LinkNode() {
        next = NULL;
    }
};

template<class T>
class SingleList {
protected:
    LinkNode<T>* head;
    int len;
public:
    SingleList();

    void PushBack(T x);
    T getData(int idx) const;
    int getLen() const;
    void output() const;
    void input(int n);
    LinkNode<T>* getHeadPtr();
    void Merge(SingleList<T>& sl);
};

int main(int argc, char const *argv[]) {
    int m, n;
    SingleList<int> a;
    SingleList<int> b;
    cin>>m>>n;

    a.input(m);
    b.input(n);

    a.Merge(b);
    a.output();

    return 0;
}

template<class T>
SingleList<T>::SingleList() {
    head = new LinkNode<T>;
    len = 0;
}


template<class T>
void SingleList<T>::PushBack(T x) {
    LinkNode<T>* t_ptr = head;
    while (t_ptr->next != NULL) {
        t_ptr = t_ptr->next;
    }
    LinkNode<T>* new_node = new LinkNode<T>;
    new_node->data = x;
    t_ptr->next = new_node;
    len++;
}

template<class T>
T SingleList<T>::getData(int idx) const {
    LinkNode<T>* t_ptr = head;
    for (int i=0; i<=idx; i++) {
        t_ptr = t_ptr->next;
    }
    return t_ptr->data;
}

template<class T>
int SingleList<T>::getLen() const {
    return len;
}

template<class T>
void SingleList<T>::output() const {
    LinkNode<T>* t_ptr = this->head->next;
    for (int i=0; i<len; i++) {
        cout<<t_ptr->data<<' ';
        t_ptr = t_ptr->next;
    }
}

template<class T>
void SingleList<T>::input(int n) {
    int t;
    for (int i=0; i<n; i++) {
        cin>>t;
        this->PushBack(t);
    }
}


template<class T>
LinkNode<T>* SingleList<T>::getHeadPtr() {
    return head;
}

template<class T>
inline void insert_node(LinkNode<T>*& rec_ptr, LinkNode<T>*& in_ptr) {
    // cout<<in_ptr->data<<endl;
    LinkNode<T>* t_ptr = in_ptr;
    in_ptr = in_ptr->next;
    
    t_ptr->next = rec_ptr->next;
    rec_ptr->next = t_ptr;

}

template<class T>
void SingleList<T>::Merge(SingleList<T>& sl) {
    LinkNode<T>* head_1 = this->head->next;
    LinkNode<T>* head_2 = sl.getHeadPtr();
    head_2 = head_2->next;

    LinkNode<T>* t_end = this->head;
    t_end->next = NULL;

    while (head_1 && head_2) {
        if (head_1->data > head_2->data) { // 插入head2
            insert_node(t_end, head_2);

        }
        else { 
            insert_node(t_end, head_1);
        }
    }

    while (head_1 != NULL) {
        insert_node(t_end, head_1);
    }
    
    while (head_2 != NULL) {
        insert_node(t_end, head_2);
    }
    this->len += sl.getLen();
}

/*
input
5 5
1 3 7 12 16
2 6 7 13 20
*/