#include <iostream>
using namespace std;

class LinearList {
public:
    int* head;
    int len;
public:
    LinearList() {
        head = new int[250];
        len = 0;
    }
    void input() {
        for (int i=0; i<len; i++) {
            cin>>head[i];
        }
    }
    bool Has(int t) {
        for (int i=0; i<len; i++) {
            if (head[i] == t) {
                return true;
            }
        }
        return false;
    }
    void Insert(int t) {
        head[len++] = t; 
    }
    void output() {
        for (int i=0; i<len; i++) {
            cout<<head[i]<<endl;
        }
    }
};

int main(int argc, char const *argv[]) {
    LinearList la;
    LinearList lb;
    LinearList lc;
    cin>>la.len>>lb.len;
    la.input();
    lb.input();

    int* t_head = la.head;
    for (int i=0; i<la.len; i++) {
        if (lc.Has(t_head[i])) {
            ;
        }
        else {
            lc.Insert(t_head[i]);
        }
    }

    t_head = lb.head;
    for (int i=0; i<lb.len; i++) {
        if (lc.Has(t_head[i])) {
            ;
        }
        else {
            lc.Insert(t_head[i]);
        }
    }
    lc.output();
    return 0;
}
