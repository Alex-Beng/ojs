#include <iostream>
using namespace std;
int n, k;
char board[23][33]; // '#' for can put, '.' for not, 'q' for qizi
int ans;

bool put_able(int row, int col) {
    if (board[row][col] != '#') {
        return false;
    }
    for (int i=row-1; i>=0; i--) {
        if (board[i][col] == 'q') {
            return false;
        }
    }
    for (int i=col-1; i>=0; i--) {
        if (board[row][i] == 'q') {
            return false;
        }
    }
    return true;
}

void dfs(int layer) {
    if (layer > n) {
        return;
    }

    if (layer == n && k == 0) {
            ans++;
    }
    else {
        for (int i=0; i<n; i++) {
            if (put_able(layer, i) && k > 0) {
                k--;
                board[layer][i] = 'q';
                dfs(layer+1);
                k++;
                board[layer][i] = '#';
            }
        }
        dfs(layer+1); // 与皇后问题不同, 这个可以直接搜索下一层
    }
}

int main(int argc, char const *argv[]) {
    while (cin>>n>>k && !(n==-1 && k==-1)) {
        ans = 0;
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                cin>>board[i][j];
            }
        }
        dfs(0);
        cout<<ans<<endl;
    }
    return 0;
}
