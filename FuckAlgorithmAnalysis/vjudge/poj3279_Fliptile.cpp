#include <cstring>

#include <iostream>
using namespace std;

int m, n;
int status[23][33];
int curr_ops[23][33];

int answ;
int answ_ops[23][33];

int diff[4][2] = {//! 5->4
    {0, 0},
    {-1, 0},
    {0, -1},
    {0, 1},
};

int get_color(int r, int c) {
    int t_color = status[r][c];
    int tr, tc;
    for (int i=0; i<4; i++) {
        tr = r+diff[i][0];
        tc = c+diff[i][1];
        if (tr>=0 && tr<m && tc>=0 && tc<n) {
            if (curr_ops[tr][tc]) {
                t_color = 1-t_color;
            }
        }
    }
    return t_color;
}

void out_res(int array[][33]) {
    for (int i=0; i<m; i++) {
        for (int j=0; j<n; j++) {
            cout<<array[i][j];
            if (j!=n-1) cout<<' ';
        }
        cout<<endl;
    }
}

void out_status() {
    for (int i=0; i<m; i++) {
        for (int j=0; j<n; j++) {
            cout<<get_color(i, j)<<' ';
        }
        cout<<endl;
    }
}

int search() {
    for (int tr=1; tr<m; tr++) {
        for (int tc=0; tc<n; tc++) {
            if (get_color(tr-1, tc)) {// 上面的黑只能下面翻
                curr_ops[tr][tc] = 1;
            }
        }
    }
    int t_sum = 0;
    
    for (int tc=0; tc<n; tc++) {
        t_sum += get_color(m-1, tc);
    }
    if (t_sum) {
        return -1;
    }

    int t_ans = 0;
    for (int tr=0; tr<m; tr++) {//! tr=1
        for (int tc=0; tc<n; tc++) {
            t_ans += curr_ops[tr][tc];
        }
    }
    return t_ans;

}



int main(int argc, char const *argv[]) {
    answ = 2147483647;

    cin>>m>>n;
    for (int i=0; i<m; i++) {
        for (int j=0; j<n; j++) {
            cin>>status[i][j];
        }
    }

    // enumerate Line 0 ops
    for (int i=0; i<(1<<n); i++) {
        memset(curr_ops, 0, sizeof(curr_ops));
        int t_ops = i;
        for (int j=0; j<n; j++) {
            curr_ops[0][j] = t_ops%2;
            t_ops = t_ops>>1;
        }
        int t_ass = search();
        if (t_ass < answ && t_ass != -1) {//!
            // cout<<t_ass<<endl;
            // out_res(curr_ops);
            
            answ = t_ass;
            memcpy(answ_ops, curr_ops, sizeof(curr_ops));
        }
    }
    
    if (answ == -1 || answ == 2147483647) {//!
        cout<<"IMPOSSIBLE"<<endl;
    }
    else {
        out_res(answ_ops);
    }
    return 0;
}