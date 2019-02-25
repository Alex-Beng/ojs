/*
AC!
sample
5
0 0 0
1 1 1
1 4 1
3 4 1
4 3 0
3 3
3 1
5 5
*/
#include <queue>
#include <iostream>
using namespace std;

#define DOWN_WALL (2)
#define RIGHT_WALL (3)
#define WALL_FREE (0)

#define HAPPENED (1)
#define UN_HAPPENED (0)

struct node {
    node (int m_row = 0, int m_col = 0, int p_row = 0, int p_col = 0) {
        mummies_row = m_row;
        mummies_col = m_col;
        person_row  = p_row;
        person_col  = p_col;
    }
    int mummies_col;
    int mummies_row;
    int person_col;
    int person_row;
};

int map[23][33] = {WALL_FREE};
int status[23][33][33][33] = {UN_HAPPENED};
int vec[4][2] = {{1,0},{-1,0},{0,1},{0,-1}}; // down, up, right, left

node move_to(node t_status, int i) {
    t_status.person_row += vec[i][0];
    t_status.person_col += vec[i][1];
    return t_status;
}

int main(int argc, char const *argv[]) {
    // cout<<status[0][0][0][0]<<endl;
    node begin;
    node end;
    
    int t_wall_num;
    int t_row,t_col;
    cin>>t_wall_num;
    for (int i=0; i<t_wall_num; i++) {
        cin>>t_row>>t_col;
        cin>>map[t_row][t_col];
        if (map[t_row][t_col] == 0) {
            map[t_row][t_col] = DOWN_WALL;
        }
        else {
            map[t_row][t_col] = RIGHT_WALL;
        }
    }
    cin>>begin.mummies_row>>begin.mummies_col;
    cin>>begin.person_row>>begin.person_col;
    cin>>end.person_row>>end.person_col;

    // for (int i=0; i<6; i++) {
    //     for (int j=0; j<6; j++) {
    //         cout<<map[i][j];
    //     }
    //     cout<<endl;
    // }
    // return 0;

    std::queue<node> qrq;
    qrq.push(begin);
    while (!qrq.empty()) {
        node t_status = qrq.front();
        node t_next;
        qrq.pop();
        for (int i=0; i<4; i++) {
            t_next = move_to(t_status,i);
            // cout<<'\n'<<t_next.person_row<<' '<<t_next.person_col<<endl<<t_next.mummies_row<<' '<<t_next.mummies_col<<endl;
            // 首先判断人的位置是否越界, 如果人没有越界, 那么僵尸跟着也不可能越界
            // 越界就pass, 搜索下一个节点
            if (t_next.person_col < 0 || t_next.person_row < 0 ||
            t_next.person_col > 5 || t_next.person_col > 5) {
                continue;
            }

            // cout<<"out_boad:"<<t_next.person_row<<' '<<t_next.person_col<<endl<<t_next.mummies_row<<' '<<t_next.mummies_col<<endl;

            // 没有越界, 若当前状态出现过, pass, next node
            if (status[t_next.person_row][t_next.person_col][t_next.mummies_row][t_next.mummies_col] == HAPPENED) {
                continue;
            }

            // cout<<"wall error:"<<t_next.person_row<<' '<<t_next.person_col<<endl<<t_next.mummies_row<<' '<<t_next.mummies_col<<endl;

            // 以上情况都没有发生, 但是撞墙了, pass, next node
            if (i == 0) { // go down
                // cout<<0<<endl;
                if (map[t_status.person_row][t_status.person_col] == DOWN_WALL) {
                    continue;
                } 
            }
            else if (i == 1) { // go up
            // cout<<1<<endl;
                if (map[t_next.person_row][t_next.person_col] == DOWN_WALL) {
                    continue;
                }
            }
            else if (i == 2) { // go right
            // cout<<2<<endl;
                if (map[t_status.person_row][t_status.person_col] == RIGHT_WALL) {
                    continue;
                }
            }
            else if (i == 3){ // go left
            // cout<<3<<endl;
                if (map[t_next.person_row][t_next.person_col] == RIGHT_WALL) {
                    continue;
                }
            }

            // cout<<"legal:"<<t_next.person_row<<' '<<t_next.person_col<<endl<<t_next.mummies_row<<' '<<t_next.mummies_col<<endl;
            
            // 到达终点
            if (t_next.person_col == end.person_col &&  
            t_next.person_row == end.person_row) {
                cout<<"Yes"<<endl;
                return 0;
            }
            // 没有, 就要模拟僵尸走路...
            int t_m_step = 2;
            // cout<<"while: "<<t_next.mummies_col<<' '<<t_next.person_col<<endl;
            while (t_next.mummies_col != t_next.person_col && t_m_step > 0) {
                // cout<<"here"<<endl;
                if (t_next.mummies_col > t_next.person_col && // 僵尸需要向左走
                map[t_next.mummies_row][t_next.mummies_col-1] != RIGHT_WALL) { // 而且能向左走
                    t_next.mummies_col--;
                }
                if (t_next.mummies_col < t_next.person_col && // 僵尸需要向右走
                map[t_next.mummies_row][t_next.mummies_col] != RIGHT_WALL) { // 而且能向左走
                    t_next.mummies_col++;
                }
                t_m_step--;
            }
            // cout<<"2while: "<<t_next.mummies_col<<' '<<t_next.person_col<<endl;
            // cout<<"2whlie: begin"<<t_next.mummies_row<<' '<<t_next.person_row<<endl;
            while (t_next.mummies_row != t_next.person_row && t_m_step > 0) { // 如果row方向不一样, 而且僵尸还能走
                // cout<<"herr"<<endl;
                if (t_next.mummies_row < t_next.person_row &&   // need down
                map[t_next.mummies_row][t_next.mummies_col] != DOWN_WALL) { // and can down
                    t_next.mummies_row++;
                }
                if (t_next.mummies_row > t_next.person_row &&   // need up
                map[t_next.mummies_row-1][t_next.mummies_col] != DOWN_WALL) { // and can up
                    t_next.mummies_row--;
                }
                t_m_step--;
            }

            // if gg.
            if (t_next.mummies_row == t_next.person_row && t_next.mummies_col == t_next.person_col) {
                continue;
            }
            else {
                status[t_next.person_row][t_next.person_col][t_next.mummies_row][t_next.mummies_col] == HAPPENED;
                qrq.push(t_next);
            }
        }
    }
    cout<<"No"<<endl;
    return 0;
}





