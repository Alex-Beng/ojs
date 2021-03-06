#include <iostream>
using namespace std;

class SeqList {
public:
    int* data;
    long max_size;
    long tail;
public:
    SeqList(int size = 233) {
        data = new int[size];
        max_size = size;
    }
    ~SeqList() {
        delete[] data;
    }
    void input() {
        cin>>tail;
        tail--;
        for (int i=0; i<=tail; i++) {
            cin>>data[i];
        }
    }
    void output() {
        for (int i=0; i<=tail; i++) {
            cout<<data[i];
            if (i!=tail) {
                cout<<' ';
            }
        }
    }
    void Revserse() {
        int middle = tail/2;
        int t;
        for (int i=0; i<=middle; i++) {
            t = data[i];
            data[i] = data[tail-i];
            data[tail-i] = t;
        }
    }
};

class LinkNode {
public:
    int data;
    LinkNode* next;
    LinkNode(LinkNode* ln, int dt) {
        ln->next = this;
        this->data = dt;
        this->next = NULL;
    }
    LinkNode(int dt) {
        this->data = dt;
        this->next = NULL;
    }
    LinkNode() {
        this->next = NULL;
    }
};

class LinkList {
private:
    LinkNode* first;
    long len;
public:
    LinkList() {
        first = new LinkNode();
    }
    LinkList(SeqList& sq) {
        first = new LinkNode();
        len = sq.tail+1;
        LinkNode* t_ptr = first;
        LinkNode* new_ptr;
        int t;
        for (int i=0; i<=sq.tail; i++) {
            t = sq.data[i];
            // cout<<'*'<<t<<endl;
            new_ptr = new LinkNode(t);
            t_ptr->next = new_ptr;
            t_ptr = t_ptr->next;
        }
    }
    ~LinkList() {
        LinkNode* t_ptr;
        while (first->next != NULL) {
            t_ptr = first;
            first = first->next;
            
            delete t_ptr;
        }
    }
    void input() {
        cin>>len;
        LinkNode* t_ptr = first;
        int t;
        for (int i=0; i<len; i++) {
            cin>>t;
            t_ptr = new LinkNode(t_ptr, t);
            t_ptr = t_ptr->next;
        }
    }
    void output() {
        LinkNode* t_ptr = first->next;
        while (t_ptr != NULL) {
            cout<<t_ptr->data;
            if (t_ptr->next != NULL) {
                cout<<' ';
            }
            t_ptr = t_ptr->next;
        }
    }
    void Reverse(int layer) {
        LinkNode* t_ptr = first->next;
        LinkNode* tail;
        if (layer == len) {
            return ;
        }
        else {
            for (int i=0; i<layer; i++) {
                t_ptr = t_ptr->next;
            }
            Reverse(layer+1);
            // cout<<t_ptr->data<<endl<<endl;
        }
        tail = first;        
        for (int i=0; i<len-layer-1; i++) {
            tail = tail->next;
        }
        tail->next = t_ptr;
        t_ptr->next = NULL;
        // this->output();
    }
};




int main(int argc, char const *argv[]) {
    SeqList sq;
    sq.input();
    // sq.output();
    LinkList ll(sq);
    // sq.output();
    sq.Revserse();
    sq.output();
    cout<<endl;
    // ll.output();
    ll.Reverse(0);
    ll.output();
    return 0;
}
