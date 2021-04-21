// WA!!!

#include <cstring>

#include <queue>
#include <vector>
#include <iostream>
using namespace std;

const int FRAC[] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};	
const int op_diff[4][2] = {
    {-1, 0},
    {0, -1},
    {0, 1},
    {1, 0},
};
const char op2char[4] {'d', 'r', 'l', 'u'};
// const char op2char[4] {'u', 'l', 'r', 'd'};//!


// sum(frac) = 409114, 即排列数；故康托展开后的数组大小只需>409114即可
bool been[9][466666];// 233333 x 2
int pre[9][466666];
char ops[9][466666];

struct status {
    int mat[3][3];
    int zr, zc;
    status() {};
    status(std::string str) {
        assign(str);
    }
    void assign(std::string str) {
        for (int r=0; r<3; r++) {
            for (int c=0; c<3; c++) {
                if (str[r*3+c] == 'X') {
                    zr = r;
                    zc = c;
                    mat[r][c] = 0;
                }
                else {
                    mat[r][c] = str[r*3+c] - '0';
                }
            }
        }
    }
    void assign(int cnt, int val) {
        mat[cnt/3][cnt%3] = val;
    }
    void print() {
        for (int r=0; r<3; r++) {
            for (int c=0; c<3; c++) {
                cout<<mat[r][c]<<' ';
            }
            cout<<endl;
        }
    }
};

int cantor(status st) {
	int ans = 0;
    for (int i=0; i<9; i++) {
        int smaller = 0;
        for (int j=i+1; j<9; j++) {
            if (st.mat[j/3][j%3] < st.mat[i/3][i%3])
                smaller++;
        }
        ans += smaller*FRAC[9-(i+1)];
    }
    return ans;
}

// 这题不太需要逆康托，但还是写一发
void decantor(int hash, status& res) {
    int cnt = 0;
    std::vector<int> ref = {0, 1, 2, 3, 4, 5, 6, 7, 8};
    for (int i=8; i>=0; i--) {
        int t = hash/FRAC[i];
        hash %= FRAC[i];
        res.assign(cnt, ref[t]);
        cnt++;
        ref.erase(ref.begin()+t);
    }
}

// 搜索X在z_idx时候的表
void bfs(int z_idx, std::string init_st) {
    memset(been[z_idx], 0, sizeof(been[z_idx]));
    memset(pre[z_idx], -1, sizeof(pre[z_idx]));

    std::queue<status> qrq;
    status t_st, t_nst;
    int t_hash, t_nhash;
    int t_nzr, t_nzc;
    t_st.assign(init_st);

    qrq.push(t_st);
    t_hash= cantor(t_st);//!
    been[z_idx][t_hash] = 1;
    while(!qrq.empty()) {
        t_st = qrq.front();
        qrq.pop();//!
        // t_st.print();cout<<endl;
        t_hash = cantor(t_st);

        for (int i=0; i<4; i++) {
            t_nst = t_st;
            t_nst.zr += op_diff[i][0];
            t_nst.zc += op_diff[i][1];
            if (t_nst.zr<0 || t_nst.zr>2
            || t_nst.zc<0 || t_nst.zc>2) continue;

            std::swap(t_nst.mat[t_nst.zr][t_nst.zc], t_nst.mat[t_st.zr][t_st.zc]);
            t_nhash = cantor(t_nst);
            if (been[z_idx][t_nhash]) continue;

            been[z_idx][t_nhash] = 1;
            pre[z_idx][t_nhash] = t_hash;
            ops[z_idx][t_nhash] = op2char[i];
            qrq.push(t_nst);

            std::swap(t_nst.mat[t_nst.zr][t_nst.zc], t_nst.mat[t_st.zr][t_st.zc]);
        }
    }
}


int main(int argc, char const *argv[]) {
    bfs(0, "X12345678");
    bfs(1, "1X2345678");
    bfs(2, "12X345678");
    bfs(3, "123X45678");
    bfs(4, "1234X5678");
    bfs(5, "12345X678");
    bfs(6, "123456X78");
    bfs(7, "1234567X8");
    bfs(8, "12345678X");

    std::string b_st_s, e_st_s;
    status b_st, e_st;
    int b_hash;
    int maping[9];// num -> num 映射
    int n;
    cin>>n;
    for (int ii=0; ii<n; ii++) {
        cin>>b_st_s;
        cin>>e_st_s;

        b_st.assign(b_st_s);
        e_st.assign(e_st_s);

        int z_idx = e_st.zr*3 + e_st.zc;

        int j=0;
        for (int i=0; i<9; i++) {
            if (e_st.mat[i/3][i%3] != 0) {
                maping[ e_st.mat[i/3][i%3] ] = ++j;
            }
        }
        maping[0] = 0;//! 0->0
        // for (int r=0; r<3; r++) {
        //     for (int c=0; c<3; c++) {
        //         cout<<r*3+c<<maping[r*3+c]<<' ';
        //     }
        //     cout<<endl;
        // }
        for (int i=0; i<9; i++) {
            b_st.mat[i/3][i%3] = maping[b_st.mat[i/3][i%3]];
        }
        // b_st.print();

        b_hash = cantor(b_st);
        std::vector<char> ans;
        while (b_hash != -1) {
            ans.push_back(ops[z_idx][b_hash]);
            b_hash = pre[z_idx][b_hash];
        }
        ans.pop_back();

        printf("Case %d: %d\n", ii+1, ans.size());
        for (int i=0; i<ans.size(); i++) {
            cout<<ans[i];
        }
        cout<<endl;
    }

    return 0;
}