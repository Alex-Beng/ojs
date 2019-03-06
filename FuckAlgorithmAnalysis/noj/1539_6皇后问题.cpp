#include <iostream>
using namespace std;

#define QUEEN 1
#define SPACE 0

int n = 6;
int board[23][33]; // 0 for space, 1 for queen
int ans;

void show(int ans) {
    cout<<"No "<<ans<<':'<<endl;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (board[i][j] == QUEEN) {
                cout<<'A';
            }
            else {
                cout<<'.';
            }
        }
        cout<<endl;
    }
}

bool can_put(int row, int col) {
    for (int t_row=row-1; t_row>=0; t_row--) {
        if (board[t_row][col] == QUEEN) {
            return false;
        }

        if (col - (row-t_row)<0) {
            ;
        }
        else {
            if (board[t_row][col - (row-t_row)] == QUEEN) {
                return false;
            }
        }

        if (col + (row-t_row)>=n) {
            ;
        }
        else {
            if (board[t_row][col + (row-t_row)] == QUEEN) {
                return false;
            }
        }

    }
    return true;   
}


void dfs(int layer) {
    if (layer == n) {
        ans++;
        show(ans);
    }
    else {
        for (int i=0; i<n; i++) {
            if (can_put(layer, i)) {
                board[layer][i] = QUEEN;
                dfs(layer+1);
                board[layer][i] = SPACE;
            }
        }
    }
}


int main(int argc, char const *argv[]) {
    dfs(0);
    // cout<<ans<<endl;
    return 0;
}
