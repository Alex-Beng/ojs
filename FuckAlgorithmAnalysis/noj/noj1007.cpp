#include <cmath>
#include <iostream>
using namespace std;

int ans_num = 0;
int board[10][10];

void print_board(){
    cout<<"No "<<++ans_num<<':'<<endl;
    for (int i=1;i<=8;i++){
        for (int j=1;j<=8;j++){
            if (board[i][j] == 1) {// 是皇后
                cout<<'A';
            }
            else if (board[i][j] == 0){ // 是空格
                cout<<'.';
            } 
        }
        cout<<endl;
    }
}

bool check_vaild( int row, int col ) {
    for (int i=1;i<row;i++) {
        for (int j=1;j<=8;j++) {
            if (board[i][j] == 1) {
                if (j==col) { //同一列
                    return false;
                }
                else if ( (row-i) == abs(col-j) ){ //斜对角
                    return false;
                }
            }
        }
    }
    return true;
}

void dfs( int row ){
    if (row > 8){
        print_board();
    }
    else {
        for (int i=1;i<=8;i++){
            if (check_vaild(row,i)) { //可以放
                board[row][i] = 1;
                dfs(row+1);
                board[row][i] = 0;
            }
        }
    }

}


int main() {
    dfs(1);
    return 0;
}
