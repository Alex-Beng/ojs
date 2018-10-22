// 搜索版本..
#include <iostream>
using namespace std;
int n;
int height[233];
int ans;
int t_sum_missile;
void dfs(int layer, int t_height) {
    if (layer == n) {
        if (t_sum_missile > ans) {
            ans = t_sum_missile;
        }
    }
    else {
        dfs(layer+1,t_height); // 不拦截

        if (height[layer] <= t_height) { //拦截
            t_sum_missile++;
            dfs(layer+1,height[layer]);
            t_sum_missile--;
        }
    }
}

int main(int argc, char const *argv[]) {
    while(cin>>n&&n) {
        for (int i=0; i<n; i++) {
            cin>>height[i];
        }
        ans = 0;
        dfs(0,9999999);
        cout<<ans<<endl;
    }
    
    return 0;
}
