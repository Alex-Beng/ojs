#include <iostream>
using namespace std;

class Queue {
private:
    int* data;
    int head;
    int len;
    int cap;
public:
    Queue(int n) {
        data = new int[n];
        head = 0;
        len  = 0;
        cap  = n;
    }
    void Push(int t) {
        data[(head+len)%cap] = t;
        len++;
    }
    void Pop() {
        head = (head+1)%cap;
        len--;
    }
    int GenNext() {
        int t_sum = 0;
        for (int i=0; i<cap; i++) {
            t_sum += data[i];
        }
        return t_sum;
    }
};

int main() {
    int k;
    int max;
    cin>>k>>max;
    Queue qrq(k);
    for (int i=0; i<k-1; i++) {
        qrq.Push(0);
    }
    qrq.Push(1);

    int t = qrq.GenNext();
    int t2;
    int cnt = k;
    while (t <= max) {
        qrq.Pop();
        qrq.Push(t);
        t2 = qrq.GenNext();
        if (t2 > max) {
            cout<<cnt<<endl<<t<<endl;
            break;
        }
        else {
            cnt++;
        }
        t = t2;
    }
    return 0;
}