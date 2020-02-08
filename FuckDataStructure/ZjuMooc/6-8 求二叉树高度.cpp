#include <stdio.h>
#include <stdlib.h>

typedef char ElementType;
typedef struct TNode *Position;
typedef Position BinTree;
struct TNode{
    ElementType Data;
    BinTree Left;
    BinTree Right;
};

BinTree CreatBinTree(); /* 实现细节忽略 */
int GetHeight( BinTree BT );

int main()
{
    BinTree BT = CreatBinTree();
    printf("%d\n", GetHeight(BT));
    return 0;
}

/* 你的代码将被嵌在这里 */
int GetHeight( BinTree BT ) {
    if (!BT) {
        return 0;
    }
    if (BT->Left!=NULL || BT->Right!=NULL) {
        int left_dep = GetHeight(BT->Left);
        int righ_dep = GetHeight(BT->Right);
        int fina_dep = left_dep>righ_dep ? left_dep:righ_dep;
        return fina_dep+1;
    }
    else {
        return 1;
    }
}