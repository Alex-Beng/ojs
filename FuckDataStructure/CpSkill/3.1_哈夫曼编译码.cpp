/**
5
a b c d e 12 40 15 8 25
 * */


#include <string>
#include <iostream>
using namespace std;


class data {
public:
    int c;
    int w;
    bool operator >=(data& r) {return w <= r.w;}
    bool operator >(data& r) {return w > r.w;}
};


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

typedef TreeNode<data>* HeapNode;

class Heap {
    public:
    Heap(int size = 10) {
        max_heap_size = size;
        this->heap = new HeapNode[max_heap_size];
        currect_size = 0;
    }
    ~Heap() {
        delete [] heap;
    }
    bool Insert(TreeNode<data>* x) {
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

    HeapNode RemoveMin() {
        // cout<<heap[0].data<<endl;
        HeapNode x = heap[0];
        // cout<<"yayaya"<<heap[0].data<<endl;
        heap[0] = heap[currect_size-1];
        currect_size--;
        SiftDown(0, currect_size-1);
        // cout<<1<<endl;
        return x;
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
            cout<<heap[i]->data.c<<' ';
            if (i == t_sum) {
                cout<<endl;
                t_sum += a_i*2;
                a_i *= 2;
            }
        }
    }
private:
    HeapNode* heap;
    int currect_size;
    int max_heap_size;

    void SiftDown(int start, int m) {
        int i = start;
        int j = 2*i + 1;
        HeapNode t = heap[i];
        while (j <= m) {
            if (j < m && heap[j]->data.w > heap[j+1]->data.w) {
                j++;
            }

            if (t->data.w <= heap[j]->data.w) {
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
    void SiftUp(int start) {
        int j = start;
        int i = (j-1) / 2;
        HeapNode t = heap[j];
        while (j > 0) {
            if (heap[i]->data.w <= t->data.w) {
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
};

template<class T>
class HuffmanTree {
public:
    HuffmanTree(T* datas, int n);
    ~HuffmanTree();
    void output(TreeNode<T>* node);
public:
    int value_num;
    int* key_char;
    string* value_code;
    string present_code;

    TreeNode<T>* root;
    void Merge(TreeNode<T>* t1, TreeNode<T>* t2, TreeNode<T>* parent);
    void GetDict(TreeNode<T>* present_node);
};

template<class T>
HuffmanTree<T>::HuffmanTree(T* datas, int n) {
    present_code = "";
    value_num = n;
    // MinHeap<TreeNode<T>*> hp(value_num);
    Heap hp(value_num);
    key_char = new int[value_num];
    value_code = new string[value_num];

    TreeNode<T>* parent;
    TreeNode<T>* first;
    TreeNode<T>* second;
    TreeNode<T>* work;
    for (int i=0; i<n; i++) {
        key_char[i] = datas[i].c;

        work = new TreeNode<T>;
        work->data = datas[i];
        work->l_child = NULL;
        work->r_child = NULL;
        work->parent  = NULL;
        hp.Insert(work);
    }

    // hp.output();
    // cout<<endl;
    for (int i=0; i<n-1; i++) {
        parent = new TreeNode<T>;
        // cout<<"ya"<<i<<endl;
        first = hp.RemoveMin();
        second = hp.RemoveMin();
        // cout<<first->data<<' '<<secsond->data<<endl;
        Merge(first, second, parent);
        // cout<<parent->data<<endl;
        hp.Insert(parent);
        // cout<<endl;
        // hp.output();
    }
    root = parent;
}

template<class T>
HuffmanTree<T>::~HuffmanTree() {
    delete root;
}

template<class T>
void HuffmanTree<T>::Merge(TreeNode<T>* t1, TreeNode<T>* t2, TreeNode<T>* parent) {
    parent->l_child = t1;
    parent->r_child = t2;
    parent->data.w = t1->data.w + t2->data.w;
    parent->data.c = -1;
    t1->parent = parent; 
    t2->parent = parent;
}

template<class T>
void HuffmanTree<T>::output(TreeNode<T>* node) {
    if (node != NULL) {
        cout<<(char)node->data.c<<endl;
        if (node->l_child != NULL)
            output(node->l_child);
        if (node->r_child != NULL)
            output(node->r_child);
    }
}

template<class T>
void HuffmanTree<T>::GetDict(TreeNode<T>* present_node) {
    if (present_node != NULL) {
        if (present_node->data.c != -1) {

            for (int i=0; i<value_num; i++) {
                if (key_char[i] == present_node->data.c) {
                    value_code[i] = present_code;
                }
            }

        }
        if (present_node->l_child != NULL) {
            present_code += "0";
            GetDict(present_node->l_child);
            present_code = present_code.substr(0, present_code.length() - 1);;
        }
        if (present_node->r_child != NULL) {
            present_code += "1";
            GetDict(present_node->r_child);
            present_code = present_code.substr(0, present_code.length() - 1);;
        }
    }
}


int main(int argc, char const *argv[]) {
    int n;
    cin>>n;
    data dt[n];
    char t_c;
    for (int i=0; i<n; i++) {
        cin>>t_c;
        dt[i].c = (int)t_c;
    }
    for (int i=0; i<n; i++) {
        cin>>dt[i].w;
    }
    HuffmanTree<data> hfft(dt, n);
    // hfft.output(hfft.root);
    hfft.GetDict(hfft.root);
    for (int i=0; i<hfft.value_num; i++) {
        cout<<(char)hfft.key_char[i]<<' '<<hfft.value_code[i]<<endl;
    }
    // hfft.GetDict(key_char, value_code);
    return 0;
}

