#include <iostream>
using namespace std;

const int INF = 127; // 注意char的比较

char mmp[1001][1001] = {0};
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
        cin>>node_1>>node_2;
        mmp[node_1][node_2] = 1;
        mmp[node_2][node_1] = 1;
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

    for (int i=1; i<=n; i++) {
        int ans = 0;
        for (int j=1; j<=n; j++) {
            if (mmp[i][j] <= 6) {
                ans++;
            }
        }
        printf("%d: %.2lf%\n", i, ans*100.0/n);
    }
    return 0;
}