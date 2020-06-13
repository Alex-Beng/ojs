#include <stdio.h>
#include <stdlib.h>

typedef struct OL { //定义带有“右”“下”的结构体
    int i, j;
    int ele;
    struct OL *right, *down;
} OL, *olink;

typedef struct
{ //定义各行各列的头指针结构体
    olink *rhead, *chead;
    int mu, nu, tu;
} cross, *cr;

void init(cross* M)
{ //初始化头指针
    M->rhead = M->chead = NULL;
    M->mu = M->nu = M->tu = 0;
}

void creat(cross* M, int m, int n, int t)
{ //输入各项数值创建一个十字链表
    int i, j, k, e;
    olink p, q;
    M->mu = m;
    M->nu = n;
    M->tu = t;
    M->rhead = (olink*)malloc(sizeof(olink) * (m + 1));
    M->chead = (olink*)malloc(sizeof(olink) * (n + 1)); //申请行和列的头指针数组
    for (k = 1; k <= m; k++)
        M->rhead[k] = NULL;
    for (k = 1; k <= n; k++)
        M->chead[k] = NULL; //把各行各列的头指针都指向NULL
    for (k = 0; k < t; k++) { //输入t组元素作为十字链表储存的稀疏矩阵
        scanf("%d%d%d", &i, &j, &e);
        p = (olink)malloc(sizeof(OL));
        p->i = i;
        p->j = j;
        p->ele = e;
        if (M->rhead[i] == NULL || M->rhead[i]->j > j) { //如果输入数据所在的这一行的头指针为NULL，或者头指针所在的列大于要输入的元素的列
            p->right = M->rhead[i];
            M->rhead[i] = p; //就直接把这一行的头指针改为输入的元素
        } else { //不然就依此查找该把次元素插在此行的哪一个位置
            for (q = M->rhead[i]; (q->right) && q->right->j < j; q = q->right)
                ;
            p->right = q->right;
            q->right = p;
        }
        p->down = NULL;
        if (M->chead[j] == NULL || M->chead[j]->i > i) { //列的插入与行类似，如果此列为空或者要插入的元素的行小于本来的头
            p->down = M->chead[j];
            M->chead[j] = p;
        } else {
            for (q = M->chead[j]; (q->down) && q->down->i < i; q = q->down)
                ;
            p->down = q->down;
            q->down = p;
        }
        p->right = NULL;
    }
}

void insert(cross& M, olink& p) //选择将B中的每个元素依此插入A
{
    int i = p->i, j = p->j;
    int de = 0, pl = 0; //定义两个变量作为指示
    if (M.rhead[i] == NULL) //先将此元素块插入A的行链表
    {
        M.rhead[i] = p; //如果A此行没有元素就直接插入
        M.tu++;
    } else {
        olink q = M.rhead[i];
        olink pre = q;
        while (q && (q->j < p->j)) //用两个指针找到该元素块应该插到那个位置
        {
            pre = q;
            q = q->right;
        }
        if (q != NULL && (q->j == p->j)) //如果要插入的A中位置恰好有元素
        {
            q->ele += p->ele;
            if (q->ele == 0) //若果AB相应元素加在一起为0，就把A中的这个元素块从链表中删除
            {
                if (pre == q)
                    M.rhead[i] = q->right;
                else
                    pre->right = q->right;
                M.tu--;
                de = 1;
            } else
                pl = 1;
        }
        if (de == 0 && pl == 0) //如果在A中没找到与P元素位置相同的元素块
        {
            if (pre == q) {
                M.rhead[i] = p; //此种情况直接插在头
                p->right = q;
            } else {
                pre->right = p; //此种情况插在之前找到的合适位置
                p->right = q;
            }
            M.tu++;
        }
    }
    if (M.chead[j] == NULL)
        M.chead[j] = p; //列的插入与行类似
    else {
        olink q = M.chead[j];
        olink pre = q;
        while (q && (q->i < p->i)) {
            pre = q;
            q = q->down;
        }
        if (de == 1) {
            if (q != NULL) {
                if (pre == q)
                    M.chead[j] = q->down;
                else
                    pre->down = q->down;
                free(q);
                free(p); //如果AB对应元素相加为0，将这个元素从链表中删除后再free掉
                return;
            }
        }
        if (pl == 0) {
            if (pre == q) {
                M.chead[j] = p;
                p->down = q;
            } else {
                pre->down = p;
                p->down = q;
            }
        }
    }
}

void add(cross& M, cross& N)
{ //将N矩阵加到M上
    olink p, q;
    p = (olink)malloc(sizeof(OL));
    int k = 1;
    for (; k <= N.mu; k++) {
        p = N.rhead[k];
        while (p) //依此找出N中的每个元素插入M中
        {
            q = (olink)malloc(sizeof(OL));
            q->down = p->down;
            q->right = p->right;
            q->ele = p->ele;
            q->i = p->i;
            q->j = p->j; //因为将P插入后N中原来的元素会变化，所以另设一个保存原有数据
            //printf("out");
            insert(M, q);
            p = p->right;
        }
    }
}

void show(cross& M)
{ //按照先行后列的顺序额依此输出一个以十字链表为春村结构的稀疏矩阵
    int k = 1, t = 1;
    for (k = 1; k <= M.mu; k++) {
        olink P = M.rhead[k];
        for (t = 1; t <= M.nu; t++) {
            if (P != NULL && t == P->j) {
                printf("%d %d %d\n", P->i, P->j, P->ele);
                P = P->right;
            }
        }
    }
}

int main()
{
    int m, n, t1, t2;
    scanf("%d%d%d%d", &m, &n, &t1, &t2);
    cross a, b;

    init(&a);
    init(&b);
    creat(&a, m, n, t1); //创建两个十字链表储存链两个稀疏矩阵
    creat(&b, m, n, t2);
    add(a, b); //加
    show(a); //输出
    return 0;
}
