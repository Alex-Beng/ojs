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
    LinkNode<T>* tail;
    int len;
public:
    SingleList();
    ~SingleList();

    void PushBack(T x);
    void PushBack(LinkNode<T>* x);
    T getData(int idx) const;
    int getLen() const;
    void output() const;
    void input(int n);
    LinkNode<T>* getHead() const;
};



int main(int argc, char const *argv[]) {
    SingleList<int> a;
    SingleList<int> b;
    SingleList<int> c;
    int m, n, p;
    cin>>m>>n>>p;
    a.input(m);
    b.input(n);
    c.input(p);

    // a.output();
    // b.output();
    // c.output();
    
    SingleList<int> bc_and;
    LinkNode<int>* h1 = b.getHead()->next;
    LinkNode<int>* h2 = c.getHead()->next;
    while (h1 != NULL && h2 != NULL) {
        if (h1->data < h2->data) {
            h1 = h1->next;
        }
        else if (h1->data > h2->data) {
            h2 = h2->next;
        }
        else {
            bc_and.PushBack(h1->data);
            h1 = h1->next;
            h2 = h2->next;
        }
    }
    // bc_and.output();
    h1 = a.getHead()->next;
    h2 = bc_and.getHead()->next;

    while (h1 != NULL && h2 != NULL) {
        if (h1->data < h2->data) {
            cout<<h1->data<<' ';
            h1 = h1->next;
        }
        else if (h1->data > h2->data) {
            h2 = h2->next;
        }
        else {
            h1 = h1->next;
        }
    }
    while (h1 != NULL) {
        cout<<h1->data<<' ';
        h1 = h1->next;
    }
    return 0;
}

template<class T>
LinkNode<T>* SingleList<T>::getHead() const {
    return head;
}

template<class T>
void SingleList<T>::input(int n) {
    int t;
    for (int i=0; i<n; i++) {
        cin>>t;
        // cout<<t<<'*';
        this->PushBack(t);
    }
}


template<class T>
SingleList<T>::SingleList() {
    head = new LinkNode<T>;
    tail = head;
    len = 0;
}

template<class T>
SingleList<T>::~SingleList() {
    LinkNode<T>* t_ptr;
    while (head->next != NULL) {
        t_ptr = head;
        head = head->next;
        delete t_ptr;
    }
}

template<class T>
void SingleList<T>::PushBack(T x) {
    tail->next = new LinkNode<T>;
    tail->next->data = x;
    tail = tail->next;
    len++;
}

template<class T>
void SingleList<T>::PushBack(LinkNode<T>* x) {

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
    LinkNode<T>* t_ptr = head->next;
    while (t_ptr != NULL) {
        cout<<t_ptr->data<<' ';
        // if (t_ptr->next != NULL) {
        //     cout<<' ';
        // }
        t_ptr = t_ptr->next;
    }
    cout<<endl;
}