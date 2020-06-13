#include <iostream>
using namespace std;

#include <stdio.h>
#include <stdlib.h>

#define ERROR NULL
// typedef enum {false, true} bool;
typedef int ElementType;
typedef struct LNode *PtrToLNode;
struct LNode {
    ElementType Data;
    PtrToLNode Next;
};
typedef PtrToLNode Position;
typedef PtrToLNode List;

List MakeEmpty(); 
Position Find( List L, ElementType X );
bool Insert( List L, ElementType X, Position P );
bool Delete( List L, Position P );

int main()
{
    List L;
    ElementType X;
    Position P;
    int N;
    bool flag;

    L = MakeEmpty();
    scanf("%d", &N);
    while ( N-- ) {
        scanf("%d", &X);
        flag = Insert(L, X, L->Next);
        if ( flag==false ) printf("Wrong Answer\n");
    }
    scanf("%d", &N);
    while ( N-- ) {
        scanf("%d", &X);
        P = Find(L, X);
        if ( P == ERROR )
            printf("Finding Error: %d is not in.\n", X);
        else {
            flag = Delete(L, P);
            printf("%d is found and deleted.\n", X);
            if ( flag==false )
                printf("Wrong Answer.\n");
        }
    }
    flag = Insert(L, X, NULL);
    if ( flag==false ) printf("Wrong Answer\n");
    else
        printf("%d is inserted as the last element.\n", X);
    P = (Position)malloc(sizeof(struct LNode));
    flag = Insert(L, X, P);
    if ( flag==true ) printf("Wrong Answer\n");
    flag = Delete(L, P);
    if ( flag==true ) printf("Wrong Answer\n");
    for ( P=L->Next; P; P = P->Next ) printf("%d ", P->Data);
    return 0;
}
/* 你的代码将被嵌在这里 */
List MakeEmpty() {
    List t_node = (List)malloc(sizeof(struct LNode));
    t_node->Next = NULL;
    return t_node;
}

Position Find( List L, ElementType X ) {
    List t_ptr = L->Next;
    while (t_ptr != NULL) {
        if (t_ptr->Data == X) {
            return t_ptr;
        }
        t_ptr = t_ptr->Next;
    }
    return ERROR;
}

bool Insert( List L, ElementType X, Position P ) {
    List t_ptr = L;
    do {
        if (t_ptr->Next == P) {
            List t_node = (List)malloc(sizeof(struct LNode));
            t_node->Data = X;

            t_node->Next = P;
            t_ptr->Next = t_node;
            return true;
        }
        t_ptr = t_ptr->Next;
    } while (t_ptr != NULL);
    
    printf("Wrong Position for Insertion\n");
    return false;
}

bool Delete( List L, Position P ) {
    if (!P) {
        printf("Wrong Position for Deletion\n");
        return false;
    }
    List pre_ptr = L;
    List t_ptr = L->Next;
    while (t_ptr != NULL) {
        if (t_ptr == P) {
            List del_ptr = t_ptr;
            pre_ptr->Next = del_ptr->Next;   
            return true;
        }
                    
        pre_ptr = pre_ptr->Next;
        t_ptr = t_ptr->Next;
    }
    printf("Wrong Position for Deletion\n");
    return false;
}