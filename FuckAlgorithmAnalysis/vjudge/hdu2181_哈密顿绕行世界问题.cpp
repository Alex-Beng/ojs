#include <cstring>
#include <cstdio>

#include <iostream>
using namespace std;

int aj_mat[23][3];
int viz[23];
int path[23];
int m;
int cnt;

void out_path() {
    printf("%d:  ", ++cnt);//!
    cout<<m<<' ';
    for (int i=1; i<=19; i++) {
        cout<<path[i]<<' ';//!
    }
    cout<<m<<endl;//!
}

void dfs(int curr_city, int curr_layer) {
    
    if (curr_layer == 20) {
        for (int i=0; i<3; i++) {
            if (aj_mat[curr_city][i] == m) {
                out_path();
            }
        }
        return;
    }

    for (int i=0; i<3; i++) {
        int to_city = aj_mat[curr_city][i];
        if (viz[to_city]) continue;

        viz[to_city] = 1;
        path[curr_layer] = to_city;
        dfs(to_city, curr_layer+1);
        viz[to_city] = 0;
    }
}

int main(int argc, char const *argv[]) {
    for (int i=1; i<=20; i++) {
        for (int j=0; j<3; j++) {
            cin>>aj_mat[i][j];
        }
    }
    while (1) {
        cin>>m;
        if (m==0) break;

        memset(viz, 0, sizeof(viz));
        viz[m] = 1;//!
        cnt = 0;
        dfs(m, 1);
        
    }
    

    return 0;
}