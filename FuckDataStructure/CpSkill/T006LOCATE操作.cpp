#include <iostream>
using namespace std;

template<class T>
struct LinkNode {
    T data;
    int freq;
    LinkNode<T>* former;
    LinkNode<T>* next;
    LinkNode() {
        former = NULL;
        next = NULL;
        freq = 0;
    }
};

template<class T>
class DoublyLinkList {
protected:
    LinkNode<T>* head;
    LinkNode<T>* tail;
    int len;
public:
    DoublyLinkList();
    ~DoublyLinkList();

    void Locate(T x);
    void input(int n);
    void output();
};

int main(int argc, char const *argv[]) {
    int m, n;
    char t;
    cin>>m>>n;
    DoublyLinkList<char> dll;
    dll.input(m);
    // dll.output();
    for (int i=0; i<n; i++) {
        cin>>t;
        dll.Locate(t);
    }
    dll.output();
    return 0;
}

template<class T>
DoublyLinkList<T>::DoublyLinkList() {
    head = new LinkNode<T>;
    tail = head;
    len = 0;
}

template<class T>
DoublyLinkList<T>::~DoublyLinkList() {
    LinkNode<T>* t_ptr;
    while (head != NULL) {
        t_ptr = head;
        head = head->next;
        delete t_ptr;
    }
}

template<class T>
void DoublyLinkList<T>::input(int n) {
    T t;
    LinkNode<T>* new_node;
    for (int i=0; i<n; i++) {
        cin>>t;
        new_node = new LinkNode<T>;
        new_node->data = t;
        tail->next = new_node;
        new_node->former = tail;
        tail = tail->next;
    }   
}

template<class T>
void DoublyLinkList<T>::output() {
    LinkNode<T>* t_ptr = head->next;
    while (t_ptr != NULL) {
        cout<<t_ptr->data;
        if (t_ptr->next != NULL) {
            cout<<' ';
        }
        t_ptr = t_ptr->next;
    }
}

template<class T>
void DoublyLinkList<T>::Locate(T x) {
    LinkNode<T>* t_ptr = head->next;
    while (t_ptr != NULL) {
        if (t_ptr->data == x) {
            // cout<<"yayaya"<<endl;
            break;
        }
        t_ptr = t_ptr->next;
    }
    t_ptr->freq += 1;

    // do forward
    LinkNode<T>* t_former = t_ptr->former;
    // cout<<"yayaya"<<endl;
    while (t_former != head 
            && t_former->freq < t_ptr->freq) {
        // cout<<t_former->data<<'*'<<endl;
        // cout<<"-----"<<endl;
        // this->output();
        t_former->former->next = t_ptr;
        t_ptr->former = t_former->former;

        t_former->next = t_ptr->next;
        if (t_ptr->next != NULL) {
            t_ptr->next->former = t_former;
        }

        t_ptr->next = t_former;
        t_former->former = t_ptr;

        t_former = t_ptr->former;
    }
}