// abandon version
// #include <iostream>
// using namespace std;

// struct node { // 节点
//     int person_cols;
//     int person_rows;
//     int mummies_cols;
//     int mummies_rows;
//     node(int person_col = 0, int person_row = 0, int mummies_row = 0, int mummies_col = 0)
//         : person_cols(person_col), person_rows(person_row), mummies_cols(mummies_row), mummies_rows(mummies_col){};
// };
// int map[2][33]; // 0 for road, 1 for down-side wall, 2 for right-side wall
// int step[23][33][33][33]; // 判重用... pcol, prow; mcol, mrow;
// int vec[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}}; // 人走的四个方向 下 上 右 左

// bool can_move_to(int rows, int cols, int flag) {
//     int t_next_rows = rows + vec[flag][0];
//     int t_next_cols = cols + vec[flag][1];
//     // 不能走， 要么是越界，要么撞墙
//     if (t_next_cols<0 || t_next_cols>5 || t_next_rows<0 || t_next_rows>5) {
//         return false;
//     }
//     else {
//         if (flag == 0 || map[rows][cols] == 1) { // 下
//             return false;
//         }
//         if (flag == 2 || map[rows][cols] == 2) { // 右
//             return false;
//         }
//     }
//     return true;
// }

// node for_mummies_move(node t_now) {
//     if (t_now.mummies_cols == t_now.person_cols) {
        
//     }
//     else if (t_now.mummies_cols < t_now.person_cols){

//     }
//     else {

//     }
// }

// node move_to(node t_now, int flag) {
//     switch (flag) {

//     }
// }

// int main(int argc, char const *argv[]) {
//     int mummies_begin_rows, mummies_begin_cols;
//     int mummies_end_rows, mummies_end_cols;
//     int person_begin_rows, person_begin_cols;

//     return 0;
// }
