#ifndef SINGLELINKLIST_H
#define SINGLELINKLIST_H

#include "LinearList.h"
// 注意实现的是有附加头节点的单链表
template<class T>
class SingleLinkList:public LinearList<T> {
protected:
    struct LinkNode {
        T data;
        LinkNode* next;
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
    bool getData(int i, T& x) const;
    bool setData(int i, T& x);
    bool Insert(int i, T& x);
    bool Remove(int i, T& x);
    bool IsEmpty() const;
    void Sort();
    void input();
    void output();
public:
    LinkNode* getHeader() const;
    T* Locate(int i) const;             // 定位链表第i项，返回T*指针
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

    LinkNode* t_ptr = first->next;
    t_ptr = new LinkNode;
    Len++;
    t_ptr->data = x;
}

template<class T>
SingleLinkList<T>::SingleLinkList(SingleLinkList<T>& L) {
    first = new LinkNode;

    LinkNode* L_ptr = L.getHeader();
    LinkNode* this_ptr = first;
    while (L_ptr->next != NULL) {
        this_ptr->next = new LinkNode;

        this_ptr = this_ptr->next;
        L_ptr = L_ptr->next;

        this_ptr->data = L_ptr->data;
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

#endif 