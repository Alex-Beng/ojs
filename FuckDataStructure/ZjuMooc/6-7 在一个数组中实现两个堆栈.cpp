#include <iostream>
using namespace std;
#include <stdio.h>
#include <stdlib.h>

#define ERROR 1e8
typedef int ElementType;
typedef enum { push, pop, end } Operation;
// typedef enum { false, true } bool;
typedef int Position;
struct SNode {
    ElementType *Data;
    Position Top1, Top2;
    int MaxSize;
};
typedef struct SNode *Stack;

Stack CreateStack( int MaxSize );
bool Push( Stack S, ElementType X, int Tag );
ElementType Pop( Stack S, int Tag );

Operation GetOp();  /* details omitted */
void PrintStack( Stack S, int Tag ); /* details omitted */

int main()
{
    int N, Tag, X;
    Stack S;
    int done = 0;

    scanf("%d", &N);
    S = CreateStack(N);
    while ( !done ) {
        switch( GetOp() ) {
        case push: 
            scanf("%d %d", &Tag, &X);
            if (!Push(S, X, Tag)) printf("Stack %d is Full!\n", Tag);
            break;
        case pop:
            scanf("%d", &Tag);
            X = Pop(S, Tag);
            if ( X==ERROR ) printf("Stack %d is Empty!\n", Tag);
            break;
        case end:
            PrintStack(S, 1);
            PrintStack(S, 2);
            done = 1;
            break;
        }
        cout<<endl;
        PrintStack(S, 1);
        PrintStack(S, 2);
        cout<<endl;
    }
    return 0;
}

Operation GetOp() {
    string t_str;
    cin>>t_str;
    if (t_str == "Push") {
        return push;
    }
    else if (t_str == "Pop") {
        return pop;
    }
    else {
        return end;
    }
    
}
void PrintStack( Stack S, int Tag ) {
    if (Tag == 1) {
        for (int i=0; i<=S->Top1; i++) {
            cout<<S->Data[i]<<' ';
        }
        cout<<endl;
    }
    else if (Tag == 2) {
        for (int i=S->MaxSize-1; i>=S->Top2; i--) {
            cout<<S->Data[i]<<' ';
        }
        cout<<endl;
    }
}

/* 你的代码将被嵌在这里 */
Stack CreateStack( int MaxSize ) {
    Stack t_sk = (Stack)malloc(sizeof(struct SNode));
    t_sk->Data = (ElementType*)malloc(MaxSize*sizeof(ElementType));
    t_sk->MaxSize = MaxSize;
    t_sk->Top1 = -1;
    t_sk->Top2 = MaxSize;
    return t_sk;
}
bool Push( Stack S, ElementType X, int Tag ) {
    if (Tag == 1) {
        if (S->Top1 < S->Top2-1) {
            S->Data[++S->Top1] = X;
            return true;
        }
        else {
            printf("Stack Full\n");
            return false; 
        }
    }
    else if (Tag == 2) {
        if (S->Top2 > S->Top1+1) {
            S->Data[--S->Top2] = X;
            return true;
        }
        else {
            printf("Stack Full\n");
            return false; 
        }
    }
}
ElementType Pop( Stack S, int Tag ) {
    if (Tag == 1) {
        if (S->Top1 >= 0) {
            return S->Data[S->Top1--];
        }
        else {
            printf("Stack %d Empty\n", Tag);
            return ERROR;
        }
    }
    else if (Tag == 2) {
        if (S->Top2 <= S->MaxSize-1) {
            return S->Data[S->Top2++];
        }
        else { 
            printf("Stack %d Empty\n", Tag);
            return ERROR;
        }
    }
}

