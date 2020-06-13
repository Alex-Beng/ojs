#include <map>
#include <iostream>
using namespace std;
map<int, int> mmp;
bool used_node[2333];
int n, e;
int ans;

void dfs(int node, int layer);
void set_node(bool status);

int main(int argc, char const *argv[]) {
    cin>>n>>e;

    for (int i=0; i<e; i++) {
        int node_1, node_2;
        cin>>node_1>>node_2;
        mmp[node_1*n + node_2] = 1; // 看成是n进制下的[node_1][node_2]两位数
        mmp[node_2*n + node_1] = 1;
    }

    for (int i=1; i<=n; i++) { // 对于每一个结点
        set_node(false);
        used_node[i] = true;
        ans = 1;
        dfs(i, 1);
        printf("%d: %.2f%\n", i, ans*100.0/n);
    }
        
    return 0;
}

void dfs(int node, int layer) {
    if (layer > 6) {
        return;
    }
    // cout<<"curr"<<node<<endl;
    for (int i=1; i<=n; i++) {
        if (mmp[i*n + node] && !used_node[i]) {
            used_node[i] = true;
            ans++;
            dfs(i, layer+1);
        }
    }
}

void set_node(bool status) {
    for (int i=0; i<=n; i++) {
        used_node[i] = false;
    }
}
