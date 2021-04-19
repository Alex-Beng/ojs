#include <cstring>

#include <algorithm>
#include <unordered_map>
#include <queue>
#include <utility>
#include <string>
#include <iostream>
using namespace std;

// std::unordered_map<std::string, int> step;
std::unordered_map<long long, std::string> ops;


int op_diff[4][2] = {
    {-1, 0},
    {0, -1},
    {0, 1},
    {1, 0}
};
// char op2char[4] {'u', 'l', 'r', 'd'};
char op2char[4] = {'d', 'r', 'l', 'u'};//! reverse！

inline void int2status(long long t, int st[3][3], int& zr, int&zc) {
    long long mod = 100000000;
    for (int r=0; r<3; r++) {
        for (int c=0; c<3; c++) {
            st[r][c] = (t%(mod*10))/mod;
            mod /= 10;
            if (st[r][c] == 0) {
                zr = r;
                zc = c;
            }
        }
    }
}

inline void status2int(int st[3][3], long long& t) {
    t = 0;
    for (int r=0; r<3; r++) {
        for (int c=0; c<3; c++) {
            t += st[r][c];
            t *= 10;//!
        }
    }
    t /= 10;
}

void out_st(int st[3][3]) {
    for (int r=0; r<3; r++) {
        for (int c=0; c<3; c++) {
            cout<<st[r][c]<<' ';
        }
        cout<<endl;
    }
}

void bfs() {
    std::queue<long long> qrq;
    qrq.push(123456780);
    ops[123456780] = "0";

    long long t_status_int;
    int t_status[3][3];
    int t_zr, t_zc;
    
    long long t_nstatus_int;
    int t_nzr, t_nzc;
    while(!qrq.empty()) {
        t_status_int = qrq.front();
        qrq.pop();
        int2status(t_status_int, t_status, t_zr, t_zc);

        for (int i=0; i<4; i++) {
            t_nzr = t_zr + op_diff[i][0];
            t_nzc = t_zc + op_diff[i][1];
            
            if (t_nzr>=0 && t_nzr<3
            && t_nzc>=0 && t_nzc<3) {
                swap(t_status[t_zr][t_zc], t_status[t_nzr][t_nzc]);
                status2int(t_status, t_nstatus_int);
                if (ops[t_nstatus_int] == "") {
                    ops[t_nstatus_int] = ops[t_status_int] + op2char[i];
                    qrq.push(t_nstatus_int);
                }
                swap(t_status[t_zr][t_zc], t_status[t_nzr][t_nzc]);
            }
        }
    }
}

inline void chars2int(char t_str[10], long long& t_st_int) {
    t_st_int = 0;
    for (int i=0; i<9; i++) {
        if (t_str[i] == 'x') {
            t_st_int *= 10;
        }
        else {
            t_st_int += (t_str[i]-'0');
            t_st_int *= 10;
        }
    }
    t_st_int /= 10;
}

int main(int argc, char const *argv[]) {
    bfs();

    char t_str[10];
    long long t_st_int;
    t_str[9] = '\0';
    while(cin>>t_str[0]>>t_str[1]>>t_str[2]
             >>t_str[3]>>t_str[4]>>t_str[5]
             >>t_str[6]>>t_str[7]>>t_str[8]) {
        chars2int(t_str, t_st_int);
        if (ops.count(t_st_int)) {
            std::string t_ans = ops[t_st_int];
            t_ans = t_ans.substr(1);
            std::reverse(t_ans.begin(), t_ans.end());
            cout<<t_ans<<endl;
        }
        else {
            cout<<"unsolvable"<<endl;
        }
    }
    return 0;
}