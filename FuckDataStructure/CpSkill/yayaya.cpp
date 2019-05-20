//第一遍看代码的时候 可以忽略所有带有path的行，只看路径长度算法
//第二遍再看带有path的行，得到路径上的节点序列

#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <stdlib.h>

using namespace std;

void shortest_path(int n,int cost[101][101]){
    bool s[101];    //判断该节点是否已经被加入
    int dist[101];    //存结果的数组
    string path[101];   //存路径的数组，没更新一次dist,路径也更新一次
    string init_path="v1";
    //初始化
    dist[1]=0;
    s[1]=true;

    for(int i=2;i<=n;i++){
        s[i]=false;
        dist[i]=-1;
    }

    //只加入了第一个节点的dist数组
    for(int i=2;i<=n;i++){
        dist[i]=cost[1][i];
        path[i]=init_path+"v"+to_string(i);//初始化 每个节点的路径就是v1到这个节点vi
    }
    //cout<<dist[2]<<endl;
    //cout<<dist[3]<<endl;
    //上述步骤已经完成了只有第一个节点的初始化
    //下一步：从dist中 找到一个距离最短的边，并把顶点加入s数组

    for(int i=2;i<=n;i++){ //剩下的N-1轮迭代
        int ii = 0; //记录该轮被加入的节点
        for(int j=2;j<=n;j++){//从第二个节点 到最后一个节点
            int min=1000;
            if(s[i]==false && dist[i]>0 && dist[i]<min){
                min=dist[i];
                ii=i;
            }
        }

        s[ii]=true;

        for(int i=2;i<=n;i++){
            if(cost[ii][i]!=-1 && s[i]==false){//如果新加入的节点ii到i节点有路径 而且i不在已选取的节点中
                if(dist[i]!=-1){ //v1到i节点有路径
                    if(dist[i]>dist[ii]+cost[ii][i]){//而且 经过ii节点的路径更短
                        dist[i]=dist[ii]+cost[ii][i]; //更新dist
                        path[i]=path[ii]+"v"+to_string(i);
                    }
                }
                else{//v1到i没有路径
                    dist[i]=dist[ii]+cost[ii][i];
                    path[i]=path[ii]+"v"+to_string(i);
                }
        }
    }
}
  //cout<<dist[n];
    cout<<"start"<<"   "<<"end"<<"   "<<"length"<<"   "<<"nodes list"<<endl;
    for(int i =2;i<=n;i++){
        if(dist[i]<100){//决定输出的空格数 控制格式
        cout<<"v1      "<<"v"<<i<<"    "<<dist[i]<<"       "<<path[i]<<endl;
        }
        else{
        cout<<"v1      "<<"v"<<i<<"    "<<dist[i]<<"      "<<path[i]<<endl;
        }
    }
}

int main(){
    // insert code here...
    int n;  //节点个数
    int m;  //边的个数
    int a,b,c;
    int cost[101][101];   //保存各节点间的代价

    while(scanf("%d%d",&n,&m)!=0){
        //cost数组的初始化
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                cost[i][j]=-1;
            }
        }
        for(int i = 0;i<m;i++){
            scanf("%d%d%d",&a,&b,&c);
            cost[a][b]=c;
        }
        //cout<<"第一次初始化";
        shortest_path(n,cost);
    }

}