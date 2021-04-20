#include <cstdlib>
#include <cstdio>

#include <queue>
#include <string>
#include <map>
#include <iostream>
using namespace std;

int op_diff[4][2] = {
    {1, 0},
    {0, -1},
    {0, 1},
    {-1, 0}
};
// char op2char[4] {'u', 'l', 'r', 'd'};
char op2char[4] {'d', 'l', 'r', 'u'};//!

int char2idx[256];
struct status {
    std::string st_str;
    int g;
    int h;
    bool operator<(const status& a) const {
        if (h!=a.h) {
            return h > a.h;
        }
        else {
            return g > a.g;
        }
    }
};

inline int get_hn(std::string& st_str, std::string& goal_str) {
    for (int i=0; i<9; i++) {
        char2idx[st_str[i]] = i;
    }
    int res = 0;
    int ir, ic;
    int j, jr, jc;
    for (int i=0; i<9; i++) {
        ir = i/3;
        ic = i%3;
        j = char2idx[goal_str[i]];
        jr = j/3;
        jc = j%3;
        res += abs(ir-jr) + abs(ic-jc);
    }
    return res;
}

inline void str2status(std::string t, char st[3][3], int& zr, int&zc) {
    for (int r=0; r<3; r++) {
        for (int c=0; c<3; c++) {
            st[r][c] = t[r*3+c];
            if (st[r][c] == 'x') {//!
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

    std::map<std::string, std::string> ops;
    // std::queue<std::string> qrq;
    std::priority_queue<status> qrq;

    status t_st, t_nst;

    ops[curr_state] = "0";
    t_st.st_str = curr_state;
    t_st.g = 0;
    t_st.h = get_hn(curr_state, goal_state);
    qrq.push(t_st);

    char t_st_mat[3][3];

    int t_zr, t_zc, t_nzr, t_nzc;
    while (!qrq.empty()) {
        t_st = qrq.top();
        // cout<<t_st.st_str<<endl;
        qrq.pop();
        if (t_st.st_str == goal_state) {
            return ops[t_st.st_str].substr(1);
        }

        str2status(t_st.st_str, t_st_mat, t_zr, t_zc);
        for (int i=0; i<4; i++) {
            t_nzr = t_zr + op_diff[i][0];
            t_nzc = t_zc + op_diff[i][1];

            if (t_nzr>=0 && t_nzr<3
            && t_nzc>=0 && t_nzc<3) {
                std::swap(t_st_mat[t_zr][t_zc], t_st_mat[t_nzr][t_nzc]);
                status2str(t_st_mat, t_nst.st_str);
                // cout<<"new"<<t_nst.st_str<<endl;
                if (ops[t_nst.st_str] == "") {
                    t_nst.g = t_st.g + 1;
                    t_nst.h = get_hn(t_nst.st_str, goal_state);
                    ops[t_nst.st_str] = ops[t_st.st_str] + op2char[i];
                    qrq.push(t_nst);
                }
                std::swap(t_st_mat[t_zr][t_zc], t_st_mat[t_nzr][t_nzc]);
            }
        }
    }
}

int main(int argc, char const *argv[]) {
    std::string g_st, res;
    char c_st[10];
    c_st[9] = '\0';
    g_st = "12345678x";
    while(cin>>c_st[0]>>c_st[1]>>c_st[2]
             >>c_st[3]>>c_st[4]>>c_st[5]
             >>c_st[6]>>c_st[7]>>c_st[8]){
        
        // cin>>g_st;

        res = bfs(std::string(c_st), g_st);
        // printf("Case %d: %d\n", i+1, res.size());
        cout<<res<<endl;
    }
    return 0;
}