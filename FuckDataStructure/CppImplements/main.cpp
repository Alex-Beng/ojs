// #include "SeqList.h"
// #include "SingleLinkList.h"
// #include "CircularLinkList.h"
// #include "Stack.h"
// #include "Queue.h"
// #include "DoublyLinkList.h"
// #include "TripleSparseMat.h"
// #include "CrossSparseMat.h"
// #include "GenList.h"
// #include "MinHeap.h"
// #include "HuffmanTree.h"
// #include "Heap_v2.h"
// #include "LLBinaryTree.h"
// #include "LLBinarySearchTree.h"
// #include <cstring>
#include "CrossSparseMat_v2.h"


int main(int argc, char const *argv[]) {
    int m, n;
    int t1, t2;
    cin>>m>>n>>t1>>t2;
    CrossSparseMat<int> m1(m, n);
    CrossSparseMat<int> m2(m, n);

    m1.input(t1);
    m2.input(t2);

    // cout<<endl;
    // m1.output();
    // cout<<endl;
    // m2.output();
    // cout<<endl;

    m1.Add(m2);
    m1.output();

    // LLBinarySearchTree<int> llbst;
    // string in_str;
    // std::getline(std::cin, in_str);
    // // cout<<in_str<<endl;
    // stringstream in_ss;
    // in_ss<<in_str;

    // TriLLNode<int>* yayaya = llbst.getHead();
    // llbst.inputPreOrd(in_ss, yayaya);

    // // LLBinarySearchTree<int> llbst2;
    // string in_str2;
    // std::getline(std::cin, in_str2);
    // // cout<<in_str<<endl;
    // stringstream in_ss2;
    // in_ss2<<in_str2;

    // int t;
    // while (!in_ss2.eof()) {
    //     in_ss2>>t;
    //     if (t != -1) {
    //         llbst.Insert(yayaya, t);
    //     }        
    // }
    // llbst.outputMidOrd(yayaya);
    // cout<<endl;

    // llbst.outputMidOrd(yayaya);

    // int* result;
    // result = new int[10];
    // int cnt = 0;
    // llbst.Search(yayaya, 10, 17, result, cnt);
    // for (int i=0; i<cnt; i++) {
    //     cout<<result[i]<<' ';
    // }
    // cout<<endl;

    // llbst.Insert(yayaya, 3);
    // llbst.Insert(yayaya, 3);
    // llbst.Insert(yayaya, 19);
    // llbst.Insert(yayaya, 18);
    // llbst.outputMidOrd(yayaya);
    // cout<<endl;

    // llbst.Remove(yayaya, 10);
    // llbst.Remove(yayaya, 3);
    // llbst.outputMidOrd(yayaya);




    // llbst.outputTaiOrd(yayaya);
    // if (llbst.IsSearchTree(yayaya)) {
    //     cout<<"yes"<<endl;
    // }
    // else {
    //     cout<<"no"<<endl;
    // }

    // LLBinaryTree<char> llbt;
    // // string in_str;
    // // stringstream in_ss;
    // // cin>>in_str;
    // // in_ss<<in_str;
    // // TriLLNode<char>* yayaya = llbt.getHead();
    // // llbt.inputPreOrd(in_ss, yayaya);
    // // cout<<llbt.getLeafNum(yayaya)<<endl;

    // char vlr[233];
    // char lvr[233];
    // cin>>vlr;
    // cin>>lvr;
    // llbt.inputPreAndMid(vlr, lvr, strlen(vlr));
    // TriLLNode<char>* yayaya = llbt.getHead();
    // llbt.outputTaiOrd(yayaya);
    // Heap hp(20);
    // HeapNode t;

    // t.data = 1;
    // hp.Insert(t);

    // t.data = 5;
    // hp.Insert(t);

    // t.data = 2;
    // hp.Insert(t);

    // t.data = 7;
    // hp.Insert(t);

    // t.data = 9;
    // hp.Insert(t);

    // t.data = 90;
    // hp.Insert(t);

    // t.data = 2;
    // hp.Insert(t);

    // t.data = 4;
    // hp.Insert(t);

    // t.data = 3;
    // hp.Insert(t);

    // for (int i=0; i<hp.current_size; i++) {
    //     cout<<hp.heap[i].data<<' ';
    // }
    // cout<<endl;

    // hp.RemoveMin();

    // for (int i=0; i<hp.current_size; i++) {
    //     cout<<hp.heap[i].data<<' ';
    // }

    // return 0;

    // MinHeap<int> t;
    // t.Insert(9);
    // t.Insert(23);
    // t.Insert(78);
    // t.Insert(45);
    // t.Insert(87);
    // t.Insert(53);
    // t.Insert(31);
    // t.Insert(17);
    // t.Insert(65);
    // t.output();
    // int ttt;
    // t.RemoveMin(ttt);
    // cout<<endl;
    // t.output();
    // cout<<endl<<ttt<<endl;

    // int nums[5] = {4, 6, 9, 666, 233};
    // HuffmanTree<int> hfft(nums, 5);
    // hfft.output(hfft.root);
    // cout<<hfft.root->data<<endl
    //     <<hfft.root->l_child->data<<' '<<hfft.root->r_child->data<<endl;
    // if (hfft.root->l_child->l_child == NULL && hfft.root->l_child->r_child == NULL) {
    //     cout<<"yayaya"<<endl;
    // }
    return 0;

    // GenList<int> gl;    
    // GListNode<int>* head = gl.getHead();

    // char str[100];
    // cin>>str;

    // gl.input(str, head);
    // // cout<<gl.Lenght(gl.getHead());
    //     cout<<' '<<gl.Depth(gl.getHead())<<endl;
    // return 0;

    // CrossSparseMat<int> csm(2, 2, 2);
    // CrossSparseMat<int> csm2(2, 2, 2);
    // csm.input(2);
    // csm2.input(2);
    // csm.output();

    // csm.Add(csm2);
    // csm.output();
    // return 0;

    // TripleSparseMat<int> tsm;
    // tsm.input();
    // // tsm.output();
    // tsm.t();
    // tsm.output();
    // return 0;



    // DoublyLinkList<int> dll;
    // dll.PushBack(2);
    // for (int i=0; i<10; i++) {
    //     dll.PushBack(0);
    // }
    // dll.output();
    
    // for (LinkNode<int>* tail = dll.getEnd(); tail != dll.getHead(); tail = tail->former) {
    //     tail->data += 1;
    // }
    // dll.output();

    // LinkNode<int>* it = dll.getHead();
    // it = it->next;
    // for (; it != NULL; it = it->next) {
    //     it->data+=7;
    // }
    // dll.output();


    // Queue<int> qrq(5);
    // int n, ttt;
    // cin>>n;
    // for (int i=0; i<n; i++) {
    //     cin>>ttt;
    //     if (qrq.Push(ttt)) {
    //         ;
    //     }
    //     else {
    //         cout<<"No"<<endl;
    //     }
    // }
    // while (!qrq.Empty()) {
    //     cout<<qrq.Pop()<<endl;
    // }
    // int t = 233;
    // // CircularLinkList<int> cll;
    // // cll.input();
    // // cll.PushBack(666);
    // // cll.output();

    // Stack<int> sk;
    // for(int i=0; i<7; i++) {
    //     cin>>t;
    //     sk.Push(t);
    //     cout<<sk.Top();
    // }
    // cout<<sk.Size()<<endl;
    // for (int i=0; i<7; i++) {
    //     cout<<sk.Pop()<<endl;
    // }

    // cout<<(int)'['<<(char)92<<' '<<(int)']'<<endl;
    // cout<<(int)'('<<' '<<(int)')'<<endl;
    // cout<<(int)'{'<<(char)124<<' '<<(int)'}'<<endl;
    // return 0;
}
