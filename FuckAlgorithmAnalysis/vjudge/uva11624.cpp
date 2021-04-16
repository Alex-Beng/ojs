// TLE！！！！

/*
2
4 4
####
#JF#
#..#
#..#
3 3
###
#J.
#.F

*/

#include <cstring>

#include <unordered_map>
#include <queue>
#include <utility>
#include <iostream>
using namespace std;

typedef std::pair<int, int> coor;

struct pair_hash {
    template <class T1, class T2>
    std::size_t operator () (const std::pair<T1,T2> &p) const {
        return p.first*1000 + p.second;
    }
};


int r, c;
char maze[2333][3333];
// int fire_step[2333][3333];
std::unordered_map<coor, int, pair_hash> fire_step;


int diff[4][2] = {
    {0, 1},
    {0, -1},
    {1, 0},
    {-1, 0}
};

void out_fire_step() {
    for (int i=0; i<r; i++) {
        for (int j=0; j<c; j++) {
            cout<<fire_step[make_pair(i, j)]<<' ';//!
        }
        cout<<endl;
    }
}

void out_joe_step(std::unordered_map<coor, int, pair_hash> joes_step) {
    for (int i=0; i<r; i++) {
        for (int j=0; j<c; j++) {
            cout<<joes_step[make_pair(i, j)]<<' ';//!
        }
        cout<<endl;
    }

}

// 先bfs fire，获得fire step
void bfs_fire(std::queue<coor> fire_qrq) {
    coor t_co, t_n_co;
    while (!fire_qrq.empty()) {
        t_co = fire_qrq.front();
        fire_qrq.pop();
        for (int i=0; i<4; i++) {
            t_n_co.first = t_co.first + diff[i][0];
            t_n_co.second = t_co.second + diff[i][1];

            if (t_n_co.first>=0 && t_n_co.first<r
            && t_n_co.second>=0 && t_n_co.second<c
            && (maze[t_n_co.first][t_n_co.second] == '.' 
               || maze[t_n_co.first][t_n_co.second] == 'J')
            && fire_step[t_n_co] == 0) {//!
                fire_qrq.push(t_n_co);
                fire_step[t_n_co] = fire_step[t_co] + 1;
            }
        }
    }
    
}

int bfs_joe(std::queue<coor> joes_qrq) {
    std::unordered_map<coor, int, pair_hash> joes_step;

    coor t_co, t_n_co;
    t_co = joes_qrq.front();
    joes_step[t_co] = 1;
    while(!joes_qrq.empty()) {
        t_co = joes_qrq.front();
        joes_qrq.pop();

        if (t_co.first==0 || t_co.first==r-1
        || t_co.second==0 || t_co.second==c-1) {
            // out_joe_step(joes_step);
            return joes_step[t_co];
        }

        for (int i=0; i<4; i++) {
            t_n_co.first = t_co.first + diff[i][0];
            t_n_co.second = t_co.second + diff[i][1];

            if (t_n_co.first>=0 && t_n_co.first<r
            && t_n_co.second>=0 && t_n_co.second<c
            && (maze[t_n_co.first][t_n_co.second] == '.' 
               || maze[t_n_co.first][t_n_co.second] == 'F')
            && joes_step[t_n_co] == 0
            && joes_step[t_co]+1 < fire_step[t_n_co]) {
                joes_qrq.push(t_n_co);
                joes_step[t_n_co] = joes_step[t_co] + 1;
            }
        }
    }
    // out_joe_step(joes_step);
    return -1;
}

int main(int argc, char const *argv[]) {
    int n;
    cin>>n;
    for (int ii=0; ii<n; ii++) {
        fire_step.clear();

        cin>>r>>c;

        std::queue<coor> fires;
        std::queue<coor> joes;// may not need 's' lol
        for (int i=0; i<r; i++) {
            for (int j=0; j<c; j++) {
                cin>>maze[i][j];//!
                if (maze[i][j] == 'F') {
                    fire_step[make_pair(i, j)] = 1;
                    fires.push(make_pair(i, j));
                }
                if (maze[i][j] == 'J') {
                    joes.push(make_pair(i, j));
                }
            }
        }

        // out_fire_step();

        bfs_fire(fires);

        // out_fire_step();
        int ans = bfs_joe(joes);

        if (ans == -1) {
            cout<<"IMPOSSIBLE"<<endl;
        }
        else {
            cout<<ans<<endl;
        }
    }
    return 0;
}