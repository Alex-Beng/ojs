/**
 * 链表储存的二叉树
 */
#ifndef LL_BINARY_TREE_H
#define LL_BINARY_TREE_H

#include <string>
#include <sstream>
#include <iostream>
using namespace std;

template<class T>
struct TriLLNode {
    TriLLNode() {
        l_child = NULL;
        r_child = NULL;
        parent  = NULL;
    }
    TriLLNode(T t_data) {
        data = t_data;
        l_child = NULL;
        r_child = NULL;
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
    void inputPreOrd(stringstream& in, TriLLNode<T>* &sub_tree);
    TriLLNode<T>* inputPreAndMid(T* vlr, T* lvr, int n);
    void outputMidOrd(TriLLNode<T>* sub_tree);
    void outputTaiOrd(TriLLNode<T>* sub_tree);
    

    int getLeafNum(TriLLNode<T>* sub_tree);
    TriLLNode<T>* getHead();
    
private:
    TriLLNode<T>* root;
};

template<class T>
LLBinaryTree<T>::LLBinaryTree() {
    root = NULL;    
}

template<class T>
LLBinaryTree<T>::~LLBinaryTree() {
    ;
    // so fucking to destroy a tree
}


template<class T>
void LLBinaryTree<T>::inputPreOrd(stringstream& in, TriLLNode<T>* &sub_tree) {
    T t_data;
    if (!in.eof()) {
        in>>t_data;
        // cout<<t_data<<233<<endl;
        if (t_data != '#') {
            // cout<<"in"<<endl;
            sub_tree = new TriLLNode<T>(t_data);
            // cout<<1<<endl;
            inputPreOrd(in, sub_tree->l_child);
            // cout<<2<<endl;
            inputPreOrd(in, sub_tree->r_child);
            // cout<<3<<endl;
            if (sub_tree->l_child != NULL) {
                sub_tree->l_child->parent = sub_tree;
            }
            if (sub_tree->r_child != NULL) {
                sub_tree->r_child->parent = sub_tree;
            }
        }
        else {
            sub_tree = NULL;
        }
    }
    
}

template<class T>
TriLLNode<T>* LLBinaryTree<T>::inputPreAndMid(T* vlr, T* lvr, int n) {
    if (n == 0) {
        return NULL;
    }
    int k = 0;
    while (vlr[0] != lvr[k]) {
        k++;
    }
    TriLLNode<T>* t = new TriLLNode<T>(vlr[0]);
    t->l_child = inputPreAndMid(vlr+1, lvr, k);
    t->r_child = inputPreAndMid(vlr+k+1, lvr+k+1, n-k-1);
    root = t;
    return t;
}

template<class T>
void LLBinaryTree<T>::outputMidOrd(TriLLNode<T>* sub_tree) {
    if (sub_tree != NULL) {
        T node_data = sub_tree->data;
        outputMidOrd(sub_tree->l_child);
        cout<<node_data;
        outputMidOrd(sub_tree->r_child);
    }
}


template<class T>
void LLBinaryTree<T>::outputTaiOrd(TriLLNode<T>* sub_tree) {
    if (sub_tree != NULL) {
        T node_data = sub_tree->data;
        outputTaiOrd(sub_tree->l_child);
        outputTaiOrd(sub_tree->r_child);
        cout<<node_data;
    }
}


template<class T>
int LLBinaryTree<T>::getLeafNum(TriLLNode<T>* sub_tree) {
    if (sub_tree == NULL) {
        return 0;
    }
    if (sub_tree->l_child == NULL
    && sub_tree->r_child == NULL) {
        return 1;
    }
    else {
        return getLeafNum(sub_tree->l_child)+getLeafNum(sub_tree->r_child);
    }
}

template<class T>
TriLLNode<T>* LLBinaryTree<T>::getHead() {
    return root;
}

#endif
