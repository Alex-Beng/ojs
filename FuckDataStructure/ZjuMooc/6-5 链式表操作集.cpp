#include <iostream>
using namespace std;

#include <stdio.h>
#include <stdlib.h>

#define ERROR NULL
typedef int ElementType;
typedef struct LNode *PtrToLNode;
struct LNode {
    ElementType Data;
    PtrToLNode Next;
};
typedef PtrToLNode Position;
typedef PtrToLNode List;

Position Find( List L, ElementType X );
List Insert( List L, ElementType X, Position P );
List Delete( List L, Position P );

int main()
{
    List L;
    ElementType X;
    Position P, tmp;
    int N;

    L = NULL;
    scanf("%d", &N);
    while ( N-- ) {
        scanf("%d", &X);
        L = Insert(L, X, L);
        if ( L==ERROR ) printf("Wrong Answer\n");
    }
    scanf("%d", &N);
    while ( N-- ) {
        scanf("%d", &X);
        P = Find(L, X);
        if ( P == ERROR )
            printf("Finding Error: %d is not in.\n", X);
        else {
            L = Delete(L, P);
            printf("%d is found and deleted.\n", X);
            if ( L==ERROR )
                printf("Wrong Answer or Empty List.\n");
        }
    }
    L = Insert(L, X, NULL);
    if ( L==ERROR ) printf("Wrong Answer\n");
    else
        printf("%d is inserted as the last element.\n", X);
    P = (Position)malloc(sizeof(struct LNode));
    tmp = Insert(L, X, P);
    if ( tmp!=ERROR ) printf("Wrong Answer\n");
    tmp = Delete(L, P);
    if ( tmp!=ERROR ) printf("Wrong Answer\n");
    for ( P=L; P; P = P->Next ) printf("%d ", P->Data);
    return 0;
}

/* 你的代码将被嵌在这里 */

Position Find( List L, ElementType X ) {
    List t_ptr = L;
    while (t_ptr != NULL) {
        if (t_ptr->Data == X) {
            // printf("posi: %d \n", t_ptr->Data);
            return t_ptr;
        }
        t_ptr = t_ptr->Next;
    }
    return ERROR;
}
List Insert( List L, ElementType X, Position P ) {
    if (L == P) {
        List t_node = (List)malloc(sizeof(struct LNode));
        t_node->Data = X;

        t_node->Next = P;
        return t_node;
    }

    List t_ptr = L;
    while (t_ptr != NULL) {
        if (t_ptr->Next == P) {
            List t_node = (List)malloc(sizeof(struct LNode));
            t_node->Data = X;

            t_node->Next = P;
            t_ptr->Next = t_node;
            return L;
        }
        t_ptr = t_ptr->Next;
    }
    printf("Wrong Position for Insertion\n");
    return ERROR;
}
List Delete( List L, Position P ) {
    if (!P) {
        printf("Wrong Position for Deletion\n");
        return ERROR;
    }
    if (L == P) {
        return P->Next;
    }
    List pre_ptr = NULL;
    List t_ptr = L;
    while (t_ptr != NULL) {
        if (t_ptr == P) {
            List del_ptr = t_ptr;
            pre_ptr->Next = del_ptr->Next;   
            return L;
        }
        if (!pre_ptr) {
            pre_ptr = t_ptr;
        }
        else {
            pre_ptr = pre_ptr->Next;
        }
        
        t_ptr = t_ptr->Next;
    }
    printf("Wrong Position for Deletion\n");
    return ERROR;
}
