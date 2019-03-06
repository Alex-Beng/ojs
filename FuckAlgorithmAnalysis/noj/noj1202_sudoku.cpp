#include <iostream>
using namespace std;
int board[9][9]; // [rows][cols]
int ans = 0;
void dfs(int layer) {
    int rows = layer/9;
    int cols = layer%9;
    if (layer >= 81) {
        ans ++;
        // cout<<ans<<endl;
        for (int i=0; i<9; i++) {
            for (int j=0; j<9; j++) {
                cout<<board[i][j];
            }
            cout<<endl;
        }
    }
    else {
        if (board[rows][cols] != 0) {
            dfs(layer+1);
        }
        else {
            for (int i=1; i<=9; i++) {      //填入的i
                bool flag = true;
                for (int j=0; j<9; j++) {   //判重的index
                    if (board[rows][j] == i || board[j][cols] == i){
                        flag = false;
                    }
                }
                int section_rows = rows/3;
                int section_cols = cols/3;
                for (int row_i=section_rows*3; row_i<section_rows*3+3; row_i++) {
                    for (int col_i=section_cols*3; col_i<section_cols*3+3; col_i++) {
                        if (board[row_i][col_i] == i){
                            flag = false;
                        }
                    }
                }
                if (flag) {
                    board[rows][cols] = i;
                    dfs(layer+1);
                    board[rows][cols] = 0;
                }
            }
        }
    }
}
int main(int argc, char const *argv[])
{
    for (int i=0; i<9; i++) {
        for (int j=0; j<9; j++) {
            char t_char;
            cin>>t_char;
            board[i][j] = (int)(t_char-'0');
        }
    }
    // cout<<endl;

    dfs(0);
    // for (int i=0; i<9; i++) {
    //     for (int j=0; j<9; j++){
    //         cout<<board[i][j] ;
    //     }
    //     cout<<endl;
    // }
    // cout<<"total"<<ans<<endl;
    return 0;
}
