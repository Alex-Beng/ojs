#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
int n;
int height[2333];
int memory[233][10000]; // [第几层][当前高度], 数值为最多拦截的导弹数
int t_sum_missile;
int ans;
int dfs_with_memory(int layer, int t_height) {
    if (memory[layer][t_height] != -1) {
        return memory[layer][t_height];
    }

    if (layer == n) {
        if (t_sum_missile > ans) {
            ans = t_sum_missile;
        }
    }
    else {
        if (height[layer] <= t_height) {
            dfs_with_memory(layer+1,t_height);
            t_sum_missile++;
            dfs_with_memory(layer+1,height[layer]);
            t_sum_missile--;
            // if (dfs_with_memory(layer+1,height[layer]) > dfs_with_memory(layer+1,t_height)) {
            //     t_sum_missile++;
            // }
            memory[layer][t_height] = max(dfs_with_memory(layer+1,height[layer]),dfs_with_memory(layer+1,t_height));
            return  memory[layer][t_height];
        }
        else {
            memory[layer][t_height] = dfs_with_memory(layer+1,t_height);
            return memory[layer][t_height];
        }
    }
}

int main(int argc, char const *argv[]) {
    while (cin>>n&&n) {
        for (int i=0; i<n; i++) {
            cin>>height[i];
        }
        memset(memory, 1, sizeof(memory)); // 初始化为-1
        ans = -1;
        t_sum_missile = 0;
        dfs_with_memory(0,999999);
        cout<<ans<<endl;
    }

    return 0;
}
