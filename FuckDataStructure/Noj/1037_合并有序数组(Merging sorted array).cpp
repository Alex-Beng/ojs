#include <iostream>
using namespace std;

// 注意实现的是有附加头节点的单链表
template<class T>
class SingleLinkList {
public:
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
    bool Insert(T& x);
    bool Remove(int i, T& x);
    bool IsEmpty() const;
    void Sort();
    void input(int n);
    void output();
    void Merge(SingleLinkList<T>& L);
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
bool SingleLinkList<T>::Insert(T& x) {
    LinkNode* t_ptr = first;
    while (1) {
        if (t_ptr->next == NULL) {
            break;
        }
        if (t_ptr->data <= x && x < t_ptr->next->data) {
            break;
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
    return true;
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
void SingleLinkList<T>::input(int n) {
    int t;
    LinkNode* t_ptr = first;
    for (int i=0; i<n; i++) {
        cin>>t;
        t_ptr->next = new LinkNode;
        t_ptr->next->data = t;
        t_ptr = t_ptr->next;
        Len++;
    }
}


template<class T>
void SingleLinkList<T>::output() {
    LinkNode* t_ptr = first;
    while (t_ptr->next != NULL) {
        t_ptr = t_ptr->next;
        cout<<t_ptr->data<<endl;
    }
    // LinkNode* t_ptr = first;
    // if (t_ptr->next != NULL) {
    //     first = first->next;
    //     this->output();
    //     cout<<t_ptr->data<<endl;
    // }
    // else {
    //     cout<<t_ptr->data<<endl;
    // }
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

template<class T>
void SingleLinkList<T>::Merge(SingleLinkList<T>& L) {
    LinkNode* L_t_ptr = L.first;
    while (L_t_ptr->next != NULL) {
        L_t_ptr = L_t_ptr->next;
        this->Insert(L_t_ptr->data);
    }
}


int main(int argc, char const *argv[]) {
    SingleLinkList<int> sll_m, sll_n;
    int m, n;
    cin>>m;
    sll_m.input(m);
    cin>>n;
    sll_n.input(n);

    sll_m.Merge(sll_n);

    sll_m.output();
    return 0;
}
