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


int R, C;
char MAZE[2333][3333];
// int FIRE_STEP[2333][3333];
std::unordered_map<coor, int, pair_hash> FIRE_STEP; // (R, C) -> step


int DIFF[4][2] = {
    {0, 1},
    {0, -1},
    {1, 0},
    {-1, 0}
};

void out_fire_step() {
    cout<<"-----------fire step--------------"<<endl;
    for (int i=0; i<R; i++) {
        for (int j=0; j<C; j++) {
            cout<<FIRE_STEP[make_pair(i, j)]<<' ';//!
        }
        cout<<endl;
    }
    cout<<endl;
}

void out_joe_step(std::unordered_map<coor, int, pair_hash> joes_step) {
    cout<<"-----------joes step--------------"<<endl;
    for (int i=0; i<R; i++) {
        for (int j=0; j<C; j++) {
            cout<<joes_step[make_pair(i, j)]<<' ';//!
        }
        cout<<endl;
    }
    cout<<endl;
}

// bfs fire one step
int bfs_fire(std::queue<coor> &fire_qrq) {
    coor t_co, t_n_co;
    int curr_qrq_size = fire_qrq.size();
    int cnt = 0;

    // cout<<"fire start"<<endl;
    while (!fire_qrq.empty()) {
        t_co = fire_qrq.front();
        fire_qrq.pop();
        cnt++;
        for (int i=0; i<4; i++) {
            t_n_co.first = t_co.first + DIFF[i][0];
            t_n_co.second = t_co.second + DIFF[i][1];
            
            // printf("%d %d fire why %d %d \n", t_n_co.first, t_n_co.second, (MAZE[t_n_co.first][t_n_co.second] == '.' 
            //    || MAZE[t_n_co.first][t_n_co.second] == 'J'), FIRE_STEP[t_n_co] == 0);
            if (t_n_co.first>=0 && t_n_co.first<R
            && t_n_co.second>=0 && t_n_co.second<C
            && (MAZE[t_n_co.first][t_n_co.second] == '.' 
               || MAZE[t_n_co.first][t_n_co.second] == 'J')
            // && FIRE_STEP[t_n_co] == 0) {//!
            && FIRE_STEP.find(t_n_co) == FIRE_STEP.end()) {//!
                fire_qrq.push(t_n_co);
                FIRE_STEP[t_n_co] = FIRE_STEP[t_co] + 1;
            }
        }
        if (cnt == curr_qrq_size) { // 只bfs一层
            // cout<<"fire end"<<endl;
            return -2;
        }
    }
    return -1;
}

// joe one step
int bfs_joe(std::queue<coor> &joes_qrq, std::unordered_map<coor, int, pair_hash> &joes_step) {
    coor t_co, t_n_co;
    // t_co = joes_qrq.front();
    int curr_qrq_size = joes_qrq.size();
    int cnt = 0;

    // joes_step[t_co] = 1;
    while(!joes_qrq.empty()) {
        t_co = joes_qrq.front();
        joes_qrq.pop();
        cnt++;

        if (t_co.first==0 || t_co.first==R-1
        || t_co.second==0 || t_co.second==C-1) {
            // out_joe_step(joes_step);
            return joes_step[t_co];
        }

        for (int i=0; i<4; i++) {
            t_n_co.first = t_co.first + DIFF[i][0];
            t_n_co.second = t_co.second + DIFF[i][1];
            
            // printf("in %d %d v: %d\n", t_n_co.first, t_n_co.second, FIRE_STEP[t_n_co]);
            // if (FIRE_STEP[t_n_co] != 0) {
            if (FIRE_STEP.find(t_n_co) != FIRE_STEP.end()) {
                // printf("worry in %d %d\n", t_n_co.first, t_n_co.second);
                continue;
            }
            // printf("why %d %d %d %d %d\n", t_n_co.first>=0 && t_n_co.first<R, t_n_co.second>=0 && t_n_co.second<C, MAZE[t_n_co.first][t_n_co.second] == '.', joes_step[t_n_co] == 0, !FIRE_STEP[t_n_co]);
            if (t_n_co.first>=0 && t_n_co.first<R
            && t_n_co.second>=0 && t_n_co.second<C
            &&
             (MAZE[t_n_co.first][t_n_co.second] == '.')
            && joes_step[t_n_co] == 0
            // && !FIRE_STEP[t_n_co] ) {
            && FIRE_STEP.find(t_n_co) == FIRE_STEP.end() ) {
                // cout<<"push: "<<t_n_co.first<<","<<t_n_co.second<<endl;
                joes_qrq.push(t_n_co);
                joes_step[t_n_co] = joes_step[t_co] + 1;
            }
        }
        if (cnt == curr_qrq_size) {
            return -2;
        }
    }
    // out_joe_step(joes_step);
    return -1;
}


int main(int argc, char const *argv[]) {
    int n;
    // cin>>n;
    scanf("%d", &n);
    std::unordered_map<coor, int, pair_hash> joes_step;
    for (int ii=0; ii<n; ii++) {
        FIRE_STEP.clear();
        joes_step.clear();

        cin>>R>>C;

        std::queue<coor> fires;
        std::queue<coor> joes;// may not need 's' lol
        for (int i=0; i<R; i++) {
            for (int j=0; j<C; j++) {
                cin>>MAZE[i][j];//!
                if (MAZE[i][j] == 'F') {
                    FIRE_STEP[make_pair(i, j)] = 1;
                    fires.push(make_pair(i, j));
                }
                if (MAZE[i][j] == 'J') {
                    joes_step[make_pair(i, j)] = 1;
                    joes.push(make_pair(i, j));
                }
            }
        }

        while (true) {
            // out_fire_step();
            bfs_fire(fires);
            // out_fire_step();
            // out_joe_step(joes_step);
            int ans = bfs_joe(joes, joes_step);
            // out_joe_step(joes_step);
            if (ans == -1) {
                cout<<"IMPOSSIBLE"<<endl;
                break;    
            }
            else if (ans == -2) {
                continue;
            }
            else {
                cout<<ans<<endl;
                break;
            }
        }
        
    }
    return 0;
}