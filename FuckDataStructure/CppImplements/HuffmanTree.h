#ifndef HUFFMAN_TREE_H
#define HUFFMAN_TREE_H

#include <iostream>
using namespace std;

template<class T>
struct TreeNode {
    T data;
    TreeNode<T>* l_child;
    TreeNode<T>* r_child;
    TreeNode<T>* parent;
    TreeNode(): l_child(NULL), r_child(NULL), parent(NULL) {}
    bool operator <=(TreeNode& r) {return this->data <= r.data;}
    bool operator >(TreeNode& r) {return this->data > r.data;}
};


class Heap {
    public:
    Heap(int size = 10) {
        max_heap_size = size;
        this->heap = new TreeNode<int>[max_heap_size];
        currect_size = 0;
    }
    Heap(TreeNode<int>* array, int n) {
        max_heap_size = n;
        heap = new TreeNode<int>[max_heap_size];
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
    ~Heap() {
        delete [] heap;
    }
    bool Insert(TreeNode<int> x) {
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

    bool RemoveMin(TreeNode<int>& x) {
        x = heap[0];
        heap[0] = heap[currect_size-1];
        currect_size--;
        SiftDown(0, currect_size-1);
        return true;
    }

    bool isEmpty() {
        return (currect_size == 0);
    }

    bool isFull() {
        return (currect_size == max_heap_size);
    }

    void output() {
        int t_sum = 0;
        int a_i = 1;
        for (int i=0; i<currect_size; i++) {
            cout<<heap[i].data<<' ';
            if (i == t_sum) {
                cout<<endl;
                t_sum += a_i*2;
                a_i *= 2;
            }
        }
    }
private:
    TreeNode<int>* heap;
    int currect_size;
    int max_heap_size;

    void SiftDown(int start, int m) {
        int i = start;
        int j = 2*i + 1;
        TreeNode<int> t = heap[i];
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
        heap[i].data = t.data;
    }
    void SiftUp(int start) {
        int j = start;
        int i = (j-1) / 2;
        TreeNode<int> t = heap[j];
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
        heap[j].data = t.data;
    }
};

template<class T>
class HuffmanTree {
public:
    HuffmanTree(T* datas, int n);
    ~HuffmanTree();
    void output(TreeNode<T>* node);
public:
    int value_num;
    TreeNode<T>* root;
    void Merge(TreeNode<T>* t1, TreeNode<T>* t2, TreeNode<T>* parent);
};

template<class T>
HuffmanTree<T>::HuffmanTree(T* datas, int n) {
    value_num = n;
    // MinHeap<TreeNode<T>*> hp(value_num);
    Heap hp(value_num);

    TreeNode<T>* parent;
    TreeNode<T>* first;
    TreeNode<T>* second;
    TreeNode<T>* work;
    for (int i=0; i<n; i++) {
        work = new TreeNode<T>;
        work->data = datas[i];
        work->l_child = NULL;
        work->r_child = NULL;
        work->parent  = NULL;
        hp.Insert(*work);
        cout<<endl;
        hp.output();
        cout<<endl;
    }

    for (int i=0; i<n-1; i++) {
        hp.RemoveMin(*first);
        hp.RemoveMin(*second);
        Merge(first, second, parent);
        hp.Insert(*parent);
        cout<<endl;
        hp.output();
    }
    root = parent;
}

template<class T>
HuffmanTree<T>::~HuffmanTree() {
    delete root;
}

template<class T>
void HuffmanTree<T>::Merge(TreeNode<T>* t1, TreeNode<T>* t2, TreeNode<T>* parent) {
    parent = new TreeNode<T>;
    parent->l_child = t1;
    parent->r_child = t2;
    parent->data = t1->data + t2->data;
    t1->parent = parent; 
    t2->parent = parent;
}

template<class T>
void HuffmanTree<T>::output(TreeNode<T>* node) {
    if (node != NULL) {
        cout<<node->data<<endl;
        output(node->l_child);
        output(node->r_child);
    }
}

#endif