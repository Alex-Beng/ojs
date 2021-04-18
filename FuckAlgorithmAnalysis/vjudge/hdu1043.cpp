#include <cstring>

#include <algorithm>
#include <unordered_map>
#include <queue>
#include <utility>
#include <string>
#include <iostream>
using namespace std;

// std::unordered_map<std::string, int> step;
std::unordered_map<std::string, std::string> ops;

int op_diff[4][2] = {
    {-1, 0},
    {0, -1},
    {0, 1},
    {1, 0}
};
// char op2char[4] {'u', 'l', 'r', 'd'};
char op2char[4] = {'d', 'r', 'l', 'u'};//! reverse！

inline void str2status(std::string t, char st[3][3], int& zr, int&zc) {
    for (int r=0; r<3; r++) {
        for (int c=0; c<3; c++) {
            st[r][c] = t[r*3+c];
            if (st[r][c] == 'x') {
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

void out_st(char st[3][3]) {
    for (int r=0; r<3; r++) {
        for (int c=0; c<3; c++) {
            cout<<st[r][c]<<' ';
        }
        cout<<endl;
    }
}

void bfs() {
    std::queue<std::string> qrq;
    qrq.push("12345678x");
    // step["12345678x"] = 1;
    ops["12345678x"] = "0";

    std::string t_status_str;
    char t_status[3][3];
    int t_zr, t_zc;
    
    std::string t_nstatus_str;
    int t_nzr, t_nzc;
    while(!qrq.empty()) {
        t_status_str = qrq.front();
        qrq.pop();
        str2status(t_status_str, t_status, t_zr, t_zc);

        for (int i=0; i<4; i++) {
            t_nzr = t_zr + op_diff[i][0];
            t_nzc = t_zc + op_diff[i][1];
            
            if (t_nzr>=0 && t_nzr<3
            && t_nzc>=0 && t_nzc<3) {
                swap(t_status[t_zr][t_zc], t_status[t_nzr][t_nzc]);
                status2str(t_status, t_nstatus_str);
                
                // std::reverse(tttt.begin(), tttt.end());
                // cout<<tttt<<' '<<step[t_status_int]+1<<endl;
                // out_st(t_status);
                if (ops[t_nstatus_str] == "") {
                    // step[t_nstatus_str] = step[t_status_str] + 1;
                    ops[t_nstatus_str] = ops[t_status_str] + op2char[i];
                    // out_st(t_status);
                    // cout<<step[t_nstatus_str]<<' '<<ops[t_nstatus_str]<<endl<<endl;
                    qrq.push(t_nstatus_str);
                }
                swap(t_status[t_zr][t_zc], t_status[t_nzr][t_nzc]);
            }
        }
    }
}

int main(int argc, char const *argv[]) {
    bfs();

    char t_str[10];
    std::string t_sstr;
    t_str[9] = '\0';
    while(cin>>t_str[0]>>t_str[1]>>t_str[2]
             >>t_str[3]>>t_str[4]>>t_str[5]
             >>t_str[6]>>t_str[7]>>t_str[8]) {
        t_sstr = std::string(t_str);
        // std::reverse(t_str.begin(), t_str.end());
        if (ops.count(t_sstr)) {
            std::string t_ans = ops[t_sstr];
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