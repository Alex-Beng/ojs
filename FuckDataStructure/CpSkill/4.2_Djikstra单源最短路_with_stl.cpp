#include <bits/stdc++.h>
using namespace std;
typedef int ElemType;
const int MAXN = 110;
int cost[110][110];
int vis[110];
int pre[MAXN];
int lowcost[MAXN];
const ElemType INF = 0x3f3f3f3f;


struct node{
    int id;
    int dist;
    node(int _id, int _dist){
        id = _id;
        dist = _dist;
    }
};

struct cmp{
    bool operator()(const node a,const node b){
        return a.dist>b.dist;
    }
};

priority_queue<node,vector<node>,cmp> que;

void Dijkstra(int n, int beg){
    //n为结点的个数，beg为源点
    for(int i=0; i<n; i++){
        lowcost[i]=INF; //进行初始化操作
        vis[i] = false;
        pre[i] = -1;
    }
    lowcost[beg] = 0;
    vis[beg] = 1;
    que.push(node(beg, 0));
    
    while(!que.empty()){
        node temp = que.top(); que.pop();
        vis[temp.id] = 1;
        for(int i=0; i<n; i++){
            if(!vis[i] && lowcost[temp.id]+cost[temp.id][i]<lowcost[i]){
                lowcost[i] = lowcost[temp.id]+cost[temp.id][i];
                pre[i] = temp.id;
                que.push(node(i,lowcost[i]));
            }
        }
    }
}



int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int N;
    cin>>N;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin>>cost[i][j];
        }
    }
    int beg;
    int end;
    cin >> beg >> end;
    Dijkstra(N, beg);
    // for(int i=0; i<N; i++){
    //     cout<<pre[i]<<endl;
    // }
    // for(int i=0; i<N; i++){
    //     cout<<lowcost[i]<<endl;
    // }
    int ans[110];
    int cnt = 0;
    while(end!=beg){
        ans[cnt] = end; cnt++; end = pre[end];
    }
    ans[cnt]=beg; cnt++;
    for(int i=cnt-1; i>=0; i--){
        cout<<ans[i]<<endl;
    }
    return 0;
}

/*
4
0 2 10 10000
2 0 7 3
10 7 0 6
10000 3 6 0
0 2
*/
