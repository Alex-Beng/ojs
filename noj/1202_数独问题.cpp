#include <iostream>
using namespace std;

int board[23][33];

void input() {
    int num[23];
    for (int i=0; i<9; i++) {
        cin>>num[i];
    }
    for (int i=0; i<9; i++) {
        for (int j=8; j>=0; j--) {
            board[i][j] = num[i]%10;
            num[i] /= 10;
        }
        
    }
}

void output() {
    for (int i=0; i<9; i++) {
        for (int j=0; j<9; j++) {
            cout<<board[i][j];
        }
        cout<<endl;
    }
}


bool check_ans() {
    for (int i=0; i<9; i++) {  
        // 对每一行
        int used[23];
        for (int j=1; j<=9; j++) {
            used[j] = false;
        }

        for (int j=0; j<9; j++) {
            used[board[i][j]] = true;
        }
        for (int j=1; j<=9; j++) {
            if (!used[j]) {
                return false;
            }
        }


        // 对每一列
        for (int j=1; j<=9; j++) {
            used[j] = false;
        }

        for (int j=0; j<9; j++) {
            used[board[j][i]] = true;
        }
        for (int j=1; j<=9; j++) {
            if (!used[j]) {
                return false;
            }
        }
    }
    return true;
}

void dfs(int layer) {
    if (layer == 81) {
        if (check_ans()) {
            output();
        }
    }
    else {
        for (int i=1; i<=9; i++) {
            board[layer/9][layer%9] = i;
            dfs(layer+1);
        }
    }
}


int main(int argc, char const *argv[]) {
    input(); 
    dfs(0);
    return 0;
}
