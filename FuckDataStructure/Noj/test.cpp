#include <stdio.h>
#include <stdlib.h>
typedef struct node {
    int data;
    struct node* lchild;
    struct node* rchild;
} BiTNode, *BiTree;
void xianxu(BiTree root)
{
    if (root != NULL) {
        printf("%d\n", root->data);
        xianxu(root->lchild);
        xianxu(root->rchild);
    }
}
void creat(BiTree* root)
{
    BiTree Q[105];
    BiTree s;
    int i, n;
    int a[105][105];
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d%d%d", &a[i][0], &a[i][1], &a[i][2]);
    }
    for (i = 0; i < n; i++) {
        s = (BiTree)malloc(sizeof(BiTNode));
        s->data = a[i][0];
        s->rchild = NULL;
        s->lchild = NULL;
        Q[i] = s;
    }
    *root = Q[0];
    for (i = 0; i < n; i++) {
        Q[i]->data = a[i][0];
        if (a[i][1] != 0) {
            Q[i]->lchild = Q[a[i][1]];
        } else {
            Q[i]->rchild = NULL;
        }
        if (a[i][2] != 0) {
            Q[i]->rchild = Q[a[i][2]];
        } else {
            Q[i]->rchild = NULL;
        }
    }
}
int main()
{
    BiTree root;
    creat(&root);
    xianxu(root);
    return 0;
}

// #include <iostream>
// #include <list>

// using namespace std;

// int main()
// {
//     list<int>rn;         //Rn
//     list<int>sum;        //前Rn的累加和

//     int n = 15;         //计算500位
//     rn.push_back(2);     //R1的第一位初始化为2;
//     sum.push_back(2);    //sum的第一位初始化为2;

//     for(int i = 1; i < n; ++i)
//         rn.push_back(0), sum.push_back(0);  //Rn和sum的其他位初始化为0
//     list<int>::reverse_iterator rit1, rit2; //逆序迭代器
//     list<int>::iterator it;                 //正序迭代器
//     int temp, ret;
//     for(int i = 1; i < 500; i ++)
//     {
//         //R(n) = R(n-1)*i/(2*i+1)

//         //乘法
//         ret = 0;
//         for(rit1 = rn.rbegin(); rit1 != rn.rend(); ++rit1)
//         {
//             temp = *rit1*i+ret;
//             *rit1 = temp%10;
//             ret = temp/10;
//         }

//         //除法
//         ret = 0;
//         for(it = rn.begin(); it != rn.end(); ++it)
//         {
//             temp = (*it+ret*10);
//             *it = temp/(2*i+1);
//             ret = temp%(2*i+1);
//         }

//         //加法,计算sum
//         ret = 0;
//         for(rit1 = sum.rbegin(), rit2 = rn.rbegin(); rit1 != sum.rend()&& rit2!=rn.rend(); ++rit1, ++rit2)
//         {
//             temp = *rit1 + *rit2+ret;
//             *rit1 = temp%10;
//             ret = temp/10;
//         }

//         for (it = rn.begin(); it != rn.end(); it++) {
//             cout<<*it;
//         }
//         cout<<' ';
//         for (it = sum.begin(); it != sum.end(); it++) {
//             cout<<*it;
//         }
//         cout<<endl;
//     }

//     int i;
//     cin >> i;
//     it = sum.begin();
//     cout << *it << ".";
//     it ++;
//     while(it != sum.end() && i)
//     {
//         cout << *it;
//         it++, i--;
//     }

// }