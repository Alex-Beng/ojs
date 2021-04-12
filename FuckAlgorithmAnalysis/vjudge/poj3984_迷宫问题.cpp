#include <cstdio>

#include <map>
#include <iostream>
using namespace std;

int maze[5][5];

int diffs[4][2] = {
                    {0, 1},
                    {0, -1},
                    {1, 0},
                    {-1, 0}
                  };

struct status {
    int row;
    int col;
    int prev;
    int op;
    status() {
        row = col = prev = op = -1;
    }    
    bool operator<(const status& that) const {
        int this_key = row*10 + col;
        int that_key = that.row*10 + that.col;
        return this_key < that_key;
    }
    void operator=(const status& that) {
        row = that.row;
        col = that.col;
        prev = that.prev;
        op = that.op;
    }
};

void out_res(status* st_qrq, int idx) {
    if (idx == -1) {
        // printf("(%d, %d)\n", st_qrq[idx].row, st_qrq[idx].col);
        ;
    }
    else {
        out_res(st_qrq, st_qrq[idx].prev);
        printf("(%d, %d)\n", st_qrq[idx].row, st_qrq[idx].col);
    }
}

void bfs() {
    status st_qrq[233];
    int qrq_head_idx = 0;
    int qrq_tail_idx = 0;

    std::map<status, int> been;

    status t_s;
    t_s.row = 0;
    t_s.col = 0;
    st_qrq[qrq_tail_idx++] = t_s;
    been[t_s] = 1;

    int t_idx = -1;
    while (qrq_head_idx != qrq_tail_idx) {
        t_s = st_qrq[qrq_head_idx];
        t_idx = qrq_head_idx;
        qrq_head_idx++;

        if (t_s.row == 4 && t_s.col == 4) {
            // out res
            // cout<<t_idx<<endl;
            out_res(st_qrq, t_idx);
        }

        // 上下左右
        for (int i=0; i<4; i++) {
            int dr = diffs[i][0];
            int dc = diffs[i][1];

            t_s.row += dr;
            t_s.col += dc;

            if (t_s.row < 0 || t_s.row > 4 
             || t_s.col < 0 || t_s.col > 4) continue;
            if (been[t_s]) continue;//!
            if (maze[t_s.row][t_s.col]) continue; //!

            t_s.prev = t_idx;
            t_s.op = i;
            st_qrq[qrq_tail_idx++] = t_s;
            been[t_s] = 1;//!

            t_s.row -= dr;
            t_s.col -= dc;
        }
    }
    
}

int main(int argc, char const *argv[]) {
    for (int i=0; i<5; i++) {
        for (int j=0; j<5; j++) {
            cin>>maze[i][j];
        }
    }
    bfs();
    return 0;
}