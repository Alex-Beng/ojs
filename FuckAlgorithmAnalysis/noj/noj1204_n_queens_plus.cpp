#include <iostream>
using namespace std;
int ans = 0;
int n;
int board[10000][10000]; // 0 for blank, 1 for queen

bool can_put(int rows,int cols) {
    int row_count = 0;
    int col_count = 0;
    for (int i=0; i<n; i++) {
        if (board[rows][i] == 1) {
            row_count++;
        }
        if (board[i][cols] == 1) {
            col_count++;
        }
        if (row_count>=2 || col_count>=2) {
            return false;
        }
    }
    return true;
}

void dfs(int layer) {
    int rows = layer/n;
    int cols = layer%n;
    if (layer >= n*n) {
        for (int i=0;i<n;i++) {
            int row_count = 0;
            int col_count = 0;
            for (int j=0;j<n;j++) {
                if (board[i][j] == 1) {
                    row_count++;
                }
                if (board[j][i] == 1) {
                    col_count++;
                }
            }
            if (row_count != 2 || col_count != 2) {
                return ;
            }
        }
        ans++;
        // for (int i=0;i<n;i++) {
        //     for (int j=0;j<n;j++) {
        //         cout<<board[i][j];
        //     }
        //     cout<<endl;
        // }
        // cout<<endl;
    }
    else {
        dfs(layer+1);
        int t_rows = (layer+1)/n;
        int t_cols = (layer+1)%n;
        if (can_put(t_rows,t_cols)) {
            board[t_rows][t_cols] = 1;
            dfs(layer+1);
            board[t_rows][t_cols] = 0;
        }
    }
}

int main(int argc, char const *argv[])
{
    cin>>n;
    dfs(0);
    cout<<ans<<endl;
    return 0;
}
