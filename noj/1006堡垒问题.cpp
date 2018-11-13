#include <iostream>
using namespace std;

char map[23][33]; // X for wall . for space b for block 

int n;
int ans;
int t_sum_block;

bool in_side(int row, int col) {
    if (row<0 || row>=n || col<0 || col>=n) {
        return false;
    }
    return true;
}

bool valid(int row ,int col) {

    if (map[row][col] == 'X') {
        return false;
    }
    
    for (int i=row-1; i>=0; i--) {
        if (map[i][col] == 'b') {
            return false;
        }
        if (map[i][col] == 'X') {
            break;
        }
    }

    for (int i=col-1; i>=0; i--) {
        if (map[row][i] == 'b') {
            return false;
        }
        if (map[row][i] == 'X') {
            break;
        }
    } 
    return true;
}


#if 0
void dfs(int layer) {
    if (layer == n) {
        if (t_sum_block > ans) {
            ans = t_sum_block;
        }
    }
    else {
        for (int i=0; i< n; i++) {
            if (valid(layer, i)) {
                dfs(layer+1);
                
                map[layer][i] = 'b';
                t_sum_block ++;

                dfs(layer+1);
                
                map[layer][i] = '.';
                t_sum_block --;
            } 
        }
    }
}
#endif
void dfs(int layer) {
    int row = layer/n;
    int col = layer%n;

    if (layer == n*n) {
        if (t_sum_block > ans) {
            ans = t_sum_block;
        }
    }
    else {
        dfs(layer+1);
        if (valid(row, col)) {
            
            map[row][col] = 'b';
            t_sum_block++;
            
            dfs(layer+1);

            map[row][col] = '.';
            t_sum_block--;
        }
    }
}


int main(int argc, char const *argv[]) {
    while (cin>>n && n) {
        ans = 0;
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                cin>>map[i][j];
            }
        }
        dfs(0);
        cout<<ans<<endl;
    }
    return 0;
}
