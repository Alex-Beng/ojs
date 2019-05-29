#include <iostream>
using namespace std;

#define private public

class HeapNode {
public:
    int idx;
    int data;   // data 这里是距离源点的路径长度
    HeapNode () {
        ;
    }
    HeapNode (HeapNode& r) {
        data = r.data;
    }
    bool operator>(HeapNode& r) {
        return data > r.data;
    }
    bool operator<=(HeapNode& r) {
        return data <= r.data;
    }
};

// 堆用于维护未访问的结点
class Heap {
public:
    Heap(int size = 233);
    ~Heap();
    void Insert(HeapNode x);
    HeapNode RemoveMin();
    bool IsEmpty();
    bool IsFull();
private:
    HeapNode* heap;
    int current_size;
    int max_size;
    void ShiftDown(int start, int end);
    void ShiftUp(int start);
};

int main(int argc, char const *argv[]) {
    int n;
    cin>>n;
    int aj_mat[n][n];

    for(int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin>>aj_mat[i][j];
        }
    }

    int begin_node;
    int end_node;
    cin>>begin_node>>end_node;  



    return 0;
}


Heap::Heap(int size) {
    max_size = size;
    heap = new HeapNode[max_size];
    current_size = 0;
}


Heap::~Heap() {
    delete [] heap;
}


void Heap::Insert(HeapNode x) {
    if (current_size == max_size) {
        return ;
    }
    else {
        heap[current_size] = x;
        ShiftUp(current_size);
        current_size++;
        return ;
    }
}


HeapNode Heap::RemoveMin() {
    HeapNode t = heap[0];
    heap[0] = heap[--current_size];
    ShiftDown(0, current_size-1);
    return t;
}


bool Heap::IsEmpty() {
    return (current_size==0);
}


bool Heap::IsFull() {
    return (current_size==max_size);
}


void Heap::ShiftDown(int start, int end) {
    int i = start;
    int j = 2*i + 1;
    HeapNode t = heap[i];
    while (j <= end) {
        if (j+1 <= end && heap[j] > heap[j+1]) {
            j++;
        }

        if (t <= heap[j]) {
            break;
        }
        else {
            heap[i] = heap[j];
            i = j;
            j = 2*i + 1;
        }
    }
    heap[i] = t;
}


void Heap::ShiftUp(int start) {
    int j = start;
    int i = (j-1) / 2;
    HeapNode t = heap[j];
    while (j > 0) {
        if (heap[i] <= t) {
            break;
        }
        else {
            heap[j] = heap[i];
            j = i;
            i = (j-1) / 2;
        }
    }
    heap[j] = t;
}


