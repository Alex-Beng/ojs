#include <stdio.h>
#include <stdlib.h>
 
struct binaryTreeNode
{
    int num;
    struct binaryTreeNode *left;
    struct binaryTreeNode *right;
    struct binaryTreeNode *next;
    struct binaryTreeNode *before;
    struct binaryTreeNode *root;
};
 
struct binaryTree
{
    struct binaryTreeNode *root;
    struct binaryTreeNode *head;
    struct binaryTreeNode *end;
};
 
struct binaryTreeStack
{
    struct binaryTreeNode *L[100];
    int flag[100];
    int top ;
};
 
void run();
struct binaryTreeNode *createNewTree(struct binaryTreeNode *root);
struct binaryTreeNode *createNewNode();
void pushStack(struct binaryTreeNode *node);
void popStack();
void getTrackList();
int stackEmptyJudge();
struct binaryTreeNode *getNode(int num);
void putOutSection();
void cutInNode(int num);
void deletNode(int num);
void print();
 
struct binaryTree T;
struct binaryTreeStack S;
 
int main()
{
    run();
    return 0;
}
 
void run()
{
    int in, out;
    T.root = createNewTree(NULL);
    getTrackList();
    putOutSection();
    scanf("%d", &in);
    cutInNode(in);
    print();
    deletNode(in);
    scanf("%d", &out);
    deletNode(out);
    print();
}
 
struct binaryTreeNode *createNewTree(struct binaryTreeNode *root)
{
    int num;
    struct binaryTreeNode *cur;
    scanf("%d", &num);
    if (num == -1) return NULL;
    cur = createNewNode();
    cur->num = num;
    cur->left = createNewTree(cur);
    cur->right = createNewTree(cur);
    cur->root = root;
    return cur;
}
 
struct binaryTreeNode *createNewNode()
{
    struct binaryTreeNode *p;
    p = (struct binaryTreeNode *)malloc(sizeof(struct binaryTreeNode));
    p->num = 0;
    p->left = NULL;
    p->right = NULL;
    p->next = NULL;
    p->before = NULL;
    return p;
}
 
void pushStack(struct binaryTreeNode *node)
{
    ++(S.top);
    S.L[S.top] = node;
    S.flag[S.top] = 0;
}
 
void popStack()
{
    --(S.top);
}
 
void getTrackList()
{
    int i;
    struct binaryTreeNode *next;
    S.top = -1;
    pushStack(T.root);
    while(stackEmptyJudge())
    {
        next = NULL;
        switch(S.flag[S.top])
        {
            case 0 :
            {
                ++(S.flag[S.top]);
                if(S.L[S.top]->left) pushStack(S.L[S.top]->left);
                break;
            }
            case 1 :
            {
                ++(S.flag[S.top]);
                if(S.L[S.top]->right) pushStack(S.L[S.top]->right);
                break;
            }
            case 2 :
            {
                if(S.L[S.top]->right)
                {
                    next = S.L[S.top]->right;
                    while(next->left) next = next->left;
                }
                else
                {
                    i = S.top - 1;
                    while(i >= 0 && S.flag[i] == 2) i--;
                    if(i >= 0) next = S.L[i];
                }
                S.L[S.top]->next = next;
                if(next) next->before = S.L[S.top];
                popStack();
            }
        }
    }
    next = T.root;
    while(next->left) next = next->left;
    T.head = next;
    next->before = NULL;
    next = T.root;
    while(next->right) next = next->right;
    T.end = next;
    next->next = NULL;
}
 
int stackEmptyJudge()
{
    if(S.top == -1) return 0;
    return 1;
}
 
struct binaryTreeNode *getNode(int num)
{
    struct binaryTreeNode *p = T.root;
    while(1)
    {
        if(p->num == num) return p;
        if(p->num < num)
        {
            if(p->right) p = p->right;
            else return p;
        }
        else
        {
            if(p->left) p = p->left;
            else return p;
        }
    }
}
 
void putOutSection()
{
    int a, b;
    struct binaryTreeNode *p = T.head;
    scanf("%d%d", &a, &b);
    p = getNode(a);
    if(p->num <= a) p = p->next;
    while(p && p->num < b)
    {
        printf("%d ", p->num);
        p = p->next;
    }
    printf("\n");
}
 
void cutInNode(int num)
{
    struct binaryTreeNode *p = getNode(num), *newNode = createNewNode();
    newNode->num = num;
    newNode->root = p;
    if(num < p->num) p->left = newNode;
    else p->right = newNode;
    getTrackList();
}
 
void deletNode(int num)
{
    struct binaryTreeNode *p, *before, *next, *root;
    p = getNode(num);
    root = p->root;
    next = p->next;
    before = p->before;
    if(p->right == NULL && p->left == NULL)
    {
        if(root)
        {
            if(root->left == p) root->left = NULL;
            else root->right = NULL;
        }
        else T.root = NULL;
    }
    else
    {
        if(p->left && p->right)
        {
            if(p->right == next)
            {
                p->num = next->num;
                p->right = next->right;
            }
            else
            {
                 p->num = next->num;
                 next->root->left = next->right;
            }
        }
        else
        {
            if(p->right)
            {
                if(p->right == next)
                {
                    if(root)
                    {
                        if(root->right == p) root->right = next;
                        else root->left = next;
                    }
                    else T.root = next;
                }
                else
                {
                    p->num = next->num;
                    next->root->left = next->right;
                }
            }
            else
            {
                if(p->left == before)
                {
                    if(root)
                    {
                        if(root->right == p) root->right = before;
                        else root->left = before;
                    }
                    else T.root = before;
                }
                else
                {
                    p->num = before->num;
                    before->root->right = before->left;
                }
            }
        }
    }
    getTrackList();
}
 
void print()
{
    struct binaryTreeNode *p = T.head;
    while (p)
    {
        printf("%d ", p->num);
        p = p->next;
    }
    printf("\n");
}