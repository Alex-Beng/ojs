/**
 * 链表储存的二叉树
 */
#ifndef LL_BINARY_TREE_H
#define LL_BINARY_TREE_H

#include <iostream>
using namespace std;

template<class T>
struct TriLLNode {
    TriLLNode() {
        l_child = NULL;
        r_child = NULL;
        parent  = NULL;
    }
    T data;
    TriLLNode<T>* l_child;
    TriLLNode<T>* r_child;
    TriLLNode<T>* parent;
};

template<class T>
class LLBinaryTree {
public:
    LLBinaryTree();
    ~LLBinaryTree();
};

#endif