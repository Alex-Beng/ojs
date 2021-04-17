#include <cstring>

#include <map>
#include <queue>
#include <utility>
#include <iostream>
using namespace std;
typedef std::pair<int, int> coor;

int m, n;
std::map<coor, char> maze;
std::map<coor, int> flag;// int key默认为零

int diff[8][2] = {
    {-1, -1},
    {-1, 0},
    {-1, 1},
    {0, -1},
    {0, 1},
    {1, -1},
    {1, 0},
    {1, 1}
};

void out_flag() {
    for (int r=0; r<m; r++) {
        for (int c=0; c<n; c++) {
            cout<<flag[make_pair(r, c)]<<' ';
        }
        cout<<endl;
    }

}

void bfs(coor b_pnt, int fff) {
    std::queue<coor> qrq;
    qrq.push(b_pnt);
    flag[b_pnt] = fff;
    
    coor t_co, t_n_co;
    while(!qrq.empty()) {
        t_co = qrq.front();
        qrq.pop();

        for (int i=0; i<8; i++) {
            t_n_co.first = t_co.first + diff[i][0];
            t_n_co.second = t_co.second + diff[i][1];
            if (t_n_co.first>=0 && t_n_co.first<m
            && t_n_co.second>=0 && t_n_co.second<n
            && maze[t_n_co]=='@'//!
            && flag[t_n_co]==0) {
                flag[t_n_co] = fff;
                qrq.push(t_n_co);
            }
        }
    }
}

int main(int argc, char const *argv[]) {
    while(1) {
        cin>>m>>n;
        if (!m) break;

        flag.clear();
        coor t_co;
        for (int r=0; r<m; r++) {
            for (int c=0; c<n; c++) {
                cin>>maze[make_pair(r, c)];
            }
        }

        int ans = 1;
        for (int r=0; r<m; r++) {
            for (int c=0; c<n; c++) {
                t_co = make_pair(r, c);
                if (maze[t_co]=='@' && flag[t_co]==0) {
                    bfs(t_co, ans);
                    ans++;
                }
                // out_flag();
            }
        }
        cout<<ans-1<<endl;
    }
    return 0;
}