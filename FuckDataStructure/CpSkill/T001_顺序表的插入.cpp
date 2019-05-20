#include <iostream>
using namespace std;

class SeqList {
private:
    int* data;
    long max_size;
    long tail;
public:
    SeqList(int size = 233);
    ~SeqList();
    void input();
    void output();
    void Insert(int t_num);
};

SeqList::SeqList(int size) {
    data = new int[size];
    max_size = size;
    int tail = -1; 
}

SeqList::~SeqList() {
    delete[] data;
}

void SeqList::input() {
    cin>>tail;
    tail--;
    for (int i=0; i<=tail; i++) {
        cin>>data[i];
    }
}

void SeqList::output() {
    for (int i=0; i<=tail; i++) {
        cout<<data[i];
        if (i!=tail) {
            cout<<' ';
        }
    }
}

void SeqList::Insert(int t_num) {
    int pos2insert = 0;
    for (int i=0; i<=tail; i++) {
        if (i==0 && data[i] >= t_num) {
            pos2insert = i;
            break;
        }

        if (i == tail) {
            pos2insert = i;
            break;
        }

        if (data[i] >= t_num && t_num > data[i-1]) {
            pos2insert = i;
            break;
        }
    }
    for (int i=tail; i>=pos2insert; i--) {
        data[i+1] = data[i];
    }
    data[pos2insert] = t_num;
    tail++;
}

int main(int argc, char const *argv[]) {
    SeqList sq(2333);
    sq.input();
    // sq.output();
    int n;
    cin>>n;
    sq.Insert(n);
    sq.output();
    return 0;
}
