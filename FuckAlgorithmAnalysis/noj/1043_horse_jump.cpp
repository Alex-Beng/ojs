/*
sample

2
1 1 2 1
1 5 5 1
*/
#include <queue>
#include <iostream> 
using namespace std;
struct coordinate {
    coordinate() {
        been_to = false;
        step = 0;
    }
    int x;
    int y;
    bool been_to;
    int step;
};


int main(int argc, char const *argv[]) {
    coordinate vec[8];
    vec[0].x =  1; vec[0].y = -2;
    vec[1].x =  2; vec[1].y = -1;
    vec[2].x =  1; vec[2].y =  2;
    vec[3].x =  2; vec[3].y =  1;
    vec[4].x = -1; vec[4].y = -2;
    vec[5].x = -2; vec[5].y = -1;
    vec[6].x = -1; vec[6].y =  2;
    vec[7].x = -2; vec[7].y =  1;

    int N;
    int sample_num;
    cin>>sample_num;
    for (int j=0; j<sample_num; j++) {
        coordinate begin;
        coordinate end;
        coordinate board[233][333];
        cin>>begin.x>>begin.y>>end.x>>end.y;

        std::queue<coordinate> qrq;
        qrq.push(begin);
        while (!qrq.empty()) {
            coordinate t_site = qrq.front();
            qrq.pop();
            for (int i=0; i<8; i++) {
                coordinate t_next;
                t_next.x = t_site.x + vec[i].x;
                t_next.y = t_site.y + vec[i].y;
                // cout<<t_next.x<<' '<<t_next.y<<endl;
                if (t_next.x == end.x && t_next.y == end.y) {
                    cout<<board[t_site.x][t_site.y].step+1<<endl;
                    while (!qrq.empty()) {
                        qrq.pop();
                    }
                    break;
                }
                if (t_next.x<1||t_next.y<1||t_next.x>200||t_next.y>200
                    ||board[t_next.x][t_next.y].been_to ) {
                    continue;
                }
                else {
                    // cout<<t_next.x<<' '<<t_next.y<<endl;
                    board[t_next.x][t_next.y].been_to = true;
                    board[t_next.x][t_next.y].step = board[t_site.x][t_site.y].step+1;
                    qrq.push(t_next);
                }
            } 
        }
    }
    
    return 0;
}
