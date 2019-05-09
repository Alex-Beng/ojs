#ifndef HUFFMAN_TREE_H
#define HUFFMAN_TREE_H
#include "MinHeap.h"

#include <iostream>
using namespace std;

template<class T>
struct TreeNode {
    T data;
    TreeNode* l_child, r_child, parent;
    TreeNode(): l_child(NULL), r_child(NULL), parent(NULL) {}
    bool operator <=(TreeNode& r) {return this->data <= r.data;}
    bool operator >(TreeNode& r) {return this->data > r.data;}
};

template<class T>
class HuffmanTree {
public:
    HuffmanTree(TreeNode<T>* datas, int n);
    ~HuffmanTree();
protected:
    TreeNode<T>* root;
    string Encode(T a);
    Decode(string str);
};

template<class T>
HuffmanTree<T>::HuffmanTree(TreeNode<T>* datas, int n) {
    MinHeap<int> hp(n);

    for (int i=0; i<n; i++) {
        hp.Insert
    }
}

#endif