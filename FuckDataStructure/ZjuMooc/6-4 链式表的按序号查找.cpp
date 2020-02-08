#include <iostream>
using namespace std;

#include <stdio.h>
#include <stdlib.h>

#define ERROR -1
typedef int ElementType;
typedef struct LNode *PtrToLNode;
struct LNode {
    ElementType Data;
    PtrToLNode Next;
};
typedef PtrToLNode List;

List Read(); /* 细节在此不表 */

ElementType FindKth( List L, int K );

int main()
{
    int N, K;
    ElementType X;
    List L = Read();
    scanf("%d", &N);
    while ( N-- ) {
        scanf("%d", &K);
        X = FindKth(L, K);
        if ( X!= ERROR )
            printf("%d ", X);
        else
            printf("NA ");
    }
    return 0;
}

List Read() {
    List head = NULL;
    List t_ptr = head;
    int t;
    while (cin>>t) {
        if (t == -1) {
            break;
        }
        List t_node = new LNode;
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


/* 你的代码将被嵌在这里 */
ElementType FindKth( List L, int K ) {
    if (!L || K<=0) {
        return ERROR;
    }
    for (int i=0; i<K-1; i++) {
        if (L->Next != NULL) {
            L = L->Next;
        }
        else {
            L = NULL;
            return ERROR;
        }
        
    }
    return L->Data;
}