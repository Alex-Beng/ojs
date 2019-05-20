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
            if (i != tail) {
                cout<<endl;
            }
        }
    }
};

template<class T>
SeqList<T> Merge(SeqList<T> seq_list1, SeqList<T> seq_list2) {
    int h1 = 0;
    int h2 = 0;
    int len1 = seq_list1.getLen();
    int len2 = seq_list2.getLen();
    SeqList<T> merged_list(len1+len2);
    while (h1 < len1 && h2 < len2) {
        if (seq_list1.getData(h1) <= seq_list2.getData(h2)) {
            merged_list.PushBack(seq_list1.getData(h1++));
        }
        else {
            merged_list.PushBack(seq_list2.getData(h2++));
        }
    }
    
    while(h1 < len1) {
        merged_list.PushBack(seq_list1.getData(h1++));
    }
    while(h2 < len2) {
        merged_list.PushBack(seq_list2.getData(h2++));
    }
    return merged_list;
}

int main(int argc, char const *argv[]) {
    SeqList<int> sl_1(23);
    SeqList<int> sl_2(23);

    sl_1.input();
    sl_2.input();

    SeqList<int> merged = Merge(sl_1, sl_2);
    merged.output();
    return 0;
}

