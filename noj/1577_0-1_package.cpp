#include <iostream>
using namespace std;
int things_num;
int things_weight[2333];
int capacity;
int ans;
int t_sum_weight;

void dfs(int layer) {
    if (layer == things_num) {
        if (t_sum_weight > ans) {
            ans = t_sum_weight;
        }
    }
    else {
        dfs(layer+1);//先搜索不塞入的...
        if (t_sum_weight+things_weight[layer] <= capacity) {
            t_sum_weight += things_weight[layer];
            dfs(layer+1);
            t_sum_weight -= things_weight[layer];
        }
    }
}

int main(int argc, char const *argv[]) {
    cin>>things_num>>capacity;
    for (int i=0; i<things_num; i++) {
        cin>>things_weight[i];
    }
    dfs(0);
    cout<<ans<<endl;
    return 0;
}
