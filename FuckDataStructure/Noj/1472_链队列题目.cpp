#include <iostream>
using namespace std;

struct LinkNode {
    int data;
    LinkNode* next;
    LinkNode() {
        next = NULL;
    }
};

class LinkQueue {
private:
    LinkNode* head;
    LinkNode* tail;
public:
    LinkQueue() {
        head = new LinkNode;
        tail = head;
    }
    ~LinkQueue() {
        delete head;
    }
    void PushBack(int t) {
        tail->next = new LinkNode;
        tail = tail->next;
        tail->data = t;
    }
    void RmFront() {
        if (head->next == NULL) {
            return;
        }
        LinkNode* t_ptr = head->next;
        head->next = t_ptr->next;
        // int t = t_ptr->data;
        delete t_ptr;
    }
    void output() {
        LinkNode* t_ptr = head->next;
        while (t_ptr != NULL) {
            cout<<t_ptr->data;
            if (t_ptr->next != NULL) {
                cout<<' ';
            }
            t_ptr = t_ptr->next;
        }
        cout<<endl;
    }
    bool Empty() {
        return head->next==NULL;
    }
};

int main(int argc, char const *argv[]) {
    LinkQueue lq;
    int n;
    int t;
    cin>>n;
    for (int i=0; i<n; i++) {
        cin>>t;
        lq.PushBack(t);        
    }
    while (1) {
        if (lq.Empty()) {
            break;
        }
        lq.output();
        lq.RmFront();
        
    }
    return 0;
}
