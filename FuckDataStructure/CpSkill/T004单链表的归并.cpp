#include <iostream>
using namespace std;

template<class T>
struct LinkNode {
    T data;
    LinkNode<T>* next;
    LinkNode() {
        next = NULL;
    }
};

template<class T>
class SingleList {
protected:
    LinkNode<T>* head;
    int len;
public:
    SingleList();
    ~SingleList();

    void PushBack(T x);
    T getData(int idx) const;
    int getLen() const;
    void output(int layer) const;
    void input(int n);
};

template<class T>
SingleList<T>::SingleList() {
    head = new LinkNode<T>;
    len = 0;
}

template<class T>
SingleList<T>::~SingleList() {
    LinkNode<T>* t_ptr;
    while (head->next != NULL) {
        t_ptr = head;
        head = head->next;
        delete t_ptr;
    }
}

template<class T>
void SingleList<T>::PushBack(T x) {
    LinkNode<T>* t_ptr = head;
    while (t_ptr->next != NULL) {
        t_ptr = t_ptr->next;
    }
    LinkNode<T>* new_node = new LinkNode<T>;
    new_node->data = x;
    t_ptr->next = new_node;
    len++;
}

template<class T>
T SingleList<T>::getData(int idx) const {
    LinkNode<T>* t_ptr = head;
    for (int i=0; i<=idx; i++) {
        t_ptr = t_ptr->next;
    }
    return t_ptr->data;
}

template<class T>
int SingleList<T>::getLen() const {
    return len;
}

template<class T>
void SingleList<T>::output(int layer) const {
    if (layer == len) {
        return ;
    }
    else {
        T data = this->getData(layer);
        output(layer+1);
        cout<<data<<' ';
        // if (layer != 0) {
        //     cout<<' ';
        // }
    }
}

template<class T>
void SingleList<T>::input(int n) {
    int t;
    for (int i=0; i<n; i++) {
        cin>>t;
        this->PushBack(t);
    }
}

template<class T>
SingleList<T> Merge(SingleList<T>& sl_1, SingleList<T>& sl_2) {
    int h1 = 0;
    int h2 = 0;
    int len1 = sl_1.getLen();
    int len2 = sl_2.getLen();
    SingleList<T> merged_list;
    while (h1 < len1 && h2 < len2) {
        if (sl_1.getData(h1) <= sl_2.getData(h2)) {
            merged_list.PushBack(sl_1.getData(h1++));
        }
        else {
            merged_list.PushBack(sl_2.getData(h2++));
        }
    }
    while (h1 < len1) {
        merged_list.PushBack(sl_1.getData(h1++));
    }
    while (h2 <len2) {
        merged_list.PushBack(sl_2.getData(h2++));
    }
    return merged_list;
}


int main(int argc, char const *argv[]) {
    int m, n;
    SingleList<int> a;
    SingleList<int> b;
    cin>>m>>n;

    a.input(m);
    b.input(n);

    SingleList<int> merged_list = Merge(a, b);
    merged_list.output(0);

    return 0;
}
