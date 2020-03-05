// 原本向djistra，发现Floyd也能a
// 太艹了
#include <iostream>
using namespace std;

const int INF = 0x3f3f3f3f; 

int mmp[233][233] = {0};

int n, e;

int main(int argc, char const *argv[]) {
    cin>>n>>e;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            if (i == j) {
                continue;
            }
            mmp[i][j] = INF;
        }
    }

    for (int i=0; i<e; i++) {
        int node_1, node_2;
        int distance;
        cin>>node_1>>node_2>>distance;
        mmp[node_1][node_2] = distance;
        mmp[node_2][node_1] = distance;
    }
    
    // do floyd
    for (int mid=1; mid<=n; mid++) {
        for (int from=1; from<=n; from++) {
            for (int to=1; to<=n; to++) {
                mmp[from][to] = mmp[from][to] < mmp[from][mid]+mmp[mid][to]?
                    mmp[from][to] : mmp[from][mid]+mmp[mid][to];
            }
        }
    }


    // do compare
    int min_dis = INF;
    int ans_animal = 0;
    for (int i=1; i<=n; i++) {
        // found longest distance
        int t_longest = -1;
        for (int j=1; j<=n; j++) {
            if (mmp[j][i] > t_longest) {
                t_longest = mmp[j][i];
            }
        }
        if (t_longest < min_dis) {
            min_dis = t_longest;
            ans_animal = i;
        }
    }
    if (ans_animal)
        cout<<ans_animal<<' '<<min_dis<<endl;
    else 
        cout<<0<<endl;
    return 0;
}