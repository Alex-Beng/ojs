#ifndef HUFFMAN_TREE_H
#define HUFFMAN_TREE_H
#include "MinHeap.h"

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
    MinHeap<TreeNode<T>*> hp(value_num);

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
        hp.Insert(work);
        cout<<endl;
        hp.output();
        cout<<endl;
    }

    for (int i=0; i<n-1; i++) {
        hp.RemoveMin(first);
        hp.RemoveMin(second);
        Merge(first, second, parent);
        hp.Insert(parent);
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