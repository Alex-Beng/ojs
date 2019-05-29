#ifndef HEAP_V2_H
#define HEAP_V2_H

#define private public

#include <iostream>
using namespace std;

class HeapNode {
public:
    int data;
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



#endif