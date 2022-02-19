#include "stdc++.h"
using namespace std;

class DancingLinks {
public:
    int n, m, cnt;
    int *L, *R, *U, *D, *row, *col;
    int *S, *H, *ans;
    // only for suduko, 100 is enough :)
    DancingLinks(int maxrow=1000, int maxcol=1000);

    void init(int r, int c);
    void add_node(int r, int c);
    void remove(int col);
    void resume(int col);
    bool dancing(int depth);
};

DancingLinks::DancingLinks(int maxrow, int maxcol) {
    int maxnode = maxrow * maxcol;
    // node的上下左右指针
    this->L = new int[maxnode];
    this->R = new int[maxnode];
    this->U = new int[maxnode];
    this->D = new int[maxnode];
    // node -> row/col
    this->row = new int[maxnode];
    this->col = new int[maxnode];
    // col[i] 的node数量
    this->S = new int[maxcol];
    // row[j] 的node数量
    this->H = new int[maxrow];
    // 结果数组
    this->ans = new int[maxrow];
}

void DancingLinks::init(int r, int c) {
    n = r;
    m = c;
    for (int i=0; i<=m; i++) {// col[0] is useless
        S[i] = 0;
        U[i] = D[i] = i;   // 前col个节点作为对应col的头节点
        L[i] = i-1;
        R[i] = i+1;
    }
    L[0] = m;
    R[m] = 0;
    this->cnt = m;  // !!!

    for (int i=1; i<=n; i++) {
        H[i] = -1;
    }
    
}

void DancingLinks::add_node(int r, int c) {
    S[c] += 1;

    this->cnt += 1;
    row[cnt] = r;
    col[cnt] = c;

    // add to col links
    D[cnt] = D[c];
    U[cnt] = c;
    U[D[cnt]] = cnt;
    D[U[cnt]] = cnt;
    // add to row links
    if (H[r] < 0) {
        H[r] = cnt;
        R[cnt] = L[cnt] = cnt;
    }
    else {
        R[cnt] = R[H[r]];
        L[cnt] = H[r];
        R[L[cnt]] = cnt;
        L[R[cnt]] = cnt;
    }
}

void DancingLinks::remove(int c) {
    // 头节点
    L[R[c]] = L[c];
    R[L[c]] = R[c];

    for (int i=D[c]; i!=c; i=D[i]) {
        for (int j=R[i]; j!=i; j=R[j]) {
            U[D[j]] = U[j];
            D[U[j]] = D[j];
            S[this->col[j]] -= 1;
        }
    }
}

void DancingLinks::resume(int c) {
    // 注意得完全反过来
    for (int i=U[c]; i!=c; i=U[i]) {
        for (int j=L[i]; j!=i; j=L[j]) {
            U[D[j]] = j;
            D[U[j]] = j;
            S[this->col[j]] += 1;
        }
    }
    L[R[c]] = c;
    R[L[c]] = c;
}

bool DancingLinks::dancing(int depth) {
    // head->R == head
    if (R[0]==0) {
        return true;
    }
    // 获得S最小的col
    int c = R[0];
    for (int i=R[0]; i!=0; i=R[i]) {
        if (S[i] < S[c]) {
            c = i;
        }

    }
    remove(c);

    for (int i=D[c]; i!=c; i=D[i]) {
        this->ans[depth] = row[i];
        for (int j=R[i]; j!=i; j=R[j]) {
            remove(col[j]);
        }
        if (dancing(depth+1)) {
            return true;
        }
        for (int j=L[i]; j!=i; j=L[j]) {
            resume(col[j]);
        }
    }
    resume(c);
    return false;
}

const int N = 9;

void place(int& row, int& c1, int& c2, int& c3, int&c4, int i, int j, int k) {
    row = (i*N+j)*N + k;
    c1 = i*N + j + 1;
    c2 = N*N*1 + i*N + k;
    c3 = N*N*2 + j*N + k;
    c4 = N*N*3 + ((i/3)*3+(j/3))*N + k;
}


class Solution {
public:

    void solveSudoku(vector<vector<char>>& board) {
        // for (int i=0; i<9; i++) {
        //     for (int j=0; j<9; j++) {
        //         cout<<board[i][j]<<' ';
        //     }
        //     cout<<endl;
        // }
        DancingLinks dlx;
        dlx.init(9*9*9, 9*9*4);
        int r, c1, c2, c3, c4;
        for (int i=0; i<9; i++) {
            for (int j=0; j<9; j++) {
                for (int k=1; k<=9; k++) {
                    if (board[i][j]=='.' || board[i][j]=='0'+k) {
                        // r = (i*9+j)*9 + k;
                        // c1 = 9*9 + j + 1;
                        // c2 = 9*9*1 + i*9 + k;
                        // c3 = 9*9*2 + j*9 + k;
                        // c4 = 9*9*3 + ((i/3)*3+(j/3))*9 + k;
                        place(r, c1, c2, c3, c4, i, j, k);

                        dlx.add_node(r, c1);
                        dlx.add_node(r, c2);
                        dlx.add_node(r, c3);
                        dlx.add_node(r, c4);
                    }
                }
            }
        }
        dlx.dancing(0);
        for (int i=0; i<81; i++) {
            int idx = (dlx.ans[i]-1)/9;

            board[idx/9][idx%9] = (dlx.ans[i]-1)%9 + '1';
        }
    }
};
