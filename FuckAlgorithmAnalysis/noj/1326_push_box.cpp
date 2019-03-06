#include <iostream>
#include <queue>

using namespace std;
int status_ever[23][33][33][33]; // 代表当前状态
int vec[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}}; // 下, 上, 左, 右
struct node {
    int person_cols;
    int person_rows;
    int box_cols;
    int box_rows;
    node(int person_col = 0, int person_row = 0, int box_col = 0, int box_row = 0)
        : person_cols(person_col), person_rows(person_row), box_cols(box_col), box_rows(box_row){};
};

node move_to(node t_now, int flag) {
    return node(t_now.person_cols+vec[flag][0],t_now.person_rows+vec[flag][1],t_now.box_cols,t_now.box_rows);
}

bool in_board(int rows, int cols) {
    if (rows<1 || cols<1 || rows>10 || cols>10) {
        return false;
    }
    return true;
}

int main(int argc, char const *argv[]) {
    int box_begin_rows, box_begin_cols;
    int box_end_rows, box_end_cols;
    int person_begin_rows, person_begin_cols;
    char map[23][33];

    for (int i=1; i<=10; i++) {         // row
        for (int j=1; j<=10; j++) {
            cin>>map[i][j];
            if (map[i][j] == '2') {
                box_begin_rows = i;
                box_begin_cols = j;
                map[i][j] = '0';
            }
            else if (map[i][j] == '3') {
                box_end_rows = i;
                box_end_cols = j;
                map[i][j] = '0';
            }
            else if (map[i][j] == '4') {
                person_begin_rows = i;
                person_begin_cols = j;
                map[i][j] = '0';
            }
        }
    }

    // for (int i=1; i<=10; i++) {         // row
    //     for (int j=1; j<=10; j++) {
    //         cout<<map[i][j];
    //     }
    //     cout<<endl;
    // }

    std::queue<node> qrq;
    qrq.push(node(person_begin_cols,person_begin_rows,box_begin_cols,box_begin_rows));
    while (!qrq.empty()) {
        node t_next;
        node t_node = qrq.front();
        qrq.pop();
        for (int i=0; i<4; i++) {
            t_next = move_to(t_node,i);

            if (t_next.person_cols == t_next.box_cols   
            && t_next.person_rows == t_next.box_rows) {     //如果推到了箱子
                t_next.box_cols += vec[i][0];
                t_next.box_rows += vec[i][1];
                if (in_board(t_next.box_rows,t_next.box_cols)
                && status_ever[t_next.person_cols][t_next.person_rows][t_next.box_cols][t_next.box_rows] == 0
                && map[t_next.box_rows][t_next.box_cols] == '0') {
                    status_ever[t_next.person_cols][t_next.person_rows][t_next.box_cols][t_next.box_rows] = status_ever[t_node.person_cols][t_node.person_rows][t_node.box_cols][t_node.box_rows] + 1;
                    qrq.push(t_next);
                }
            }
            else {                                          //如果没推到箱子
                if (in_board(t_next.person_rows,t_next.person_cols) 
                && status_ever[t_next.person_cols][t_next.person_rows][t_next.box_cols][t_next.box_rows] == 0
                && map[t_next.person_rows][t_next.person_cols] == '0' ) {   
                    status_ever[t_next.person_cols][t_next.person_rows][t_next.box_cols][t_next.box_rows] = status_ever[t_node.person_cols][t_node.person_rows][t_node.box_cols][t_node.box_rows] + 1;
                    qrq.push(t_next);
                }   
            }
            if (t_next.box_cols == box_end_cols && t_next.box_rows == box_end_rows) {
                cout<<status_ever[t_next.person_cols][t_next.person_rows][t_next.box_cols][t_next.box_rows]<<endl;
                return 0;
            }
        }
    }
    cout<<-1<<endl;
    return 0;
}

// #include <queue>
// #include <iostream>
// using namespace std;
// int vec[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
// int status_ever[23][33][33][33]; // person_col, *_row; box_col, *_row;
// struct coordinate {
//     int col_;
//     int row_;
//     char road_; // '0' for road, '1' for wall
// };

