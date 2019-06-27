#include <iostream>
using namespace std;

struct LinkNode {
    int data;
    LinkNode* next;
    LinkNode() {
        next = NULL;
    }
};

class LinkList {
private:
    LinkNode* head;
    int len;
public:
    LinkList();
    void input(int n);
    void output();
    int LastMMax(int m);
};

LinkList::LinkList() {
    head = new LinkNode;
}

void LinkList::input(int n) {
    len = n;

    LinkNode* tail_ptr = head;
    LinkNode* t_ptr;
    int t;
    for (int i=0; i<n; i++) {
        cin>>t;

        t_ptr = new LinkNode;
        t_ptr->data = t;
        tail_ptr->next = t_ptr;
        tail_ptr = t_ptr;
    }
}

void LinkList::output() {
    LinkNode* t_ptr = head->next;
    while (t_ptr != NULL) {
        cout<<t_ptr->data<<endl;
        t_ptr = t_ptr->next;
    }
}

int LinkList::LastMMax(int m) {
    LinkNode* begin_ptr = head;
    for (int i=0; i<(len-m); i++) {
        begin_ptr = begin_ptr->next;
    }
    int max = -1;
    begin_ptr = begin_ptr->next;
    while (begin_ptr != NULL) {
        if (begin_ptr->data > max) {
            max = begin_ptr->data;
        }
        begin_ptr = begin_ptr->next;
    }
    return max;
}

int main(int argc, char const *argv[]) {
    LinkList ll;
    int n;
    int m;
    cin>>n>>m;
    ll.input(n);
    // ll.output();
    cout<<ll.LastMMax(m)<<endl;
    return 0;
}
