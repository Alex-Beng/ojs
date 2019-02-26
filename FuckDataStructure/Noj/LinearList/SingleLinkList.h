#ifndef SINGLELINKLIST_H
#define SINGLELINKLIST_H


#include "LinearList.h"

template<class T>
class SingleLinkList:public LinearList<T> {
protected:
    struct LinkNode {
        T data;
        LinkNode* next;
    };
public:
    SingleLinkList(int size = 100);
    SingleLinkList(SingleLinkList<T>& L);
    ~SingleLinkList();

    int Size() const;
    int Lenght() const;
    int Search(T& x) const;
    int Locate(int i) const;
    bool getData(int i, T& x) const;
    bool setData(int i, T& x);
    bool Insert(int i, T& x);
    bool Remove(int i, T& x);
    bool IsEmpty() const;
    bool IsFull() const;
    void Sort();
    void input();
    void output();
};
#endif