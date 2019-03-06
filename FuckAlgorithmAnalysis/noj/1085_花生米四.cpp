#include <stdio.h>
// 把n堆数量全部转成二进制
// 然后统计各个堆的数量二进制的1的数量
// 若有一堆有奇数个1, 先取会赢,
// 否则后取会赢
int a[10];
int b[10][7]; //2^7=128>100，7位小够用了
int n;
int change();
void com(int m);
int main(){
    int i,j,k;
    scanf("%d",&n);
    while(n!=0){
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        for(i=0;i<n;i++)
            for(j=0;j<7;j++)
                b[i][j]=0;
        k=change();
        printf("%d\n",k);
        scanf("%d",&n);
    }
    return 0;
}
int change(){
    int i,j,flag;
    for(i=0;i<n;i++)
        com(i);
    for(i=0;i<7;i++){
        flag=0;
        for(j=0;j<n;j++){
            if(b[j][i]==1) flag=1-flag; //只要找到所有堆数中，某一位上共有奇数个1，就会使flag为1
			//只要找到奇数个，那么所有数异或后会成为S态（即大于0），
			//这是最后取会赢，由取火柴游戏可知：S态，只要方法正确，必赢。 
			//http://www.cnblogs.com/tanky_woo/archive/2010/08/20/1804464.html
        }
        if(flag==1) break; //一旦找到flag＝1，就退出循环，最后会返回1
    }
    if(flag==1) return 1;
    else return 0;
}
void com(int m){
    int t=a[m],p;
    int i;
    for(i=0;i<7;i++){
        p=t/2;
        b[m][i]=t-p*2; //将a[m]转化成7位二进制表示的数
        t=t/2;
    }
}