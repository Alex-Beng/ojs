// XXXXXXXXXXXX
// X......X.XXX
// X.X.XX.....X
// X.X.XX.XXX.X
// X.X.....X..X
// X.XXXXXXXXXX
// X...X.X....X
// X.XXX...XXXX
// X.....X....X
// XXX.XXXX.X.X
// XXXXXXX..XXX
// XXXXXXXXXXXX
#include <queue>
#include <iostream>
using namespace std;
class coordinate {
public:
coordinate() {
    x = -1;
    y = -1;
}
public:
    int x;
    int y;
};
int step_to_coordinate[20][20] = {0}; 
int map[20][20]; // 0 for road, 1 for building
std::queue<coordinate> qrq;
coordinate move_to(coordinate t, int flag) {
    coordinate return_value;
    return_value.x = t.x;
    return_value.y = t.y;
    switch(flag) {
        case 0: //上
            return_value.y -= 1;
            break;
        case 1: //左
            return_value.x -= 1;
            break;
        case 2: //下
            return_value.y += 1;
            break;
        case 3: //右
            return_value.x += 1;
            break;
    }
    return return_value;
}
int main(int argc, char const *argv[])
{
    coordinate begin;
    coordinate end;
    cin>>begin.x>>begin.y>>end.x>>end.y;
    for (int i=0;i<12;i++) {
        for (int j=0; j<12; j++) {
            coordinate t_site;
            char t_char;
            t_site.x = j;
            t_site.y = i;
            cin>>t_char;
            if (t_char == 'X') {
                map[t_site.x][t_site.y] = 1;
            }
            else {
                map[t_site.x][t_site.y] = 0;
            }
        }
    }
    // for (int i=0;i<12;i++) {
    //     for (int j=0; j<12; j++) {
    //         coordinate t_site;
    //         t_site.x = j;
    //         t_site.y = i;
    //         cout<<map[t_site.x][t_site.y];
    //     }
    //     cout<<endl;
    // }
    qrq.push(begin);
    step_to_coordinate[begin.x][begin.y] = 0;
    while (!qrq.empty()) {
        coordinate t_site = qrq.front();
        cout<<'x'<<t_site.x<<' '<<t_site.y<<endl;
        qrq.pop();
        for (int i=0; i<4; i++) {
            coordinate t_next = move_to(t_site,i);
            if (map[t_next.x][t_next.y] == 1) {
                continue;
            }
            if (t_next.x == end.x && t_next.y == end.y) {
                cout<<step_to_coordinate[t_site.x][t_site.y] + 1;
                return 0;
            }
            if (t_next.x<12&&t_next.x>=0&&t_next.y>=0&&t_next.y<12 && step_to_coordinate[t_next.x][t_next.y] == 0 ) {
                step_to_coordinate[t_next.x][t_next.y] = step_to_coordinate[t_site.x][t_site.y] + 1;
                qrq.push(t_next);
            }
        }
    }

    return 0;
}
