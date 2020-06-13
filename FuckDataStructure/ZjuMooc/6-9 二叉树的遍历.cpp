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
void InorderTraversal( BinTree BT );
void PreorderTraversal( BinTree BT );
void PostorderTraversal( BinTree BT );
void LevelorderTraversal( BinTree BT );

int main()
{
    BinTree BT = CreatBinTree();
    printf("Inorder:");    InorderTraversal(BT);    printf("\n");
    printf("Preorder:");   PreorderTraversal(BT);   printf("\n");
    printf("Postorder:");  PostorderTraversal(BT);  printf("\n");
    printf("Levelorder:"); LevelorderTraversal(BT); printf("\n");
    return 0;
}

/* 你的代码将被嵌在这里 */
// 中序
void InorderTraversal( BinTree BT ) {
    if (!BT) {
        return;
    }
    if (BT->Left)
        InorderTraversal(BT->Left);
    printf(" %c", BT->Data);
    if (BT->Right)
        InorderTraversal(BT->Right);
}
// 前序
void PreorderTraversal( BinTree BT ) {
    if (!BT) {
        return;
    }
    printf(" %c", BT->Data);
    if (BT->Left)
        PreorderTraversal(BT->Left);
    if (BT->Right)
        PreorderTraversal(BT->Right);
}
// 后序
void PostorderTraversal( BinTree BT ) {
    if (!BT) {
        return;
    }
    if (BT->Left)
        PostorderTraversal(BT->Left);
    if (BT->Right)
        PostorderTraversal(BT->Right);
    printf(" %c", BT->Data);
}
// 利用队列水平
void LevelorderTraversal( BinTree BT ) {
    if (!BT) {
        return;
    }
    BinTree datas[2333];
    int left = 0;
    int right = 0;
    datas[right++] = BT;
    while (left < right) {
        BinTree t_node = datas[left++];
        printf(" %c", t_node->Data);
        
        if (t_node->Left)
            datas[right++] = t_node->Left;
        if (t_node->Right)
            datas[right++] = t_node->Right;
    }
    
}
