#include <cstring>
#include <iostream>
using namespace std;

int m,n;// m 个饺子 n 个人
int dp[233][233];

int dfs(int m, int n) {
    if (dp[m][n] != -1) {
        return dp[m][n];
    }

    if (m == 1 || n == 1 || m == 0) {
        return dp[m][n] = 1;
    }
    else if (m < n) {
        return dp[m][n] = dfs(m, m);
    }
    else {
        return dp[m][n] = dfs(m-n, n)+dfs(m, n-1);
    }
}

int main(int argc, char const *argv[]) {
    memset(dp, -1, sizeof(dp));
    cin>>m>>n;
    cout<<dfs(m, n)<<endl;
    return 0;
}
