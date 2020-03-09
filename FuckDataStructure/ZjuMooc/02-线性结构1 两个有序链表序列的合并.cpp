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
void Print( List L ); /* 细节在此不表；空链表将输出NULL */

List Merge( List L1, List L2 );

int main()
{
    List L1, L2, L;
    L1 = Read();
    L2 = Read();
    L = Merge(L1, L2);
    Print(L);
    Print(L1);
    Print(L2);
    return 0;
}

List Read() {
    int n;
    cin>>n;
    List head = new Node;
    List t_ptr = head;
    int t;
    for (int i=0; i<n; i++) {
        cin>>t;
        List t_node = new Node;
        t_node->Data = t;
        t_ptr->Next = t_node;
        t_ptr = t_node;
    }
    t_ptr->Next = NULL;
    return head;
}

void Print( List L ) {
    List t_ptr = L->Next;
    while (t_ptr != NULL) {
        cout<<t_ptr->Data<<' ';
        t_ptr = t_ptr->Next;
    }
    cout<<endl;
    
}

/* 你的代码将被嵌在这里 */
List Merge( List L1, List L2 ) {
    List head_1 = L1->Next;
    List head_2 = L2->Next;

    // List result = new Node;
    List result = (List)malloc(sizeof(struct Node));
    List res_ptr = result;

    while (head_1 && head_2) {
        if (head_1->Data > head_2->Data) {
            res_ptr->Next = head_2;

            head_2 = head_2->Next;
            res_ptr = res_ptr->Next;
        }
        else {
            res_ptr->Next = head_1;

            head_1 = head_1->Next;
            res_ptr = res_ptr->Next;
        }
    }
    
    while (head_1!=NULL) {
        res_ptr->Next = head_1;

        head_1 = head_1->Next;
        res_ptr = res_ptr->Next;
    }
    while (head_2!=NULL) {
        res_ptr->Next = head_2;

        head_2 = head_2->Next;
        res_ptr = res_ptr->Next;
    }

    L1->Next = NULL;
    L2->Next = NULL;

    return result;
}
