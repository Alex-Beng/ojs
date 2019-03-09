#ifndef DOUBLYLINKLIST_H
#define DOUBLYLINKLIST_H

#include <bits/stdc++.h>
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
    cout<<endl;
}

#endif