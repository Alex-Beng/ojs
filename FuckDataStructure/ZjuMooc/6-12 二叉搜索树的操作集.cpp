#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct TNode *Position;
typedef Position BinTree;
struct TNode{
    ElementType Data;
    BinTree Left;
    BinTree Right;
};

void PreorderTraversal( BinTree BT ); /* 先序遍历，由裁判实现，细节不表 */
void InorderTraversal( BinTree BT );  /* 中序遍历，由裁判实现，细节不表 */

BinTree Insert( BinTree BST, ElementType X );
BinTree Delete( BinTree BST, ElementType X );
Position Find( BinTree BST, ElementType X );
Position FindMin( BinTree BST );
Position FindMax( BinTree BST );

int main()
{
    BinTree BST, MinP, MaxP, Tmp;
    ElementType X;
    int N, i;

    BST = NULL;
    scanf("%d", &N);
    for ( i=0; i<N; i++ ) {
        scanf("%d", &X);
        BST = Insert(BST, X);
    }
    printf("Preorder:"); PreorderTraversal(BST); printf("\n");
    MinP = FindMin(BST);
    MaxP = FindMax(BST);
    scanf("%d", &N);
    for( i=0; i<N; i++ ) {
        scanf("%d", &X);
        Tmp = Find(BST, X);
        if (Tmp == NULL) printf("%d is not found\n", X);
        else {
            printf("%d is found\n", Tmp->Data);
            if (Tmp==MinP) printf("%d is the smallest key\n", Tmp->Data);
            if (Tmp==MaxP) printf("%d is the largest key\n", Tmp->Data);
        }
    }
    scanf("%d", &N);
    for( i=0; i<N; i++ ) {
        scanf("%d", &X);
        BST = Delete(BST, X);
    }
    printf("Inorder:"); InorderTraversal(BST); printf("\n");

    return 0;
}

void PreorderTraversal( BinTree BT ) {
    if (!BT) {
        return;
    }
    printf(" %d", BT->Data);
    if (BT->Left)
        PreorderTraversal(BT->Left);
    if (BT->Right)
        PreorderTraversal(BT->Right);

}
void InorderTraversal( BinTree BT ) {
    if (!BT) {
        return;
    }
    if (BT->Left)
        InorderTraversal(BT->Left);
    printf(" %d", BT->Data);
    if (BT->Right)
        InorderTraversal(BT->Right);

}
/* 你的代码将被嵌在这里 */
BinTree Insert( BinTree BST, ElementType X ) {
    BinTree inser_node = (BinTree)malloc(sizeof(struct TNode));
    inser_node->Data = X;
    inser_node->Left = NULL;
    inser_node->Right = NULL;
    if (!BST) {
        return inser_node;
    }

    BinTree pare_node = NULL;
    BinTree t_node = BST;
    while (t_node != NULL) {
        pare_node = t_node;
        if (X < t_node->Data) {
            t_node = t_node->Left;
        }
        else {
            t_node = t_node->Right;
        }
    }
    if (X < pare_node->Data) {
        pare_node->Left = inser_node;
    }
    else {
        pare_node->Right = inser_node;   
    }
    return BST;
}

// // 将BST树上的u替换为v
// void Transplant( BinTree BST, BinTree u, BinTree v, BinTree u_parent) {
//     if (u == BST) {// 想不到吧，👴就是根节点
//         BST = v;
//     }

//     if (u_parent->Left == u) {// u是左儿子
//         u_parent->Left = v;
//     }
//     else { // u是右儿子
//         u_parent->Right = v;
//     }
// }

BinTree Delete( BinTree BST, ElementType X ) {
    if (!BST) {
        printf("Not Found\n");
    }
    else {
        if (X < BST->Data) {
            BST->Left = Delete(BST->Left, X);// 递归删除
        }
        else if (X > BST->Data) {
            BST->Right = Delete(BST->Right, X);
        }
        else {// 删他
            if (BST->Left && BST->Right) {// 儿孙满堂
                BinTree t_node = FindMin(BST->Right);
                BST->Data = t_node->Data;
                BST->Right = Delete(BST->Right, t_node->Data);
            }
            else {
                BinTree t_node = BST;
                if (!BST->Left) {
                    BST = BST->Right;
                }
                else if (!BST->Right) {
                    BST = BST->Left;
                }
                free(t_node);
            }
        }
    }
    return BST;
    // if (!X_node) {
    //     printf("Not Found\n");
    //     return BST;
    // }
    // // find X node && its father 
    // // BinTree X_node = Find(BST, X);
    // BinTree X_node = BST;
    // BinTree X_father = NULL;
    // while (X_node != NULL && X_node->Data != X) {
    //     if (X < X_node->Data) {
    //         if (!X_father) {
    //             X_father = X_node;
    //         }
    //         X_node = X_node->Left;
    //     }
    //     else {
    //         if (!X_father) {
    //             X_father = X_node;
    //         }
    //         X_node = X_node->Right;
    //     }
    //     if (!X_father) {
    //         X_father = BST;
    //     }
    // }

    // if (X_node->Left == NULL) {
    //     Transplant(BST, X_node, X_node->Right, X_father);
    // }
    // else if (X_node->Right == NULL) {
    //     Transplant(BST, X_node, X_node->Left, X_father);
    // }
    // else {
    //     // find x_min && its father 
    //     // BinTree X_min = FindMin(X_node->Right);
    //     BinTree X_min = BST;
    //     BinTree X_min_father = NULL;
    //     while (X_min->Right != NULL) {
    //         X_min_father = X_min;
    //         X_min = X_min->Right;
    //     }

    //     if (X_node->Left != X_min) {
    //         Transplant(BST, X_min, X_min->Left, X_min_father);
    //         X_min->Right = X_node->Right;
    //     }
    //     Transplant(BST, X_node, X_min, X_father);
    //     X_min->Left = X_node->Left;
    // }
    // return BST;
}
Position Find( BinTree BST, ElementType X ) {
    while (BST != NULL && BST->Data != X) {
        if (X < BST->Data) {
            BST = BST->Left;
        }
        else {
            BST = BST->Right;
        }
    }
    return BST; // None is NULL
}
Position FindMin( BinTree BST ) {
    if (!BST) {
        return NULL;
    }
    while (BST->Left != NULL) {
        BST = BST->Left;
    }
    return BST;
}
Position FindMax( BinTree BST ) {
    if (!BST) {
        return NULL;
    }
    while (BST->Right != NULL) {
        BST = BST->Right;
    }
    return BST;
}
