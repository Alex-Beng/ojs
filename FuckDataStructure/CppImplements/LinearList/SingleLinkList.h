#ifndef SINGLELINKLIST_H
#define SINGLELINKLIST_H

#include "LinearList.h"
// 注意实现的是有附加头节点的单链表
template<class T>
class SingleLinkList {
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
    SingleLinkList();
    SingleLinkList(T& x);
    SingleLinkList(SingleLinkList<T>& L);
    ~SingleLinkList();

    int Length() const;
    int Search(T& x) const;             // 找是单链表的第几项
    T* Locate(int i) const;             // 定位链表第i项，返回T*指针
    bool getData(int i, T& x) const;
    bool setData(int i, T& x);
    bool Insert(int i, T& x);
    bool Remove(int i, T& x);
    bool IsEmpty() const;
    void Sort();
    void input();
    void output();
};

template<class T>
SingleLinkList<T>::SingleLinkList()   {
    first = new LinkNode; 
    Len = 0;
}

template<class T>
SingleLinkList<T>::SingleLinkList(T& x) {
    first = new LinkNode;
    Len = 0;

    first->next = new LinkNode;
    Len++;
    first->next->data = x;
}

template<class T>
SingleLinkList<T>::SingleLinkList(SingleLinkList<T>& L) {
    first = new LinkNode;
    Len = 0;

    LinkNode* L_ptr = L.getHeader();
    LinkNode* this_ptr = first;
    while (L_ptr->next != NULL) {
        this_ptr->next = new LinkNode;

        this_ptr = this_ptr->next;
        L_ptr = L_ptr->next;

        this_ptr->data = L_ptr->data;
        Len++;
    }
}

template<class T>
SingleLinkList<T>::~SingleLinkList() {
    LinkNode* t_ptr;
    while (first->next != NULL) {
        t_ptr = first->next;        
        delete first;
        first = t_ptr;
    }
}

template<class T>
int SingleLinkList<T>::Length()const {
    return Len;
}

template<class T>
int SingleLinkList<T>::Search(T& x)const {
    LinkNode* t_ptr = first;
    while(t_ptr->next != NULL) {
        if (t_ptr->data == x) {
            return  0;
        }
    }
}

template<class T>
bool SingleLinkList<T>::getData(int i, T& x)const {
    LinkNode* t_ptr = first;
    for (int j = 0; j < i; j++) {
        if (t_ptr->next != NULL) {
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
bool SingleLinkList<T>::setData(int i, T& x) {
    LinkNode* t_ptr = first;
    for (int j = 0; j < i; j++) {
        if (t_ptr->next == NULL) {
            return false;
        }
        else {
            t_ptr = t_ptr->next;
        }
    }
    t_ptr->data = x;
}

template<class T>
bool SingleLinkList<T>::Insert(int i, T& x) {
    if (i >= 0) {
        LinkNode* t_ptr = first;
        for (int j = 0; j < i; j++) {
            if (t_ptr->next == NULL) {
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
bool SingleLinkList<T>::Remove(int i, T& x) {
    if (i >= 1) {
        LinkNode* t_ptr = first;
        for (int j = 0; j < i-1; j++) {
            if (t_ptr->next == NULL) {
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
bool SingleLinkList<T>::IsEmpty()const {
    return (Len == 0);
}


template<class T>
void SingleLinkList<T>::Sort() {

}

template<class T>
void SingleLinkList<T>::input() {
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
void SingleLinkList<T>::output() {
    LinkNode* t_ptr = first;
    while (t_ptr->next != NULL) {
        t_ptr = t_ptr->next;
        cout<<t_ptr->data<<' ';
    }
    cout<<endl;
}

template<class T>
T* SingleLinkList<T>::Locate(int i)const {
    LinkNode* t_ptr = first;
    for (int j = 0; j < i; j++) {
        if (t_ptr->next == NULL) {
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