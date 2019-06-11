/**
 * 链表储存的二叉排序树
 */
#ifndef LL_BINARY_SEARCH_TREE_H
#define LL_BINARY_SEARCH_TREE_H

#include "LLBinarySearchTree.h"

#include <string>
#include <sstream>
#include <iostream>
using namespace std;


template<class T>
class LLBinarySearchTree {
public:
    LLBinarySearchTree();
    ~LLBinarySearchTree();
    void inputPreOrd(stringstream& in, TriLLNode<T>* &sub_tree);
    TriLLNode<T>* inputPreAndMid(T* vlr, T* lvr, int n);
    void outputMidOrd(TriLLNode<T>* sub_tree);
    void outputTaiOrd(TriLLNode<T>* sub_tree);

    bool IsSearchTree(TriLLNode<T>* sub_tree);
    TriLLNode<T>* getHead();
    
private:
    TriLLNode<T>* root;
};

template<class T>
LLBinarySearchTree<T>::LLBinarySearchTree() {
    root = NULL;    
}

template<class T>
LLBinarySearchTree<T>::~LLBinarySearchTree() {
    ;
    // so fucking to destroy a tree
}


template<class T>
void LLBinarySearchTree<T>::inputPreOrd(stringstream& in, TriLLNode<T>* &sub_tree) {
    T t_data;
    if (!in.eof()) {
        in>>t_data;
        // cout<<t_data<<'c'<<endl;
        if (t_data != -1) {
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
TriLLNode<T>* LLBinarySearchTree<T>::inputPreAndMid(T* vlr, T* lvr, int n) {
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
void LLBinarySearchTree<T>::outputMidOrd(TriLLNode<T>* sub_tree) {
    if (sub_tree != NULL) {
        T node_data = sub_tree->data;
        outputMidOrd(sub_tree->l_child);
        cout<<node_data;
        outputMidOrd(sub_tree->r_child);
    }
}


template<class T>
void LLBinarySearchTree<T>::outputTaiOrd(TriLLNode<T>* sub_tree) {
    if (sub_tree != NULL) {
        T node_data = sub_tree->data;
        outputTaiOrd(sub_tree->l_child);
        outputTaiOrd(sub_tree->r_child);
        cout<<node_data;
    }
}

template<class T>
bool LLBinarySearchTree<T>::IsSearchTree(TriLLNode<T>* sub_tree) {
    if (sub_tree != NULL) {
        bool this_is = false;
        if ( (sub_tree->l_child != NULL && sub_tree->l_child->data < sub_tree->data || sub_tree->l_child == NULL)
        &&   (sub_tree->r_child != NULL && sub_tree->r_child->data > sub_tree->data || sub_tree->r_child == NULL) ) {
            this_is = true;
        }
        bool l_is = IsSearchTree(sub_tree->l_child);
        bool r_is = IsSearchTree(sub_tree->r_child);
        if (l_is && r_is && this_is) {
            return true;
        }
        else {
            return false;
        }
    }
    else {
        return true;
    }
}

template<class T>
TriLLNode<T>* LLBinarySearchTree<T>::getHead() {
    return root;
}

#endif
