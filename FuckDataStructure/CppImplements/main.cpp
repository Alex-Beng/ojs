#include "SeqList.h"
#include "SingleLinkList.h"
#include "CircularLinkList.h"
#include "Stack.h"
#include "Queue.h"
#include "DoublyLinkList.h"
#include "TripleSparseMat.h"
#include "CrossSparseMat.h"
#include "GenList.h"

int main(int argc, char const *argv[]) {
    GenList<int> gl;    
    GListNode<int>* head = gl.getHead();

    char str[100];
    cin>>str;

    gl.input(str, head);
    // cout<<gl.Lenght(gl.getHead());
        cout<<' '<<gl.Depth(gl.getHead())<<endl;
    return 0;

    CrossSparseMat<int> csm(2, 2, 2);
    CrossSparseMat<int> csm2(2, 2, 2);
    csm.input(2);
    csm2.input(2);
    csm.output();

    csm.Add(csm2);
    csm.output();
    return 0;

    TripleSparseMat<int> tsm;
    tsm.input();
    // tsm.output();
    tsm.t();
    tsm.output();
    return 0;



    DoublyLinkList<int> dll;
    dll.PushBack(2);
    for (int i=0; i<10; i++) {
        dll.PushBack(0);
    }
    dll.output();
    
    for (LinkNode<int>* tail = dll.getEnd(); tail != dll.getHead(); tail = tail->former) {
        tail->data += 1;
    }
    dll.output();

    LinkNode<int>* it = dll.getHead();
    it = it->next;
    for (; it != NULL; it = it->next) {
        it->data+=7;
    }
    dll.output();


    Queue<int> qrq(5);
    int n, ttt;
    cin>>n;
    for (int i=0; i<n; i++) {
        cin>>ttt;
        if (qrq.Push(ttt)) {
            ;
        }
        else {
            cout<<"No"<<endl;
        }
    }
    while (!qrq.Empty()) {
        cout<<qrq.Pop()<<endl;
    }
    int t = 233;
    // CircularLinkList<int> cll;
    // cll.input();
    // cll.PushBack(666);
    // cll.output();

    Stack<int> sk;
    for(int i=0; i<7; i++) {
        cin>>t;
        sk.Push(t);
        cout<<sk.Top();
    }
    cout<<sk.Size()<<endl;
    for (int i=0; i<7; i++) {
        cout<<sk.Pop()<<endl;
    }

    cout<<(int)'['<<(char)92<<' '<<(int)']'<<endl;
    cout<<(int)'('<<' '<<(int)')'<<endl;
    cout<<(int)'{'<<(char)124<<' '<<(int)'}'<<endl;
    return 0;
}
