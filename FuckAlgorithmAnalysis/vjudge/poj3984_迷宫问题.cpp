#include <stack>
#include <queue>
#include <iostream>
using namespace std;

int direction[4][2] = {{0,1}, {0,-1}, {-1,0}, {1,0}};
int mist[23][33]; // 0 for road, 1 for wall
stack<int> roads;
stack<int> ans_roads;
int ans = 0;
int t_sum_step;

void input_data () {
    for (int i=0; i<5; i++) {
        for (int j=0; j<5; j++) {
            cin>>mist[i][j];
        }
    }
}

bool go_able(int row, int col) {
    if (mist[row][col] == 1) {
        return false;
    }
    if (row < 0 || row > 4 || col < 0 || col > 4) {
        return false;
    }
    return true;
}

void dfs(int row, int col, int flag) {
    cout<<row<<' '<<col<<' '<<flag<<endl;
    if (row == 4 && col == 4) {
        if (t_sum_step < ans) {
            ans = t_sum_step;
            ans_roads = roads;
        }
    }
    else {
        for (int i=0; i<4; i++) {
            int t_row = row + direction[i][0];
            int t_col = col + direction[i][1];
            
            // cout<<t_row<<t_col<<endl;
            if (go_able(t_row, t_col)) {
                // cout<<'w'<<t_row<<t_col<<endl;
                t_sum_step++;
                roads.push(t_row*5 + t_col);
                dfs(t_row, t_col, i);
                roads.pop();
                t_sum_step--;
            }
        }
    }
}

int main(int argc, char const *argv[]) {
    input_data();

    ans_roads.push(0);
    dfs(0, 0, -1);
    for (size_t i=0; i<ans_roads.size(); i++) {
        cout<<ans_roads.top();
        ans_roads.pop();
    }
    return 0;
}
