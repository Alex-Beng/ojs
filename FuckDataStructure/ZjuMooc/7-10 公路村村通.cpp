#include <iostream>
using namespace std;

const int MAX_N = 1233;
const int INTMAX = 65535;

int map[MAX_N][MAX_N];
int node_num, edge_num;

void input_map();
int prim();

int main(int argc, char const *argv[]) {
    cin>>node_num>>edge_num;
    input_map();
    int ans = prim();
    cout<<ans<<endl;
    return 0;
}

void input_map() {
    for (int i=1; i<=node_num; i++) {
        for (int j=1; j<=node_num; j++) {
            map[i][j] = INTMAX;
        }
    }
    for (int i=0; i<edge_num; i++) {
        int n1, n2, e;
        cin>>n1>>n2>>e;
        map[n1][n2] = e;
        map[n2][n1] = e;
    }
}

int prim() {
    int ans = 0;
    int lowcost[node_num+7]; // 加入结点时，当前已加入树的结点到其他结点的最短距离，
    //                          && 用于标记时候已加入生成树

    lowcost[1] = 0;// 第一个结点
    for (int i=2; i<=node_num; i++) {
        lowcost[i] = map[1][i];
    }

    for (int i=2; i<=node_num; i++) {// 每次加一个结点
        int min_cost = INTMAX; 
        int min_node = 0;
        for (int j=1; j<=node_num; j++) {
            if (lowcost[j] != 0   // 未加入树
            && lowcost[j] < min_cost) {// 更短不
                min_cost = lowcost[j];
                min_node = j;
            }
        }
        if (min_node == 0) {
            return -1;// 不连通鸭
        }
        ans += min_cost;
        lowcost[min_node] = 0;

        // 更新lowcost
        for (int j=2; j<=node_num; j++) {
            if (lowcost[j] != 0 && map[min_node][j] < lowcost[j]) {
                lowcost[j] = map[min_node][j];
            }
        }
    }
    return ans;
}
