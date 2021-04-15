#include <cstdio>
#include <cstring>

#include <map>
#include <queue>
#include <vector>
#include <utility>
#include <iostream>
using namespace std;

typedef std::pair<int, int> coor;

int n, m;
char mapp[23][33];
int diff[4][2] = {
    {0, 1},
    {0, -1},
    {1, 0},
    {-1, 0}
};

int bfs(coor p1, coor p2, std::vector<coor>& grasses) {
    int been[23][33];
    memset(been, 0, sizeof(been));

    std::queue<coor> qrq;
    qrq.push(p1);
    qrq.push(p2);
    been[p1.first][p1.second] = 1;
    been[p2.first][p2.second] = 1;

    coor t_co, t_co_forward;
    while (!qrq.empty()) {
        t_co = qrq.front();
        qrq.pop();

        for (int i=0; i<4; i++) {
            t_co_forward.first = t_co.first + diff[i][0];
            t_co_forward.second = t_co.second + diff[i][1];//!
            if (t_co_forward.first>=0&&t_co_forward.first<n 
            && t_co_forward.second>=0&&t_co_forward.second<m
            && mapp[t_co_forward.first][t_co_forward.second] == '#'
            && !been[t_co_forward.first][t_co_forward.second]) {
                been[t_co_forward.first][t_co_forward.second] = been[t_co.first][t_co.second] + 1;//!
                qrq.push(t_co_forward);
            }
        }
    }
    int cnt = 0;
    for (int i=0; i<grasses.size(); i++) {
        t_co = grasses[i];

        if (been[t_co.first][t_co.second] == 0) {// 有未烧到的草地
            return -1;
        }
        else {
            
            cnt = max(cnt, been[t_co.first][t_co.second]);
        }
    }
    return cnt-1;
}

int main(int argc, char const *argv[]) {
    int T;
    cin>>T;
    for (int ii=0; ii<T; ii++) {
        std::vector<coor> grasses;

        cin>>n>>m;
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                cin>>mapp[i][j];
                if (mapp[i][j] == '#') {
                    grasses.push_back(make_pair(i, j));
                }
            }
        }

        // for all p1 (x1, y1) and p2 (x2, y2)
        int ans = 2147483647;
        int t_ans;
        for (int i=0; i<grasses.size(); i++) {
            for (int j=0; j<grasses.size(); j++) {
                coor p1 = grasses[i];
                coor p2 = grasses[j];
                t_ans = bfs(p1, p2, grasses);
                if (t_ans != -1) {
                    ans = min(ans, t_ans);
                }
            }
        }
        if (ans == 2147483647) {
            ans = -1;
        }

        printf("Case %d: %d\n", ii+1, ans);
    }
    return 0;
}