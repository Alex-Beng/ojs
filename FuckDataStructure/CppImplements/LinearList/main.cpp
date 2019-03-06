#include "SeqList.h"
#include "SingleLinkList.h"
#include "CircularLinkList.h"
#include "Stack.h"
#include "Queue.h"

int main(int argc, char const *argv[]) {
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