// struct node {
//     coordinate person_site_;
//     coordinate box_site_;
// };

// node move_to(node status, int flag) {   // flag for four directions.
//     node t_next;
//     t_next.person_site_.row_ = status.person_site_.row_ + vec[flag][0];
//     t_next.person_site_.col_ = status.person_site_.col_ + vec[flag][1];
//     t_next.box_site_.col_    = status.box_site_.col_;
//     t_next.box_site_.row_    = status.box_site_.row_;
//     return t_next;
// }

// bool in_board(coordinate site) {
//     if (site.col_<1 || site.row_<1 || site.col_>10 || site.row_>10) {
//         return false;
//     }
//     return true;
// }

// int main(int argc, char const *argv[]) {
//     coordinate person_begin;
//     coordinate box_begin;
//     coordinate box_end;
//     coordinate map[23][33];

//     for (int i=1; i<=10; i++) {
//         for (int j=1; j<=10; j++) {
//             cin>>map[i][j].road_;
//             if (map[i][j].road_ == '2') { // box begin
//                 box_begin.row_ = i;
//                 box_begin.col_ = j;
//             }
//             if (map[i][j].road_ == '3') { // box end
//                 box_end.row_ = i;
//                 box_end.col_ = j;
//             }
//             if (map[i][j].road_ == '2') { // person begin
//                 person_begin.row_ = i;
//                 person_begin.col_ = j;
//             }
//         }
//     }
//     // box_begin.col_ = 10;
//     node begin_node;
//     begin_node.person_site_ = person_begin;
//     begin_node.box_site_ = box_begin;
//     std::queue<node> qrq;
//     qrq.push(begin_node);
//     // cout<<begin_node.box_site_.col_<<endl;
//     while (!qrq.empty()) {
//         node t_next;
//         node t_status = qrq.front();
//         qrq.pop();
//         for (int i=0; i<4; i++) {
//             t_next = move_to(t_status,i);
//             cout<<t_next.person_site_.row_<<' '<<t_next.person_site_.col_<<endl;
//             if (t_next.person_site_.col_ == t_next.box_site_.col_
//             && t_next.person_site_.row_ == t_next.box_site_.row_) {
//                 coordinate t_box_next;
//                 t_box_next.row_ = t_next.person_site_.row_ + vec[i][0];
//                 t_box_next.col_ = t_next.person_site_.col_ + vec[i][1];
//                 if (in_board(t_box_next)
//                 && status_ever[t_next.person_site_.col_][t_next.person_site_.row_][t_box_next.col_][t_box_next.row_] == 0
//                 && map[t_box_next.row_][t_box_next.col_].road_ == '0') {
//                     t_next.box_site_ = t_box_next;
//                     qrq.push(t_next);
//                     status_ever[t_next.person_site_.col_][t_next.person_site_.row_][t_next.box_site_.col_][t_next.box_site_.row_]
//                     = status_ever[t_status.person_site_.col_][t_status.person_site_.row_][t_status.box_site_.col_][t_status.box_site_.row_] + 1;
//                 }
//             }
//             else if (in_board(t_next.person_site_)
//             && status_ever[t_next.person_site_.col_][t_next.person_site_.row_][t_next.box_site_.col_][t_next.box_site_.row_] == 0) {
//                 status_ever[t_next.person_site_.col_][t_next.person_site_.row_][t_next.box_site_.col_][t_next.box_site_.row_]
//                     = status_ever[t_status.person_site_.col_][t_status.person_site_.row_][t_status.box_site_.col_][t_status.box_site_.row_] + 1;
//                 qrq.push(t_next);
//             }
//             if (t_next.box_site_.col_ == box_end.col_ && t_next.box_site_.row_ == box_end.row_) {
//                 cout<<status_ever[t_next.person_site_.col_][t_next.person_site_.row_][t_next.box_site_.col_][t_next.box_site_.row_]<<endl;
//                 return 0;
//             }
//         }
//     }
//     cout<<-1<<endl;
//     return 0;
// }
