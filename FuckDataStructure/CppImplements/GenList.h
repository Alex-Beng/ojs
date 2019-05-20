#ifndef GEN_LIST_H
#define GEN_LIST_H

#include <cstring>
#include <iostream>
using namespace std;

enum {HEAD, ATOM, SON_HEAD};

template<class T>
struct GListNode {
    GListNode() {
        type = 0;
        next = NULL;
        info.ref = 0;  
    }
    GListNode(GListNode<T>& ttt) {
        type = ttt.type;
        next = ttt.next;
        info = ttt.info;
    }
    GListNode(int node_type) {
        type = node_type;
    }
    int type;
    union {
        int ref;
        T value;
        GListNode<T>* son_next;
    } info;
    GListNode<T>* next;
};


template <class T>
class GenList {
protected:
    GListNode<T>* first;

public:
    GenList();

    void input(char* str, GListNode<T>* head);
    int Lenght(GListNode<T>* head);
    int Depth(GListNode<T>* head);
    GListNode<T>* getHead() const;
};

template<class T>
GenList<T>::GenList() {
    first = new GListNode<T>;
}

template<class T>
void GenList<T>::input(char* str, GListNode<T>* head) {
    char t_c;
    while (1) {
        t_c = *str++;
        cout<<(int)t_c<<endl;
        if (t_c == '\0') {
            break;
        }
        switch (t_c) {
        case '(':
            head->next = new GListNode<T>(SON_HEAD);
            input(str, head->info.son_next);
            break;
        case ')':
            head->next = NULL;
            return;
        case ',':
            break;
        default:// else
            head->next = new GListNode<T>(ATOM);
            head->info.value = t_c;
            head = head->next;
        }
    }
}

template<class T>
int GenList<T>::Lenght(GListNode<T>* head) {
    if (first != NULL) {
        return 1+Lenght(head->next);
    }
    else {
        return 0;
    }
}

template<class T>
int GenList<T>::Depth(GListNode<T>* head) {
    if (head == NULL) { // 空表返回1
        return 1;
    }
    
    GListNode<T>* t_ptr = head->next;
    int depth = -1;
    int t;
    while (t_ptr != NULL) {
        if (t_ptr->type == SON_HEAD) {
            t = Depth(t_ptr->info.son_next);
            if (t > depth) {
                depth = t;              
            }
        }
        t_ptr = t_ptr->next;
    }
    return depth+1;
}

template<class T>
GListNode<T>* GenList<T>::getHead() const {
    return first;
}

#endif