#include <iostream>
using namespace std;

int weight[23];
int value[23];

int n;
int ans;
int t_sum_values;

void dfs(int layer, int capacity) {
    if (layer == n) {
        if (t_sum_values > ans) {
            ans = t_sum_values;
        }
    }
    else {
        dfs(layer+1, capacity);
        if (capacity - weight[layer] >= 0) {
            t_sum_values += value[layer];
            dfs(layer+1, capacity-weight[layer]);
            t_sum_values -= value[layer];
        }
    }
}

int main(int argc, char const *argv[]) {
    int capacity;
    while ( cin>>n>>capacity && !(n==0 && capacity==0) ) {
        ans = 0;
        for (int i=0; i<n; i++) {
            cin>>weight[i];
        }
        for (int i=0; i<n; i++) {
            cin>>value[i];
        }
        dfs(0, capacity);
        cout<<ans<<endl;
    }
    return 0;
}
