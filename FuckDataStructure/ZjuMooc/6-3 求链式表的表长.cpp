#include <iostream>
using namespace std;
#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct LNode *PtrToLNode;
struct LNode {
    ElementType Data;
    PtrToLNode Next;
};
typedef PtrToLNode List;

List Read(); /* 细节在此不表 */
void Print( List L );
int Length( List L );

int main()
{
    List L = Read();
    Print(L);
    printf("%d\n", Length(L));
    return 0;
}

/* 你的代码将被嵌在这里 */
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

int Length( List L ) {
    int len = 0;
    List t_ptr = L;
    while (t_ptr != NULL) {
        t_ptr = t_ptr->Next;
        len++;
    }
    return len;
}

void Print( List L ) {
    List t_ptr = L;
    while (t_ptr != NULL) {
        cout<<t_ptr->Data<<' ';
        t_ptr = t_ptr->Next;
    }
    cout<<endl;
    
}