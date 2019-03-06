#include <iostream>
using namespace std;

int n;
int missile_height[233333];
int t_ms_num;
int ans = -1;

int dfs(int layer, int t_height) {
    if (layer == n) {
        if (t_ms_num > ans) {
            ans = t_ms_num;
        }
        return 0;
    }
    else {
        int res;
        res = dfs(layer+1, t_height);
        if (t_height > missile_height[layer]) {
            res = max(res, dfs(layer+1, missile_height[layer]));
        }
        return res;
    }
}

int main(int argc, char const *argv[]) {
    
    return 0;
}
