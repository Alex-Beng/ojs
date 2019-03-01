#include <iostream>
using namespace std;

template<class T>
class SeqList {
protected:
    T* data;
    int max_size;
    int last;
    void resize(int new_size);
public:
    SeqList(int size);
    ~SeqList();

    void input();
    void output();
};   


template<typename T>
SeqList<T>::SeqList(int size) {
    if (size > 0) {
        max_size = size;
        last = -1;
        data = new T[max_size];
        if (data == NULL) {
        cerr << "fail to new in line: " << __LINE__ << endl;
            exit(1);
        }
    }
}
template<typename T>
SeqList<T>::~SeqList() {
    delete[] data;
}

template<typename T>
void SeqList<T>::input() {
    cin>>last;
    last--;
    for (int i = last; i >= 0; i--) {
        cin>>data[i];
    }
}

template<typename T>
void SeqList<T>::output() {
    for (int i = 0; i <= last; i++) {
        cout<<data[i]<<endl;
    }
}

int main(int argc, char const *argv[]) {
    SeqList<int> sq(100);
    sq.input();
    sq.output();
    return 0;
}

