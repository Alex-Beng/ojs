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
    scanf("%d", &n);
    List head, end, t_node;
    head = (List)malloc(sizeof(struct Node));
    end = head;
    for (int i=0; i<n; i++) {
        t_node = (List)malloc(sizeof(struct Node));
        scanf("%d", &(t_node->Data));
        end->Next = t_node;
        end = t_node;
    }
    end->Next = NULL;
    return head;
}

void Print(List L) {
    while (L->Next != NULL) {
        L = L->Next;
        printf("%d ", L->Data);
    }
    return ;
}

List Reverse(List L) {
    List re_head, t_node, re_end, re_t_node;
    re_head = (List)malloc(sizeof(struct Node));
    re_end = re_head;

    int L_len = 0;
    List L_head = L;
    while (L_head->Next != NULL) {
        L_head = L_head->Next;
        L_len++;
    }

    for (int i=L_len; i>0; i--) {
        t_node = L;
        for (int j=0; j<i; j++) {
            t_node = t_node->Next;
        }

        re_t_node = (List)malloc(sizeof(struct Node));
        re_t_node->Data = t_node->Data;
        re_end->Next = re_t_node;
        re_end = re_t_node;
    }
    re_end->Next = NULL;
    return re_head;
}