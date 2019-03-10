#ifndef CIRCULARLINKLIST_H
#define CIRCULARLINKLIST_H

#include <bits/stdc++.h>
using namespace std;

template<class T>
class CircularLinkList {
protected:
    struct LinkNode {
        T data;
        LinkNode* next;
        LinkNode() {
            next = NULL;
        }
    };
    LinkNode* first;
    int Len;
public:
    CircularLinkList();
    ~CircularLinkList();

    int Length() const;
    int Search(T x) const;              // 找是循环链表的第几项
    T* Locate(int i) const;             // 定位链表第i项，返回T*指针
    bool PushBack(T x);                // 类似 vector 的push_back()
    bool getData(int i, T& x) const;
    bool setData(int i, T& x);
    bool Insert(int i, T x);
    bool Remove(int i, T& x);
    bool IsEmpty() const;
    void Sort();
    void input();
    void output();
};

template<class T>
CircularLinkList<T>::CircularLinkList()   {
    first = new LinkNode; 
    first->next = first;
    Len = 0;
}

template<class T>
CircularLinkList<T>::~CircularLinkList() {
    LinkNode* t_ptr = first;
    LinkNode* for_del;
    do {
        for_del = first;
        first = first->next;
        delete for_del;
    } while (first != t_ptr);
}

template<class T>
int CircularLinkList<T>::Length()const {
    return Len;
}

template<class T>
int CircularLinkList<T>::Search(T x)const {
    LinkNode* for_search = first;
    int counter = 0;
    while(for_search->next != first) {
        if (for_search->data == x) {
            return  counter;
        }
        for_search = for_search->next;
        counter++;
    }
}

template<class T>
bool CircularLinkList<T>::PushBack(T x) {
    Insert(Len, x);
}

template<class T>
bool CircularLinkList<T>::getData(int i, T& x)const {
    LinkNode* t_ptr = first;
    for (int j = 0; j < i; j++) {
        if (t_ptr->next != first) {
            t_ptr = t_ptr->next;
        }
        else {
            return false;
        }
    }
    x = t_ptr->data;
    return true;
}

template<class T>
bool CircularLinkList<T>::setData(int i, T& x) {
    LinkNode* t_ptr = first;
    for (int j = 0; j < i; j++) {
        if (t_ptr->next == first) {
            return false;
        }
        else {
            t_ptr = t_ptr->next;
        }
    }
    t_ptr->data = x;
}

template<class T>
bool CircularLinkList<T>::Insert(int i, T x) {
    if (i >= 0) {
        LinkNode* t_ptr = first;
        for (int j = 0; j < i; j++) {
            if (t_ptr->next == first) {
                return false;
            }
            else {
                t_ptr = t_ptr->next;
            }
        }
        LinkNode* new_node = new LinkNode;
        new_node->data = x;
        new_node->next = t_ptr->next;

        t_ptr->next = new_node;

        Len++;
    }
    else {
        return false;
    }
}

template<class T>
bool CircularLinkList<T>::Remove(int i, T& x) {
    if (i >= 1) {
        LinkNode* t_ptr = first;
        for (int j = 0; j < i-1; j++) {
            if (t_ptr->next == first) {
                return false;
            }
            else {
                t_ptr = t_ptr->next;
            }
        }
        LinkNode* delete_ptr = t_ptr->next;
        t_ptr->next = delete_ptr->next;

        x = delete_ptr->data;
        delete delete_ptr;
        Len--;
    }
    else {
        return false;
    }
}

template<class T>
bool CircularLinkList<T>::IsEmpty()const {
    return (Len == 0);
}


template<class T>
void CircularLinkList<T>::Sort() {

}

template<class T>
void CircularLinkList<T>::input() {
    int n;
    cin>>n;
    T t;
    int L = Len;
    for (int i = L; i < n+L; i++) {
        cin>>t;
        Insert(i, t);
    }
}

template<class T>
void CircularLinkList<T>::output() {
    LinkNode* t_ptr = first;
    while (t_ptr->next != first) {
        t_ptr = t_ptr->next;
        cout<<t_ptr->data<<' ';
    }
    cout<<endl;
}

template<class T>
T* CircularLinkList<T>::Locate(int i)const {
    LinkNode* t_ptr = first;
    for (int j = 0; j < i; j++) {
        if (t_ptr->next == first) {
            cerr<<"Locate error in line: "<<__LINE__<<endl;
            exit(1);
        }
        else {
            t_ptr = t_ptr->next;
        }
        
    }
    return &(t_ptr->data);
}

#endif