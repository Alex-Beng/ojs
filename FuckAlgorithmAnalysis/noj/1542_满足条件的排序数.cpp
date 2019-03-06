#include <iostream>
using namespace std;
int m, n;
bool used[23] = {false};
int t_positions[23];
int ans = 0;

void dfs(int layer) {
    // cout<<"num:"<<t_positions[layer-1]<<endl;
    if (layer == n) {
        ans++;
    }
    else {
        
        for (int i=1; i<=n; i++) {
            if (!used[i]) {
                if (t_positions[layer-1] + i >= m) { // the 0th all is 1, so write so.
                    // cout<<t_positions[layer-1]<<' '<<i<<endl;
                    used[i] = true;
                    t_positions[layer] = i;
                    dfs(layer+1);
                    used[i] = false;
                }
            }
        }
    }
}

int main(int argc, char const *argv[]) {
    cin>>m>>n;
    t_positions[0] = 1;
    used[1] = true;
    dfs(1);
    cout<<ans<<endl;
    return 0;
}
