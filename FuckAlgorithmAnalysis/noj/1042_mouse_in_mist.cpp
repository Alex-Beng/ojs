/**
 * AC!!!!!!!!
*/
/*
sample:

2 9 11 8
XXXXXXXXXXXX
X......X.XXX
X.X.XX.....X
X.X.XX.XXX.X
X.X.....X..X
X.XXXXXXXXXX
X...X.X....X
X.XXX...XXXX
X.....X....X
XXX.XXXX.X.X
XXXXXXX..XXX
XXXXXXXXXXXX
*/
#include <queue>
#include <iostream>
using namespace std;

struct coordinate {
    int x;
    int y;
    bool been_2;
    int step;
    char road;
};

coordinate map[23][33];
coordinate vec[4];

inline bool judge_site_legal(coordinate site) { //不越界，不撞墙，而且是第一次走
    if (site.x<1||site.y<1||site.x>12||site.y>12) {
        return false;
    }
    if (map[site.x][site.y].road == 'X') {
        return false;
    }
    if (map[site.x][site.y].been_2 == true) {
        return false;
    }
    return true;
}

int main(int argc, char const *argv[]) {
    vec[0].x =  0;vec[0].y = -1; //上
    vec[1].x = -1;vec[1].y =  0; //左
    vec[2].x =  0;vec[2].y =  1; //下
    vec[3].x =  1;vec[3].y =  0; //右

    coordinate begin;
    coordinate end;
    cin>>begin.x>>begin.y>>end.x>>end.y;
    for (int i=1; i<=12; i++) {   //x
        for (int j=1; j<=12; j++) {  //y
            cin>>map[i][j].road;
            map[i][j].been_2 = false;
            map[i][j].step = 0;
        }
    }

    std::queue<coordinate> qrq;
    qrq.push(begin);
    map[begin.x][begin.y].been_2 = true;
    
    while (!qrq.empty()) {
        coordinate t_site = qrq.front();
        coordinate t_next;
        qrq.pop();
        for (int i=0; i<4; i++) { //四个方向 
            t_next.x = t_site.x + vec[i].x;
            t_next.y = t_site.y + vec[i].y;
            if (t_next.x == end.x && t_next.y == end.y) {
                cout<<map[t_site.x][t_site.y].step+1<<endl;
                return 0;
            }
            if (judge_site_legal(t_next)) {
                map[t_next.x][t_next.y].been_2 = true;
                map[t_next.x][t_next.y].step = map[t_site.x][t_site.y].step+1;
                qrq.push(t_next); 
            }
        }
    }
    return 0;
}
