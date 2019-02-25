#include <iostream>
using namespace std;

int num[9] = {1,2,3,4,5,6,7,8,9};
bool used[9] = {false};
int board[9];
int ans = 0;

bool check() {
    
    // int row_sum[3] = {0};
    // int col_sum[3] = {0};
    // int cross_line_sum[2] = {0};

    // for (int i=0; i<3; i++) {
    //     row_sum[0] += board[i];
    //     row_sum[1] += board[3+i];
    //     row_sum[2] += board[6+i];

    //     col_sum[0] += board[i*3]; 
    //     col_sum[1] += board[i*3+1];
    //     col_sum[2] += board[i*3+2];

    //     cross_line_sum[0] += board[i*3+i];
    //     cross_line_sum[1] += board[i*3+i-2];
    // }
    // for (int i=0; i<3; i++) {
    //     if (row_sum[i] != 15) {
    //         return false;
    //     }
    //     if (col_sum[i] != 15) {
    //         return false;
    //     }
    // }
    // for (int i=0; i<2; i++) {
    //     if(cross_line_sum[i] != 15) {
    //         return false;
    //     }
    // }
    // return true;

    int t_cross_line_sum = 0;
    int t_cross_line_sum_2 = 0;
    for (int i=0; i<3; i++) {
        int t_row_sum = 0;
        int t_col_sum = 0;
        t_cross_line_sum += board[i*3+i];
        t_cross_line_sum_2 += board[i*3+2-i];   
        for (int j=0; j<3; j++) {
            t_row_sum += board[i*3+j];
            t_col_sum += board[j*3+i];
        }
        if (t_col_sum != 15 || t_row_sum != 15) {
            return false;
        }
    }
    if (t_cross_line_sum != 15 || t_cross_line_sum_2 != 15) {
        return false;
    }
    else {
        return true;
    }
}

void show() {
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            cout<<board[i*3+j];
            if (j!=2) {
                cout<<' ';
            }
        }
        cout<<endl;
    }
    cout<<endl;
}

void search(int layer) {
    if (layer == 9) {
        // for (int i=0; i<9; i++) {
        //     cout<<board[i];
        // }
        // cout<<endl;
        if (check()) {
            // cout<<"hh"<<endl;
            ans++;
            show();
        }
    }
    else {
        for (int i=0; i<9; i++) {
            if (!used[i]) {
                // cout<<'h'<<endl;
                board[layer] = num[i];
                used[i] = true;
                search(layer+1);
                used[i] = false;
            }
        }
    }
}

int main(int argc, char const *argv[]) {
    search(0);
    return 0;
}
