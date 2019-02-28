#include "SeqList.h"
#include "SingleLinkList.h"

int main(int argc, char const *argv[]) {
    int t = 233;
    int tt;
    SeqList<int> sq(t);
    SingleLinkList<int> sll(t);
    if (sll.getData(1, tt)) {
        cout<<tt<<endl;
    }
    sll.output();
    sll.input();
    cout<<sll.Length()<<endl;
    sll.output();

    t = 0;
    if (sll.Remove(2, t)) {
        cout<<t<<endl;
    }
    sll.output();

    t = 666;
    if (sll.Insert(0, t)) {
        sll.output();
    }


    return 0;
}
