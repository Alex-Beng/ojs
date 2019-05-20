#include <iostream>
using namespace std;

template<class T>
struct LinkNode {
    T data;
    LinkNode<T>* former;
    LinkNode<T>* next;
    LinkNode() {
        former = NULL;
        next = NULL;
    }
};

template<class T>
class DoublyLinkList {
protected:
    LinkNode<T>* head;
    LinkNode<T>* tail;
    int Len;
public:
    DoublyLinkList();
    ~DoublyLinkList();

    bool PushBack(T x);
    LinkNode<T>* getHead() const;
    LinkNode<T>* getTail() const;
    void output() const;
    void Add(DoublyLinkList<T>& An);
    void Multiple(T n);
    void Divide(T n);
    bool EqualZero() const;
};

int main(int argc, char const *argv[]) {
    int nums;
    cin>>nums;

    DoublyLinkList<long long> sum;
    DoublyLinkList<long long> An;
    sum.PushBack(2);
    An.PushBack(2);

    for (int i=0; i<nums+7; i++) {
        sum.PushBack(0);
        An.PushBack(0);
    }

    long long n = 1;

    LinkNode<long long>* i;
    LinkNode<long long>* j;
    while (1) {
        An.Multiple(n);
        An.Divide(2*n+1);

        if (An.EqualZero()) {
            break;
        }

        sum.Add(An);
        n += 1;
    }
    i = sum.getHead();
    i = i->next;
    i = i->next;
    cout<<"3.";
    for (int iter=0; iter<nums; iter++) {
        cout<<i->data;
        i = i->next;
    }
    cout<<endl;
    return 0;
}


template<class T>
DoublyLinkList<T>::DoublyLinkList() {
    head = new LinkNode<T>;
    tail = head;
}

template<class T>
DoublyLinkList<T>::~DoublyLinkList() {
    LinkNode<T>* t_ptr;
    do {
        t_ptr = head;
        head = head->next;
        delete t_ptr;
    } while (head != NULL);
}

template<class T>
bool DoublyLinkList<T>::PushBack(T x) {
    LinkNode<T>* t_ptr = new LinkNode<T>;
    if (t_ptr == NULL) {
        return false;
    }
    t_ptr->data = x;

    tail->next = t_ptr;
    t_ptr->former = tail;
    
    tail = t_ptr;
}

template<class T>
LinkNode<T>* DoublyLinkList<T>::getHead() const{
    return head;
}

template<class T>
LinkNode<T>* DoublyLinkList<T>::getTail() const{
    return tail;
}

template<class T>
void DoublyLinkList<T>::output() const{
    LinkNode<T>* t_ptr = head;
    while (t_ptr->next != NULL) {
        t_ptr = t_ptr->next;
        cout<<t_ptr->data;
    }
    cout<<' ';
}

template<class T>
void DoublyLinkList<T>::Add(DoublyLinkList<T>& An) {
    T t;
    T carry_in = 0;
    LinkNode<T>* i;
    LinkNode<T>* j;
    carry_in = 0;
    for (i = An.getTail(), j = tail; 
         i != An.getHead() && j != head; 
         i = i->former, j = j->former) {
        t = i->data + j->data + carry_in;
        j->data = t%10;
        carry_in = t/10;
    }
}

template<class T>
void DoublyLinkList<T>::Multiple(T n) {
    T carry_in = 0;
    LinkNode<T>* i;
    for (i = tail; i != head; i = i->former) {
        i->data = i->data*n + carry_in;
        carry_in = i->data/10;
        i->data %= 10;
    }
}

template<class T>
void DoublyLinkList<T>::Divide(T n) {
    T t;
    T carry_in = 0;
    LinkNode<T>* i;
    for (i = head->next; i != NULL; i = i->next) {
        t = i->data + carry_in*10;
        i->data = t/n;
        carry_in = t%n;
    }
}

template<class T>
bool DoublyLinkList<T>::EqualZero()const {
    LinkNode<T>* i;
    for (i = head->next; i != NULL; i = i->next) {
        if (i->data != 0) {
            return false;
        }
    }
    return true;
}
