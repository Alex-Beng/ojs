/*
ABD##EH###CF#I##G##
*/

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
    int getLeafNum(TriLLNode<T>* sub_tree);
    TriLLNode<T>* getHead();
private:
    TriLLNode<T>* root;
};

int main(int argc, char const *argv[]) {
    LLBinaryTree<char> llbt;
    string in_str;
    stringstream in_ss;
    cin>>in_str;
    in_ss<<in_str;
    TriLLNode<char>* yayaya = llbt.getHead();
    llbt.inputPreOrd(in_ss, yayaya);
    cout<<llbt.getLeafNum(yayaya)<<endl;

    return 0;
}



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
