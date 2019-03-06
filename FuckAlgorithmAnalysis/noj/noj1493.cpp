#include <stdio.h>
#include<stdlib.h>
 
typedef struct OLNODE
{
    int row,col;
    int data;
    struct OLNODE *right,*down;
} NODE,*LNODE;
 
typedef struct CORSS
{
    LNODE *rh,*ch;
    int ra,ca,da;
} CROSS, *LCROSS;
 
void Create(LCROSS A);
 
void PlusToA(LCROSS A,LCROSS B);
 
void PrintCross(LCROSS A);
 
int main()
{
    LCROSS A = (LCROSS)malloc(sizeof(CROSS));
    LCROSS B = (LCROSS)malloc(sizeof(CROSS));
 
    scanf("%d %d %d %d",&A->ra,&A->ca,&A->da,&B->da);
    B->ra = A->ra;
    B->ca = A->ca;
 
    Create(A);
    Create(B);//" 3  4 0 5  创建时B有问题"
    PlusToA(A,B);
    PrintCross(A);
    return 0;
}
 
void Create(LCROSS M)
{
    int i;
    LNODE p,temp;
 
    M->rh = (LNODE *)malloc((M->ra+1)*sizeof(LNODE));
    M->ch = (LNODE *)malloc((M->ca+1)*sizeof(LNODE));
 
    for(i=1; i<=M->ra; i++)
    {
        M->rh[i]=NULL;
    }
    /*for(i=1; i<=M->ca; i++)
    {
        M->ch[i]=NULL;
    }*/
 
    if(M->da != 0)
    {
        for(i=1; i<=M->da; i++)
        {
            p=(LNODE)malloc(sizeof(NODE));
            scanf("%d %d %d",&p->row,&p->col,&p->data);
            if(M->rh[p->row] == NULL)
            {
                p->right=NULL;
                M->rh[p->row] = p;
 
            }
            else
            {
                for(temp=M->rh[p->row];; temp=temp->right)
                {
                    if(temp->right == NULL)
                    {
                        temp->right = p;
                        p->right =NULL;
                        break;
                    }
                    else if(temp->col < p->col && temp->right->col>p->col)
                    {
                        p->right = temp->right;
                        temp->right = p;
                        break;
                    }
                    else if(temp==M->rh[p->row] && temp->col>p->col)
                    {
                        p->right = temp;
                        temp=p;
                        break;
                    }
                }
 
 
 
            }
 
   /*         if(M->ch[p->col] == NULL|| M->ch[p->col]->row>(p->row))
            {
                p->down=M->ch[p->col];
                M->ch[p->col] = p;
            }
            else
            {
                for(temp=M->ch[p->col]; temp->down && temp->down->row<p->row; temp=temp->down);
                p->down = temp->down;
                temp->down = p;
            }*/
        }
    }
 
}
 
void PlusToA(LCROSS A,LCROSS B)
{
    int i;
    LNODE p,temp1,temp2;
    for(i=1; i<=A->ra; i++)
    {
        if(B->rh[i] == NULL) continue;
        else
        {
            if(A->rh[i] == NULL)
            {
 
                p=(LNODE)malloc(sizeof(NODE));
                p->col = B->rh[i]->col;
                p->row = B->rh[i]->row;
                p->data = B->rh[i]->data;
                A->rh[i]=p;
                p->right = NULL;
                B->rh[i]=B->rh[i]->right;
 
            }
            if(B->rh[i]==NULL)continue;
            for(temp1=B->rh[i];; temp1=temp1->right)
            {
                for(temp2=A->rh[i];; temp2=temp2->right)
                {
                    if(temp2->col == temp1->col)
                    {
                        temp2->data+=temp1->data;
                        break;
                    }
                    else if(temp2==A->rh[i] && temp1->col<temp2->col)
                    {
                        p=(LNODE)malloc(sizeof(NODE));
                        p->col = temp1->col;
                        p->row = temp1->row;
                        p->data = temp1->data;
                        p->right = temp2->right;
                        p->right =temp2;
                        A->rh[i]=p;
                        break;
                    }
                    else if((temp2->right == NULL || temp2->right->col>temp1->col)  && temp1->col>temp2->col)
                    {
                        p=(LNODE)malloc(sizeof(NODE));
                        p->col = temp1->col;
                        p->row = temp1->row;
                        p->data = temp1->data;
                        p->right = temp2->right;
                        temp2->right=p;
                        break;
                    }
 
                }
 
                if(temp1->right == NULL) break;
            }
        }
    }
 
}
 
 
void PrintCross(LCROSS A)
{
    int i;
    LNODE p;
    for(i=1; i<=A->ra; i++)
    {
        p=A->rh[i];
        while(p!=NULL)
        {
            printf("%d %d %d\n",p->row,p->col,p->data);
            p=p->right;
        }
    }
}
