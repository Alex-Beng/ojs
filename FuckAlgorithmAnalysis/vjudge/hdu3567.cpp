#include <cstdio>

#include <queue>
#include <string>
#include <unordered_map>
#include <iostream>
using namespace std;

int op_diff[4][2] = {
    {-1, 0},
    {0, -1},
    {0, 1},
    {1, 0}
};
char op2char[4] {'u', 'l', 'r', 'd'};


inline void str2status(std::string t, char st[3][3], int& zr, int&zc) {
    for (int r=0; r<3; r++) {
        for (int c=0; c<3; c++) {
            st[r][c] = t[r*3+c];
            if (st[r][c] == 'X') {//!
                zr = r;
                zc = c;
            }
        }
    }
}

inline void status2str(char st[3][3], std::string& t) {
    t = "";
    for (int r=0; r<3; r++) {
        for (int c=0; c<3; c++) {
            t += st[r][c];
        }
    }
}

std::string bfs(std::string curr_state, std::string goal_state) {
    std::unordered_map<std::string, std::string> ops;
    std::queue<std::string> qrq;

    ops[curr_state] = "0";
    qrq.push(curr_state);

    std::string t_st_str, t_nst_str;
    char t_st[3][3];

    int t_zr, t_zc, t_nzr, t_nzc;
    while (!qrq.empty()) {
        t_st_str = qrq.front();
        // cout<<t_st_str<<endl;
        qrq.pop();
        if (t_st_str == goal_state) {
            return ops[t_st_str].substr(1);
        }

        str2status(t_st_str, t_st, t_zr, t_zc);
        for (int i=0; i<4; i++) {
            t_nzr = t_zr + op_diff[i][0];
            t_nzc = t_zc + op_diff[i][1];

            if (t_nzr>=0 && t_nzr<3
            && t_nzc>=0 && t_nzc<3) {
                std::swap(t_st[t_zr][t_zc], t_st[t_nzr][t_nzc]);
                status2str(t_st, t_nst_str);
                if (ops[t_nst_str] == "") {
                    ops[t_nst_str] = ops[t_st_str] + op2char[i];
                    qrq.push(t_nst_str);
                }
                std::swap(t_st[t_zr][t_zc], t_st[t_nzr][t_nzc]);
            }
        }
    }
}

int main(int argc, char const *argv[]) {
    int n;
    std::string c_st, g_st, res;
    cin>>n;
    for (int i=0; i<n; i++) {
        cin>>c_st;
        cin>>g_st;

        res = bfs(c_st, g_st);
        printf("Case %d: %d\n", i+1, res.size());
        cout<<res<<endl;
    }
    return 0;
}