#include <cstring>
#include <iostream>
using namespace std;
int dp[1001][1001];

int dfs(int n, int k) {// 从n个中最多取k个必胜
    if (n == 1 || n == 0)  {
        return 0;   
    }
    else if (n == k){
        return 1;
    }
    else if (dp[n][k] != -1) {
        return dp[n][k];
    } 
    else {
        
        for (int i=1; i<=n&&i<=k; i++) {
            // t_ans *= dfs(n-i, 2*i);
            if (dfs(n-i, 2*i) == 0) { // 这个min很关键！
                return dp[n][k] = 1;
            }
        }
    
        return dp[n][k] = 0;
        
    }
}


int main(int argc, char const *argv[]) {
    int n;
    memset(dp, -1, sizeof(dp)); // 初始化为-1
    // cout<<dp[0][0]<<endl;
    while (cin>>n && n) {
        cout<<dfs(n, 1)<<endl;
    }
    return 0;
}
