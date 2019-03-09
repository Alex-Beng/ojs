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
    LinkNode<T>* first;
    LinkNode<T>* tail;
    int Len;
public:
    DoublyLinkList();
    ~DoublyLinkList();

    bool PushBack(T x);
    LinkNode<T>* getHead() const;
    LinkNode<T>* getEnd() const;
    void output() const;
};

template<class T>
DoublyLinkList<T>::DoublyLinkList() {
    first = new LinkNode<T>;
    tail = first;
}

template<class T>
DoublyLinkList<T>::~DoublyLinkList() {
    LinkNode<T>* t_ptr;
    do {
        t_ptr = first;
        first = first->next;
        delete t_ptr;
    } while (first != NULL);
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
    return first;
}

template<class T>
LinkNode<T>* DoublyLinkList<T>::getEnd() const{
    return tail;
}

template<class T>
void DoublyLinkList<T>::output() const{
    LinkNode<T>* t_ptr = first;
    while (t_ptr->next != NULL) {
        t_ptr = t_ptr->next;
        cout<<t_ptr->data;
    }
    cout<<' ';
}

int main(int argc, char const *argv[]) {
    int nums;
    cin>>nums;

    DoublyLinkList<short> sum;
    DoublyLinkList<short> An;
    sum.PushBack(2);
    An.PushBack(2);

    for (int i=0; i<600; i++) {
        sum.PushBack(0);
        An.PushBack(0);
    }

    int n = 1;
    short ttt;
    short carry_in;
    bool break_flag;

    LinkNode<short>* i;
    LinkNode<short>* j;
    while (1) {

        // 然后乘 n
        carry_in = 0;
        for (i = An.getEnd(); i != An.getHead(); i = i->former) {
            ttt = i->data*n + carry_in;
            i->data = ttt%10;
            carry_in = ttt/10;
        }
        
        // 先除于 2*n+1
        carry_in = 0;
        i = An.getHead();
        i = i->next;
        for (; i != NULL; i = i->next) {
            ttt = i->data+carry_in*10;
            i->data = ttt/(2*n + 1);
            carry_in = ttt%(2*n + 1);
        }        

        // 如果 An == 0 跳出循环
        break_flag = true;
        i = An.getHead();
        i = i->next;
        for (; i != NULL; i = i->next) {
            if (i->data == 0) {
                ;
            }
            else {
                break_flag = false;
            }
        }
        if (break_flag) {
            break;
        }

        // 然后加到 sum 里面
        i = An.getEnd();
        j = sum.getEnd();
        carry_in = 0;
        for (; i != An.getHead() && j != An.getHead(); i = i->former, j = j->former) {
            ttt = i->data + j->data + carry_in;
            j->data = ttt%10;
            carry_in = ttt/10;
        }

        // An.output();
        // sum.output();
        // cout<<endl;
        n += 1;
    }
    // sum.output();
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
