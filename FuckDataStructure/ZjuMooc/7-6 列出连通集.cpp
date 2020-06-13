#include <map>
#include <queue>
#include <iostream>
using namespace std;
map<int, int> mmp;
bool* used_node;
int n, e;

void bfs(int node);
void dfs(int node);
void set_node(bool status);

int main(int argc, char const *argv[]) {
    cin>>n>>e;
    used_node = new bool[n];

    for (int i=0; i<e; i++) {
        int node_1, node_2;
        cin>>node_1>>node_2;
        mmp[node_1*n + node_2] = 1; // 看成是n进制下的[node_1][node_2]两位数
        mmp[node_2*n + node_1] = 1;
    }

    set_node(false);
    for (int i=0; i<n; i++) {
        if (used_node[i]) {
            continue;
        }
        used_node[i] = true;
        printf("{ %d ", i);
        dfs(i);
        cout<<'}'<<endl;
    }

    set_node(false);
    for (int i=0; i<n; i++) {
        if (used_node[i]) {
            continue;
        }
        used_node[i] = true;
        printf("{ ");

        bfs(i);
        cout<<'}'<<endl;
    }

    delete [] used_node;
    return 0;
}


void bfs(int node) {
    queue<int> qrq;
    qrq.push(node);

    while (!qrq.empty()) {
        int t_node = qrq.front();
        qrq.pop();
        used_node[t_node] = true;
        cout<<t_node<<' ';
        for (int i=0; i<n; i++) {
            if (mmp[i*n + t_node] && !used_node[i]) {
                qrq.push(i);
                used_node[i] = true;
            }
        }
    }
    
}

void dfs(int node) {
    for (int i=0; i<n; i++) {
        if (mmp[i*n + node] && !used_node[i]) {
            used_node[i] = true;
            cout<<i<<' ';
            dfs(i);
        }
    }
}
void set_node(bool status) {
    for (int i=0; i<n; i++) {
        used_node[i] = false;
    }
}

