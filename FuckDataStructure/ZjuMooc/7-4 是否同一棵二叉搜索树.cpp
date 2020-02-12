#include <iostream>
using namespace std;
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

void PreorderTraversal( BinTree BT ); 
void InorderTraversal( BinTree BT );  

BinTree Insert( BinTree BST, ElementType X );
bool Check( BinTree A, BinTree B );

int main() {
    int n;
    while (cin>>n && n) {
        int l;
        cin>>l;
        BinTree right_tree = NULL;
        BinTree check_trees[l];
        for (int i=0; i<n; i++) {
            int t;
            cin>>t;
            right_tree = Insert(right_tree, t);
        }
        for (int i=0; i<l; i++) {
            check_trees[i] = NULL;
            for (int j=0; j<n; j++) {
                int t;
                cin>>t;
                check_trees[i] = Insert(check_trees[i], t);
            }
        }
        // PreorderTraversal(right_tree);
        // InorderTraversal(right_tree);
        // printf("\n");
        // PreorderTraversal(check_trees[0]);
        // InorderTraversal(check_trees[0]);
        
        for (int i=0; i<l; i++) {
            if (Check(right_tree, check_trees[i])) {
                printf("Yes\n");
            }
            else {
                printf("No\n");
            }
        }
    }
    

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

bool Check( BinTree A, BinTree B ) {
    if (A && B) {// both not null
        if (A->Data == B->Data) {
            return Check(A->Left, B->Left)&Check(A->Right, B->Right);
        }
        else {
            return false;
        }
    }
    else if (!A && !B) {// both null
        return true;
    }
    else {// one null one not null
        return false;
    }
    
}