#include <queue>
#include <iostream>
using namespace std;

char map[23][33];  // 'X' for wall, '.' for space.
int step[23][33];

int begin_row, begin_col;
int end_row, end_col;

bool is_valid(int row, int col) {
    if (row<0 || row>11 || col<0 || col>11 || map[row][col] == 'X') {
        return false;
    }
    return true;
}

int move_to(int t_now, int flag) {
    int t_row = t_now/12;
    int t_col = t_now%12;
    switch(flag) {
        
        case 0: // up
        t_row--;
        if (!is_valid(t_row,t_col)) {
            return -1;
        }
        break;

        case 1: // down
        t_row++;
        if (!is_valid(t_row,t_col)) {
            return -1;
        }
        break;

        case 2: // left
        t_col--;
        if (!is_valid(t_row,t_col)) {
            return -1;
        }
        break;

        case 3: // right
        t_col++;
        if (!is_valid(t_row,t_col)) {
            return -1;
        }
        break;
    }
    return 12*t_row+t_col;
}

int bfs() {
    queue<int> qrq;
    qrq.push(begin_row*12+begin_col);

    while (!qrq.empty()) {
        int t_node = qrq.front();
        int t_next;
        qrq.pop();
        for (int i=0; i<4; i++) {
            t_next = move_to(t_node, i);
            // cout<<t_next/12<<' '<<t_next%12<<endl;
            if (t_next == -1) {
                continue;
            }
            else {
                // cout<<t_next/12<<' '<<t_next%12<<endl;

                if (t_next/12 == end_row && t_next%12 == end_col) {
                    return step[t_node/12][t_node%12]+1;
                }
                if (step[t_next/12][t_next%12] == 0) {
                    // cout<<t_next/12<<' '<<t_next%12<<endl;
                    qrq.push(t_next);
                    step[t_next/12][t_next%12] = step[t_node/12][t_node%12]+1;
                }
                else {
                    step[t_next/12][t_next%12] = step[t_node/12][t_node%12]+1;
                }
            }
        }
    }
}

int main(int argc, char const *argv[]) {
    cin>>begin_row>>begin_col>>end_row>>end_col;
    begin_row--; begin_col--;
    end_row--; end_col--;
    for (int i=0; i<12; i++) {
        for (int j=0; j<12; j++) {
            cin>>map[i][j];
        }
    }
    
    cout<<bfs()<<endl;
    // cout<<is_valid(2,8)<<endl;
    // cout<<is_valid(2,9)<<endl;
    return 0;
}
