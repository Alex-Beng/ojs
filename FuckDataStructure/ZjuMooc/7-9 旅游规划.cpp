#include <queue>
#include <iostream>
using namespace std;

#define MAX_N (555)

int n, e, beg, endd;
short mmp[MAX_N][MAX_N];
short fee[MAX_N][MAX_N];
int lowcost[MAX_N];
int lowfee[MAX_N];

struct node{
    int id;
    int dist;
    int fee;
    node(int _id, int _dist, int _fee){
        id = _id;
        dist = _dist;
        fee = _fee;
    }
};

struct cmp{
    bool operator()(const node a,const node b){
        if (a.dist != a.dist) {
            return a.dist>b.dist;
        }
        else {
            return a.fee<b.fee;
        }
    }
};

priority_queue<node,vector<node>,cmp> qrq;

void Dijkstra(){
    for(int i=0; i<n; i++){
        lowcost[i] = 0x3f3f3f3f;
        lowfee[i] = 0x3f3f3f3f;
    }
    lowcost[beg] = 0;
    lowfee[beg] = 0;
    qrq.push(node(beg, 0, 0));

    while (!qrq.empty()) {
        node t_node = qrq.top();
        qrq.pop();
        for (int i=0; i<n; i++) {
            if (lowcost[t_node.id]+mmp[t_node.id][i] < lowcost[i]) {
                lowcost[i] = lowcost[t_node.id]+mmp[t_node.id][i];
                lowfee[i] = lowfee[t_node.id]+fee[t_node.id][i];
                qrq.push(node(i, lowcost[i], lowfee[i]));
            }
            else if (lowcost[t_node.id]+mmp[t_node.id][i] == lowcost[i]) {
                // 康康费用
                if (lowfee[t_node.id]+fee[t_node.id][i] < lowfee[i]) {
                    lowcost[i] = lowcost[t_node.id]+mmp[t_node.id][i];
                    lowfee[i] = lowfee[t_node.id]+fee[t_node.id][i];
                    qrq.push(node(i, lowcost[i], lowfee[i]));
                }
            }
        }
    }
    
    cout<<lowcost[endd]<<' '<<lowfee[endd]<<endl;
}


int main(int argc, char const *argv[]) {
    cin>>n>>e>>beg>>endd;
    
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            mmp[i][j] = 555;
            fee[i][j] = 555;
        }
    }

    for (int i=0; i<e; i++) {
        int t_b, t_e, t_dis, t_fee;
        cin>>t_b>>t_e>>t_dis>>t_fee;
        mmp[t_b][t_e] = t_dis;
        mmp[t_e][t_b] = t_dis;
        fee[t_b][t_e] = t_fee;
        fee[t_e][t_b] = t_fee;
    }

    // do Dijkstra
    Dijkstra();

    return 0;
}