#include <iostream>
using namespace std;

int max_sum_value;
int t_sum_value;
int remain_value=0;
int capacity_value;
int n;
int value[50];
void dfs(int layer) {
    if (layer == n) {
        if (t_sum_value > max_sum_value) {
            max_sum_value = t_sum_value;
        }
    }
    else {
        remain_value -= value[layer];
        if (t_sum_value + value[layer] <= capacity_value) {
            t_sum_value += value[layer];
            dfs(layer+1);
            t_sum_value -= value[layer];
        }
        // dfs(layer+1);
        if (t_sum_value+remain_value > max_sum_value) {
            dfs(layer+1);
        }
        remain_value += value[layer]; 
    }
}

int main(int argc, char const *argv[])
{
    cin>>n>>capacity_value;
    for (int i=0; i<n; i++) {
        cin>>value[i];
        remain_value += value[i];
    }
    dfs(0);
    cout<<max_sum_value<<endl;
    return 0;
}
