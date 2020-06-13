/*
12 8 4 -1 -1 10 -1 -1 16 13 -1 -1 18 -1 -1
10 17 
6 
12
*/
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

    // 查找上下限之间的结点, 注意是用中序搜索
    void Search(TriLLNode<T>* sub_tree, T min, T max, T* &result, int& result_count);
    bool Search(TriLLNode<T>* sub_tree, T s_value);
    void Insert(TriLLNode<T>* &sub_tree, T in_value);
    void Remove(TriLLNode<T>* &sub_tree, T rm_value);
public:
    int len;
    stringstream out_ss;
private:
    TriLLNode<T>* root;
};

int main(int argc, char const *argv[]) {
    LLBinarySearchTree<int> llbst;
    string in_str;
    std::getline(std::cin, in_str);
    // cout<<in_str<<endl;
    stringstream in_ss;
    in_ss<<in_str;

    TriLLNode<int>* yayaya = llbst.getHead();
    llbst.inputPreOrd(in_ss, yayaya);

    int* result;
    result = new int[llbst.len+1];
    int cnt = 0;
    int min;
    int max;
    cin>>min>>max;
    llbst.Search(yayaya, min, max, result, cnt);
    for (int i=0; i<cnt; i++) {
        cout<<result[i];
        if (i != cnt-1) {
            cout<<' ';
        }
    }
    cout<<endl;

    int in_value;
    cin>>in_value;
    llbst.Insert(yayaya, in_value);
    llbst.out_ss.str("");
    llbst.outputMidOrd(yayaya);
    cout<<llbst.out_ss.str().substr(0, llbst.out_ss.str().length()-1)<<endl;

    int rm_value;
    cin>>rm_value;
    llbst.Remove(yayaya, rm_value);
    llbst.out_ss.str("");
    llbst.outputMidOrd(yayaya);
    cout<<llbst.out_ss.str().substr(0, llbst.out_ss.str().length()-1);

    return 0;
}




template<class T>
LLBinarySearchTree<T>::LLBinarySearchTree() {
    root = NULL;    
    len = 0;
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
            len++;
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
        out_ss<<node_data<<' ';
        outputMidOrd(sub_tree->r_child);
    }
}


template<class T>
void LLBinarySearchTree<T>::outputTaiOrd(TriLLNode<T>* sub_tree) {
    if (sub_tree != NULL) {
        T node_data = sub_tree->data;
        outputTaiOrd(sub_tree->l_child);
        outputTaiOrd(sub_tree->r_child);
        cout<<node_data<<' ';
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

template<class T>
void LLBinarySearchTree<T>::Search(TriLLNode<T>* sub_tree, T min, T max, T* &result, int& result_count) {
    if (sub_tree == NULL) {// 来到一个空子树，再见了您那
        return;
    }
    else {
        Search(sub_tree->l_child, min, max, result, result_count);
        if (min<sub_tree->data && sub_tree->data<max) {
            result[result_count++] = sub_tree->data;
        }
        Search(sub_tree->r_child, min, max, result, result_count);
    }
}

template<class T>
bool LLBinarySearchTree<T>::Search(TriLLNode<T>* sub_tree, T s_value) {
    T* t_result;
    int cnt;
    t_result = new T[233];
    Search(sub_tree, s_value, s_value, t_result, cnt);
    if (cnt >= 1) {
        return true;
    }
    else {
        return false;
    }
}

template<class T>
void LLBinarySearchTree<T>::Insert(TriLLNode<T>* &sub_tree, T in_value) {
    if (sub_tree == NULL) {// 插它插它
        sub_tree = new TriLLNode<T>(in_value);
    }
    else if (in_value < sub_tree->data) {
        Insert(sub_tree->l_child, in_value);
    }
    else if (in_value > sub_tree->data) {
        Insert(sub_tree->r_child, in_value);
    }
}

template<class T>
void LLBinarySearchTree<T>::Remove(TriLLNode<T>* &sub_tree, T rm_value) {
    TriLLNode<T>* t_ptr;
    if(sub_tree != NULL) {
        if (rm_value < sub_tree->data) {
            Remove(sub_tree->l_child, rm_value);
        }
        else if (rm_value > sub_tree->data){
            Remove(sub_tree->r_child, rm_value);
        }
        else {// 就是你，我删我删我删死你
            if (sub_tree->l_child!=NULL && sub_tree->r_child!=NULL) {
                t_ptr = sub_tree->r_child;  // 右子树找中序的第一个节点（排序树性质，中序是大小有序的）
                while (t_ptr->l_child != NULL) {
                    t_ptr = t_ptr->l_child;
                }
                sub_tree->data = t_ptr->data;
                Remove(sub_tree->r_child, sub_tree->data);
            }
            else {
                t_ptr = sub_tree;
                if (sub_tree->l_child == NULL) {
                    sub_tree = sub_tree->r_child;
                }
                else {
                    sub_tree = sub_tree->l_child;
                }
                delete t_ptr;
            }
        }
    }
}