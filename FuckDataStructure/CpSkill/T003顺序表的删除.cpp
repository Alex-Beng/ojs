#include <iostream>
using namespace std;

template<class T>
class SeqList {
protected:
    T* data;
    int max_size;
    int tail;
public:
    SeqList(int size) {
        if (size > 0) {
            data = new T[size];
            max_size = size;
            tail = -1;
        }
    }

    void PushBack(T x) {
        if (tail+1 <= max_size-1) {
            data[++tail] = x;
        }
    }
    T getData(int idx) {
        return data[idx];
    }
    int getLen() {
        return tail+1;
    }
    void input(int len) {
        tail = len;
        tail--;
        for (int i=0; i<=tail; i++) {
            cin>>data[i];
        }
    }
    void output() {
        for (int i=0; i<=tail; i++) {
            cout<<data[i];
            if (i != tail) {
                cout<<endl;
            }
        }
    }
};

template<class T>
SeqList<T> And(SeqList<T>& sq_1, SeqList<T>& sq_2) {
    int h1 = 0;
    int h2 = 0;
    int len1 = sq_1.getLen();
    int len2 = sq_2.getLen();
    SeqList<T> and_list(min(len1, len2));
    while (h1 < len1 && h2 < len2) {
        if (sq_1.getData(h1) < sq_2.getData(h2)) {
            h1++;
        }
        else if (sq_1.getData(h1) > sq_2.getData(h2)) {
            h2++;
        }
        else {
            and_list.PushBack(sq_1.getData(h1));
            h1++;
            h2++;
        }
    }
    return and_list;
}

template<class T>
void OutWithout(SeqList<T>& sq, SeqList<T>& without_list) {
    int h1 = 0;
    int h2 = 0;
    int len1 = sq.getLen();
    int len2 = without_list.getLen();
    while (h1 < len1 && h2 < len2) {
        if (sq.getData(h1) < without_list.getData(h2)) {
            cout<<sq.getData(h1);
            if (h1 != len1-1) {
                cout<<' ';
            }
            h1++;
        }
        else if (sq.getData(h1) > without_list.getData(h2)) {
            h2++;
        }
        else {
            h1++;
        }
    }
    while (h1 < len1) {
        cout<<sq.getData(h1);
        if (h1 != len1-1) {
                cout<<' ';
        }
        h1++;
    }
}

int main(int argc, char const *argv[]) {
    SeqList<int> a(233);
    SeqList<int> b(233);
    SeqList<int> c(233);
    int m, n, p;
    cin>>m>>n>>p;
    a.input(m);
    b.input(n);
    c.input(p);

    SeqList<int> bc_and = And(b, c);
    // bc_and.output();
    OutWithout(a, bc_and);
    return 0;
}
