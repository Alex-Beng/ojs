#ifndef MIN_HEAP_H
#define MIN_HEAP_H
#include <iostream>
using namespace std;
#define DEAULTI_SIZE 10

template<class T>
class MinHeap {
public:
    MinHeap(int size = DEAULTI_SIZE);
    MinHeap(T* array, int n);
    ~MinHeap();
    bool Insert(T x);
    bool RemoveMin(T& x);
    bool isEmpty();
    bool isFull();
private:
    T* heap;
    int currect_size;
    int max_heap_size;
    void SiftDown(int start, int m);
    void SiftUp(int start);
};

template<class T>
MinHeap<T>::MinHeap(int size) {
    max_heap_size = size;
    this->heap = new T[max_heap_size];
    currect_size = 0;
}

template<class T>
MinHeap<T>::MinHeap(T* array, int n) {
    max_heap_size = n;
    heap = new T[max_heap_size];
    for (int i=0; i<n; i++) {
        heap[i] = array[i];
    }
    currect_size = n;
    int current_pos = (currect_size-2)/2;
    while (current_pos >= 0) {
        SiftDown(current_pos, currect_size-1);
        current_pos--;
    }
}

template<class T>
MinHeap<T>::~MinHeap() {
    delete [] heap;
}

template<class T>
bool MinHeap<T>::Insert(T x) {
    if (currect_size == max_heap_size) {
        return false;
    }
    else {
        heap[currect_size] = x;
        SiftUp(currect_size);
        currect_size++;
        return true;
    }
}

template<class T>
bool MinHeap<T>::RemoveMin(T& x) {
    x = heap[0];
    heap[0] = heap[currect_size-1];
    currect_size--;
    SiftDown(0, currect_size-1);
    return true;
}

template<class T>
bool MinHeap<T>::isEmpty() {
    return (currect_size == 0);
}

template<class T>
bool MinHeap<T>::isFull() {
    return (currect_size == max_heap_size);
}


template<class T>
void MinHeap<T>::SiftDown(int start, int m) {
    int i = start;
    int j = 2*j + 1;
    int t = heap[i];
    while (j <= m) {
        if (j < m && heap[j] > heap[j+1]) {
            j++;
        }

        if (t <= heap[j]) {
            break;
        }
        else {
            heap[i] = heap[j];
            i = j;
            j = 2*j+1;
        }
    }
    heap[i] = t;
}

template<class T>
void MinHeap<T>::SiftUp(int start) {
    int j = start;
    int i = (j-1) / 2;
    int t = heap[j];
    while (j > 0) {
        if (heap[i] <= t) {
            break;
        }
        else {
            heap[j] = heap[i];
            j = i;
            i = (i-1) / 2;
        }
    }
    heap[j] = t;
}



#endif