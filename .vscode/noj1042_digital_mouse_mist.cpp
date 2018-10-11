#include <map>
#include <queue>
#include <iostream>
using namespace std;
class coordinate{
public:
    coordinate(){
        x = -1;
        y = -1;
    }
public:
    int x;
    int y;
public:
    bool operator<(const coordinate& t) const {
        return (y*12-12+x)<(t.y*12-12+x);
    }
};
std::map<coordinate,int> step_to_coordinate; // <coordinate, steps>
std::map<coordinate,int> map_; // map, 0 for road, 1 for building
std::queue<coordinate> qrq;
coordinate move_to(coordinate t, int flag) {
    coordinate return_value;
    return_value.x = t.x;
    return_value.y = t.y;
    switch(flag) {
        case 0: //上
            return_value.y -= 1;
            if ( return_value.y >=0
                 && map_[return_value] == 0 ) { //能走
                return return_value;
            }
            else {
                return coordinate();
            }
        case 1: //左
            return_value.x -= 1;
            if ( return_value.x >=0 
                 && map_[return_value] == 0 ) {
                return return_value;
            }
            else {
                return coordinate();
            }
        case 2: //下
            return_value.y += 1;
            if ( return_value.y <= 11
                 && map_[return_value] == 0 ) {
                return return_value;
            }
            else {
                return coordinate();
            }
        case 3: //右
            return_value.x += 1;
            if ( return_value.x <= 11 
                 && map_[return_value] == 0 ) {
                return return_value;
            }
            else {
                return coordinate();
            }
    }
}

int main() {
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
                // cout<<1;
                map_[t_site] = 1;
                cout<<map_[t_site];
            }
            else {
                // cout<<0;
                map_[t_site] = 0;
                cout<<map_[t_site];
            }
        }
        cout<<endl;
    }
    cout<<endl;
    for (int i=0;i<12;i++) {
        for (int j=0; j<12; j++) {
            coordinate t_site;
            t_site.x = j;
            t_site.y = i;
            cout<<map_[t_site];
            // if (map_[t_site] == 1) {
            //     cout<<'X';
            // }
            // else {
            //     cout<<'.';
            // }
        }
        cout<<endl;
    }
    qrq.push(begin);
    step_to_coordinate[begin] = 0;
    while (!qrq.empty()) {
        coordinate t_site = qrq.front();
        qrq.pop();
        for (int i=0; i<4; i++) {//向四个方向搜索
            coordinate t_next = move_to(t_site,i);
            if (t_next.x == -1 || t_next.y == -1) {//走不了...

                continue;
            }
            else {
                if (t_next.x == end.x && t_next.y == end.y) { //到终点了..
                    step_to_coordinate[t_next] = step_to_coordinate[t_site] + 1;
                    cout<<step_to_coordinate[end]<<endl;
                    return 0;
                }
                
            }

        }
    }
    return 0;
}