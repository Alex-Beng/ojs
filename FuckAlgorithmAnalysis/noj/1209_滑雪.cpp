#include <cstring>
#include <iostream>
using namespace std;

int rows,cols;
int height[233][233];
int dp[233][233];
int direction[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
int ans;

bool is_valid(int row, int col) {
    if (row<0 || row>=rows || col<0 || col>=cols) {
        return false;
    }
    return true;
}

int dfs(int row, int col) {
    if (dp[row][col] != -1) {
        return dp[row][col];
    }
    else {
        dp[row][col] = 1;
        for (int i=0; i<4; i++) {
            // cout<<row+direction[i][0]<<' '<<col+direction[i][1]<<endl;
            if (is_valid(row+direction[i][0], col+direction[i][1]) && height[row][col]>height[row+direction[i][0]][col+direction[i][1]]) {
                // cout<<row+direction[i][0]<<' '<<col+direction[i][1]<<endl<<endl;
                dp[row][col] = max(dp[row][col], dfs(row+direction[i][0], col+direction[i][1])+1);
            }
        }
        if (dp[row][col] > ans) {
            ans = dp[row][col];
        }
        return dp[row][col];
    }
}


int main(int argc, char const *argv[]) {
    memset(dp, -1, sizeof(dp));
    cin>>rows>>cols;
    for (int i=0; i<rows; i++) {
        for (int j=0; j<cols; j++) {
            cin>>height[i][j];
        }
    }

    for (int i=0; i<rows; i++) {
        for (int j=0; j<cols; j++) {
            // cin>>height[i][j];
            dfs(i, j);
        }
    }
    cout<<ans<<endl;
    return 0;
}
