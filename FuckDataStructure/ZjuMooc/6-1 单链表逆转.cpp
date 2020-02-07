#include <iostream>
using namespace std;

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
    ElementType Data;
    PtrToNode   Next;
};
typedef PtrToNode List;

List Read(); /* 细节在此不表 */
void Print( List L ); /* 细节在此不表 */

List Reverse( List L );

int main()
{
    List L1, L2;
    L1 = Read();
    L2 = Reverse(L1);
    Print(L1);
    Print(L2);
    return 0;
}

List Read() {
    int n;
    cin>>n;
    List head = NULL;
    List t_ptr = head;
    int t;
    for (int i=0; i<n; i++) {
        cin>>t;
        List t_node = new Node;
        t_node->Data = t;
        if (!head) {
            head = t_node;
            t_ptr = head;
            continue;
        }
        t_ptr->Next = t_node;
        t_ptr = t_ptr->Next;
    }
    t_ptr->Next = NULL;
    return head;
}

void Print( List L ) {
    List t_ptr = L;
    while (t_ptr != NULL) {
        cout<<t_ptr->Data<<' ';
        t_ptr = t_ptr->Next;
    }
    cout<<endl;
    
}

/* 你的代码将被嵌在这里 */
List Reverse( List L ) {
    if (!L) {
        return NULL;
    }
    List t_ptr = L->Next;
    List head_ptr = L;
    List end_ptr = L;
    while (t_ptr != NULL) {
        // cout<<t_ptr->Data<<' ';
        List moving_node = t_ptr;

        t_ptr = t_ptr->Next;

        end_ptr->Next = moving_node->Next;
        moving_node->Next = head_ptr;
        head_ptr = moving_node;
        // try
        // {
        //     // Print(head_ptr);
        //     ;
        // }
        // catch(const std::exception& e)
        // {
        //     cout<<"ya"<<endl;
        //     std::cerr << e.what() << '\n';
        // }
    }
    // cout<<endl;
    // t_ptr->Next = NULL;
    // cout<<"ya"<<endl;
    //     Print(head_ptr);
    return head_ptr;
}
