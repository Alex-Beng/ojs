#include <cstring>
#include <queue>
#include <iostream>
using namespace std;
struct node {
    node (int rows_=0, int col_=0, int layer_=0) {
        row = rows_;
        col = col_;
        layer = layer_;
    } 
    int row;
    int col;
    int layer;
};
char map[233][33][33];
int step[233][33][33];
int layers, rows, cols;

bool operator== (node a, node b) {
    if (a.col != b.col || a.row != b.row || a.layer != b.layer) {
        return false;
    }
    else {
        return true;
    }
}

node move_to(node t_now, int flag) {
    node t_next = t_now;
    switch(flag) {
        case 0: // -1, 0, 0
        if (t_next.row-1 >= 0 && map[t_next.layer][t_next.row-1][t_next.col] != '#') {
            t_next.row -= 1;
            return t_next;
        }
        break;

        case 1: // 1, 0, 0
        if (t_next.row+1 < rows && map[t_next.layer][t_next.row+1][t_next.col] != '#') {
            t_next.row += 1;
            return t_next;
        }
        break;

        case 2: // 0, -1, 0
        if (t_next.col-1 >= 0 && map[t_next.layer][t_next.row][t_next.col-1] != '#') {
            t_next.col -= 1;
            return t_next;
        }
        break;

        case 3: // 0, 1, 0
        if (t_next.col+1 < cols && map[t_next.layer][t_next.row][t_next.col+1] != '#') {
            t_next.col += 1;
            return t_next;
        }
        break;

        case 4: // 0, 0, -1
        if (t_next.layer-1 >= 0 && map[t_next.layer-1][t_next.row][t_next.col] != '#') {
            t_next.layer -= 1;
            return t_next;
        }
        break;

        case 5: // 0, 0, 1 
        if (t_next.layer+1 < layers && map[t_next.layer+1][t_next.row][t_next.col] != '#') {
            t_next.layer += 1;
            return t_next;
        }
        break;
    }
    t_next.row = -1;
    return t_next;
}

int bfs(node begin, node end) {
    memset(step, 0, sizeof(step));
    std::queue<node> qrq;
    qrq.push(begin);
    step[begin.layer][begin.row][begin.col] = 1;
    while (!qrq.empty()) {
        node t_now = qrq.front();   
        qrq.pop();
        for (int i=0; i<6; i++) {
            node t_next = move_to(t_now, i);
            if (t_next.row == -1) {
                continue;
            }
            // cout<<t_next.layer<<t_next.row<<t_next.col<<endl;
            if (step[t_next.layer][t_next.row][t_next.col] == 0) { // first time been
                if (t_next == end) {
                    return step[t_now.layer][t_now.row][t_now.col];
                }
                step[t_next.layer][t_next.row][t_next.col] = step[t_now.layer][t_now.row][t_now.col] + 1;
                qrq.push(t_next);
            }
            else { // 
                ;
            }
        }
    }
    return -1;
}

int main(int argc, char const *argv[]) {
    while (cin>>layers>>rows>>cols && (layers||rows||cols)) {
        node begin, end;

        for (int t_layer=0; t_layer<layers; t_layer++) {
            for (int t_rows=0; t_rows<rows; t_rows++) {
                for (int t_cols=0; t_cols<cols; t_cols++) {
                    cin>>map[t_layer][t_rows][t_cols];
                    if (map[t_layer][t_rows][t_cols] == 'S') {
                        begin = node(t_rows, t_cols, t_layer);
                    }
                    if (map[t_layer][t_rows][t_cols] == 'E') {
                        end = node(t_rows, t_cols, t_layer);
                    }
                }
            }
        }
        // cout<<bfs(begin, end)<<endl;
        int t =bfs(begin, end);
        if (t == -1) {
            cout<<"Trapped!"<<endl;
        }
        else {
            cout<<"Escaped in "<<t<<" minute(s)."<<endl;
        }
    }
    return 0;
}