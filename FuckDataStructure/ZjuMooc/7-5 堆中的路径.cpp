#include <iostream>
using namespace std;

class MinHeap {
public:
    MinHeap(int size);
    ~MinHeap();
    void Insert(int x);
    void ShowPath(int start);
private:
    int* heap_data;
    int heap_size;
    int curr_size;
    void SiftUp(int start);
};

int main(int argc, char const *argv[]) {
    int n, m;
    cin>>n>>m;

    MinHeap hp(n+1);
    for (int i=0; i<n; i++) {
        int t;
        cin>>t;
        hp.Insert(t);
    }
    for (int i=0; i<m; i++) {
        int t;
        cin>>t;
        hp.ShowPath(t-1);
    }
    return 0;
}

MinHeap::MinHeap(int size) {
    this->heap_size = size;
    this->heap_data = new int[size];
    curr_size = 0;
}

MinHeap::~MinHeap() {
    delete [] heap_data;
}

void MinHeap::Insert(int x) {
    if (curr_size == heap_size) {
        ;
    }
    else {
        heap_data[curr_size] = x;
        SiftUp(curr_size);
        curr_size++;
    }
}

void MinHeap::ShowPath(int idx) {
    while (idx > 0) {
        cout<<heap_data[idx]<<' ';
        idx = (idx-1) / 2;
    }
    cout<<heap_data[0]<<endl;
}

void MinHeap::SiftUp(int curr) {
    int curr_father = (curr-1)/2;
    int curr_data = heap_data[curr];

    while (curr > 0) {
        if (heap_data[curr_father] <= curr_data) {
            break;
        }
        else {
            heap_data[curr] = heap_data[curr_father];
            curr = curr_father;
            curr_father = (curr_father-1) / 2;
        }
    }
    heap_data[curr] = curr_data;
}

