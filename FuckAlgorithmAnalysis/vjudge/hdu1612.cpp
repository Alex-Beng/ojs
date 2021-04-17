#include <cstring>

#include <map>
#include <queue>
#include <vector>
#include <utility>
#include <iostream>
using namespace std;
typedef std::pair<int, int> coor;

int n, m;
char maze[233][333];
int y_step[233][333];
int m_step[233][333];

int diff[4][2] = {
    {-1, 0},
    {0, -1},
    {0, 1},
    {1, 0}
};

void out_step(int step[][333]) {
    for (int r=0; r<n; r++) {
        for (int c=0; c<m; c++) {
            cout<<step[r][c]<<' ';
        }
        cout<<endl;
    }
}

void y_bfs(coor b_pnt) {
    memset(y_step, 0, sizeof(y_step));
    std::queue<coor> qrq;
    qrq.push(b_pnt);
    y_step[b_pnt.first][b_pnt.second] = 1;

    coor t_co, t_n_co;
    while(!qrq.empty()) {
        t_co = qrq.front();
        qrq.pop();
        
        for (int i=0; i<4; i++) {
            t_n_co.first = t_co.first+diff[i][0];
            t_n_co.second = t_co.second+diff[i][1];
            if (t_n_co.first>=0 && t_n_co.first<n
            && t_n_co.second>=0 && t_n_co.second<m
            && maze[t_n_co.first][t_n_co.second] != '#'
            && y_step[t_n_co.first][t_n_co.second] == 0) {
                qrq.push(t_n_co);
                y_step[t_n_co.first][t_n_co.second] = y_step[t_co.first][t_co.second]+1;
            }
        }
    }
}

void m_bfs(coor b_pnt) {
    memset(m_step, 0, sizeof(m_step));
    std::queue<coor> qrq;
    qrq.push(b_pnt);
    m_step[b_pnt.first][b_pnt.second] = 1;

    coor t_co, t_n_co;
    while(!qrq.empty()) {
        t_co = qrq.front();
        qrq.pop();
        
        for (int i=0; i<4; i++) {
            t_n_co.first = t_co.first+diff[i][0];
            t_n_co.second = t_co.second+diff[i][1];
            if (t_n_co.first>=0 && t_n_co.first<n//! t_n_co.second<n
            && t_n_co.second>=0 && t_n_co.second<m
            && maze[t_n_co.first][t_n_co.second] != '#'
            && m_step[t_n_co.first][t_n_co.second] == 0) {
                qrq.push(t_n_co);
                m_step[t_n_co.first][t_n_co.second] = m_step[t_co.first][t_co.second]+1;
            }
        }
    }
}

int main(int argc, char const *argv[]) {
    while (cin>>n>>m) {
        std::vector<coor> kfcs;
        coor yb, mb;
        for (int r=0; r<n; r++) {
            for (int c=0; c<m; c++) {
                cin>>maze[r][c];
                if (maze[r][c] == '@') {
                    kfcs.push_back(make_pair(r, c));
                }
                else if (maze[r][c] == 'Y') {
                    yb = make_pair(r, c);
                }
                else if (maze[r][c] == 'M') {
                    mb = make_pair(r, c);
                }
            }
        }
        
        y_bfs(yb);
        // out_step(y_step);
        m_bfs(mb);
        // out_step(m_step);

        
        coor t_co;
        int ans = 2147483647;
        for (int i=0; i<kfcs.size(); i++) {
            t_co = kfcs[i];
            if (y_step[t_co.first][t_co.second] != 0
            && m_step[t_co.first][t_co.second] != 0) {
                if (y_step[t_co.first][t_co.second]
                + m_step[t_co.first][t_co.second] < ans) {
                    ans = y_step[t_co.first][t_co.second]
                          + m_step[t_co.first][t_co.second];
                }
            }
        }
        cout<<(ans-2)*11<<endl;
    }
    return 0;
}